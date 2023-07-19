#include <bits/stdc++.h>
using namespace std;

using ip = pair<int, int>;

int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
vector<vector<bool>> board;
vector<ip> babyShark;

int FindBiggest()
{
    vector<vector<int>> localBoard;
    localBoard.resize(n, vector<int>(m, 0));

    for (auto bs : babyShark)
    {
        vector<vector<bool>> v(n, vector<bool>(m, false));
        queue<ip> q;
        q.push(bs);
        v[bs.first][bs.second] = true;

        while (!q.empty())
        {
            ip frt = q.front();
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int yy = frt.first + dy[k];
                int xx = frt.second + dx[k];
                if (yy < 0 || yy >= n || xx < 0 || xx >= m)
                    continue;

                if (v[yy][xx] || board[yy][xx])
                    continue;
                q.push({yy, xx});
                v[yy][xx] = true;
                if (localBoard[yy][xx] > 0)
                    localBoard[yy][xx] = min(localBoard[yy][xx], localBoard[frt.first][frt.second] + 1);
                else if (board[yy][xx] == 0)
                    localBoard[yy][xx] = localBoard[frt.first][frt.second] + 1;
            }
        }
    }
    int result = 0;
    for (auto i : localBoard)
    {
        for (auto j : i)
        {
            result = max(result, j);
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board.resize(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int token;
            cin >> token;
            board[i][j] = token;
            if (board[i][j])
                babyShark.push_back({i, j});
        }
    }

    cout << FindBiggest() << '\n';
}