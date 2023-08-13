#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
int h;
vector<vector<int>> v;
vector<vector<int>> visited;

int dy[2] = {0, 1};
int dx[2] = {1, 0};

void solve()
{
    cin >> n >> m;
    v.resize(n, vector<int>(m));
    visited.assign(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    cin >> h;

    queue<ip> q;
    visited[0][0] = v[0][0];
    q.push({0, 0});

    while (!q.empty())
    {
        ip frt = q.front();
        q.pop();

        if (frt.first == n - 1 && frt.second == m - 1)
        {
            cout << "YES" << '\n';
            cout << visited[n - 1][m - 1] << '\n';
            return;
        }

        for (int i = 0; i < 2; i++)
        {
            int yy = frt.first + dy[i];
            int xx = frt.second + dx[i];
            if (yy < 0 || yy >= n || xx < 0 || xx >= m)
                continue;

            int nxtCost = visited[frt.first][frt.second] + v[yy][xx];
            if (nxtCost <= h)
                if (nxtCost < visited[yy][xx]) // 최저 소음 거리
                {
                    visited[yy][xx] = nxtCost;
                    q.push({yy, xx});
                }
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