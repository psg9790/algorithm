#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m, t;
int py, px;
int k;

ip CalcBulletDir(ip tgt, ip cur)
{
    int maxD = INT_MAX;
    int dir = -1;

    for (int i = 0; i < 8; i++)
    {
        int yy = cur.first + dy[i];
        int xx = cur.second + dx[i];
        if (yy < 0 || yy >= n || xx < 0 || xx >= m)
            continue;
        int dist = abs(tgt.first - yy) + abs(tgt.second - xx);
        if (dist < maxD) // hueDist
        {
            maxD = dist;
            dir = i;
        }
    }
    return {cur.first + dy[dir], cur.second + dx[dir]};
}

class board
{
public:
    ip GetPlayerPos()
    {
        return playerPos;
    }
    int GetElapsed()
    {
        return elapsed;
    }

    string Serialize() // set 방문처리용 직렬화
    {
        string result;
        result += to_string(elapsed);
        result += ',';
        result += to_string(playerPos.first);
        result += ',';
        result += to_string(playerPos.second);
        result += ',';
        for (auto i : bulletsPos)
        {
            result += to_string(i.first);
            result += ',';
            result += to_string(i.second);
            result += ',';
        }
        debug(result);
        return result;
    }

    void SetPlayerPos(ip pos)
    {
        playerPos = pos; // 플레이어 위치 설정
    }

    void AddBulletPos(ip pos)
    {
        bulletsPos.insert(pos); // 총알 위치 추가
    }

    void SetElapsed(int t)
    {
        elapsed = t; // 시간 설정
    }

    bool IsGameOver()
    {
        return (bulletsPos.find(playerPos) != bulletsPos.end()); // 총알과 같은 위치
    }

    bool IsComplete()
    {
        return !IsGameOver() && (elapsed >= t);
    }

    void print()
    {
#ifndef ONLINE_JUDGE
        cout << "=======================\n";
        cout << elapsed << '\n';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == playerPos.first && j == playerPos.second)
                {
                    cout << "P ";
                    continue;
                }
                if (bulletsPos.find({i, j}) != bulletsPos.end())
                {
                    cout << "b ";
                    continue;
                }
                cout << ". ";
            }
            cout << '\n';
        }
        cout << "=======================\n";

#endif
    }

    vector<board *> Simulate()
    {
        vector<board *> result;
        for (int i = 0; i < 8; i++)
        {
            board *newBoard = new board;
            newBoard->SetElapsed(elapsed + 1);

            // player
            int yy = playerPos.first + dy[i];
            int xx = playerPos.second + dx[i];
            if (yy < 0 || yy >= n || xx < 0 || xx >= m) // out of board
                continue;
            if (bulletsPos.find({yy, xx}) != bulletsPos.end()) // bullet blocking
                continue;
            newBoard->SetPlayerPos({yy, xx});

            // bullets
            for (auto b : bulletsPos)
            {
                newBoard->AddBulletPos(CalcBulletDir({yy, xx}, b));
            }

            // gameover?
            if (newBoard->IsGameOver() == false)
            {
                result.push_back(newBoard);
            }
        }
        return result;
    }

private:
    ip playerPos;
    set<ip> bulletsPos;
    int elapsed;
};

queue<board *> q;
set<string> visited;

void solve()
{
    cin >> n >> m >> t;
    cin >> py >> px;

    board *init = new board;
    init->SetElapsed(0);
    init->SetPlayerPos({py, px});

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int by, bx;
        cin >> by >> bx;
        init->AddBulletPos({by, bx});
    }

    q.push(init);
    visited.insert(init->Serialize());
    while (!q.empty())
    {
        board *frt = q.front();
        q.pop();
        frt->print();
        debug(frt->GetElapsed(), frt->GetPlayerPos().first, frt->GetPlayerPos().second);

        vector<board *> res = frt->Simulate();
        for (auto i : res)
        {
            string str = i->Serialize();
            if (visited.find(str) != visited.end())
                continue;
            if (i->IsComplete())
            {
                cout << "YES" << '\n';
                return;
            }
            q.push(i);
            visited.insert(str);
        }
    }

    cout << "NO" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}