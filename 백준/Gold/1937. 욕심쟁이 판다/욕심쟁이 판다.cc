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

int n;
vector<vector<int>> v;

vector<vector<int>> visited; // 경로 최대값 저장용
vector<vector<int>> step;
int ans = 0;

void print()
{
#ifndef ONLINE_JUDGE
    cout << "================" << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << visited[i][j] << ' ';
        cout << '\n';
    }
    cout << "================" << '\n';

#endif
}

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (yy < 0 || yy >= n || xx < 0 || xx >= n)
            continue;
        if (v[yy][xx] <= v[y][x]) // 무조건 더 큰 수만
            continue;

        if (step[yy][xx] >= 0) // 이미 방문한 칸 처리
        {
            int amount = visited[yy][xx] - step[yy][xx]; // 경로 최대까지의 추가 칸 수
            visited[y][x] = max(visited[y][x], step[y][x] + 1 + amount);
            continue;
        }
        visited[yy][xx] = step[y][x] + 2;
        step[yy][xx] = step[y][x] + 1;
        dfs(yy, xx);
        visited[y][x] = max(visited[y][x], visited[yy][xx]);
    }
}

void solve()
{
    cin >> n;
    v.resize(n, vector<int>(n));
    visited.resize(n, vector<int>(n, -1));
    step.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (step[i][j] < 0)
            {
                step[i][j] = 0;
                visited[i][j] = 1;

                // cout << i << ' ' << j << '\n';
                dfs(i, j);
                print();

                ans = max(ans, visited[i][j]);
            }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}