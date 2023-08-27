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

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
int n, m, o, f, xs, ys, xe, ye;
vector<vector<int>> v;
vector<vector<bool>> visited;

bool bfs()
{
    queue<ip> q;
    visited[ys][xs] = true;
    q.push({ys, xs});

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            ip frt = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int yy = frt.first + dy[j];
                int xx = frt.second + dx[j];

                if (yy < 1 || yy > n || xx < 1 || xx > m)
                    continue;

                if (visited[yy][xx])
                    continue;

                int diff = v[yy][xx] - v[frt.first][frt.second];
                if (diff > f) // 점프가능
                    continue;

                if (yy == ye && xx == xe) // 도착 성공
                    return true;

                visited[yy][xx] = true;
                q.push({yy, xx});
            }
        }
        f--;        // 힘빠짐
        if (f == 0) // 힘 0
            break;
    }
    return false;
}

void solve()
{
    cin >> n >> m >> o >> f >> ys >> xs >> ye >> xe;

    v.assign(n + 1, vector<int>(m + 1, 0));
    visited.assign(n + 1, vector<bool>(m + 1, false));

    for (int i = 0; i < o; i++)
    {
        int y, x, l;
        cin >> y >> x >> l;
        v[y][x] = l;
    }

    if (bfs())
    {
        cout << "잘했어!!" << '\n';
        return;
    }
    cout << "인성 문제있어??" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}