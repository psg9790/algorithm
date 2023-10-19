#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif
int R, C;
vector<vector<int>> arr;
vector<vector<int>> visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct compare
{
    bool operator()(ip &a, ip &b)
    {
        return arr[a.first][a.second] > arr[b.first][b.second];
    }
};

int find(int x, int y)
{
    vector<vector<int>> v(R, vector<int>(C));
    v[x][y] = 1;
    priority_queue<ip, vector<ip>, compare> pq;

    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        {
            continue;
        }
        if (arr[nx][ny] >= arr[x][y])
        {
            pq.push({nx, ny});
            v[nx][ny] = 1;
        }
    }
    int cnt = 1;
    int tail = arr[x][y];
    while (!pq.empty())
    {
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (arr[x][y] < tail)
        {
            continue;
        }
        tail = arr[x][y];
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || v[nx][ny] == 1)
            {
                continue;
            }
            if (arr[nx][ny] >= tail)
            {
                pq.push({nx, ny});
                v[nx][ny] = 1;
            }
        }
    }
    return cnt;
}

void solve()
{
    cin >> R >> C;
    arr.resize(R, vector<int>(C));
    visited.resize(R, vector<int>(C, -1));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> arr[i][j];
        }
    }
    int mx = 1;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if ((R * C) - arr[i][j] + 1 < mx)
            {
                continue;
            }
            mx = max(mx, find(i, j));
        }
    }
    cout << mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}