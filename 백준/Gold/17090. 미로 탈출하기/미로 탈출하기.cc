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

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int n, m;
vector<vector<char>> v;
vector<vector<int>> vmap; // 1: O, -1: X

int convert(int y, int x)
{
    if (v[y][x] == 'U')
        return 0;
    else if (v[y][x] == 'D')
        return 1;
    else if (v[y][x] == 'L')
        return 2;
    else
        return 3;
}

int dfs(int y, int x)
{
    if (y < 0 || y >= n || x < 0 || x >= m) // 탈출 성공
        return 1;
    if (vmap[y][x] != 0) // 이미 계산된 좌표
        return vmap[y][x];

    vmap[y][x] = -1;
    int dir = convert(y, x);
    int yy = y + dy[dir];
    int xx = x + dx[dir];
    return vmap[y][x] = dfs(yy, xx); // dfs next
}

void solve()
{
    cin >> n >> m;
    v.resize(n);
    vmap.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            v[i].push_back(str[j]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vmap[i][j] == 0) // 아직 계산되지 않은 좌표
            {
                // debug(i, j);
                dfs(i, j);
                // debug(vmap);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (vmap[i][j] == 1)
                ans++;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}