#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using tt = tuple<int, int, bool>;

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int n, m, t;
vector<vector<int>> arr;
vector<vector<int>> steps;
vector<vector<int>> gramSteps;

void bfs()
{
    queue<tt> q;
    steps[0][0] = 0;
    tt nt = {0, 0, (arr[0][0] == 2)};
    q.push(nt);

    while (!q.empty())
    {
        int y, x, gram;
        tie(y, x, gram) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            bool newGram = gram;
            if (yy < 0 || yy >= n || xx < 0 || xx >= m)
                continue;

            if (gram == false)
            {
                if (arr[yy][xx] == 1)
                    continue;
                else if (arr[yy][xx] == 2)
                {
                    newGram = true;
                    gramSteps[yy][xx] = steps[y][x] + 1;
                    q.push({yy, xx, newGram});
                    continue;
                }
                if (steps[yy][xx] > steps[y][x] + 1)
                {
                    if (steps[y][x] + 1 > t)
                        continue;
                    q.push({yy, xx, gram});
                    steps[yy][xx] = steps[y][x] + 1;
                }
            }
            else if (gram == true)
            {
                if (gramSteps[yy][xx] > gramSteps[y][x] + 1)
                {
                    if (gramSteps[y][x] + 1 > t)
                        continue;
                    q.push({yy, xx, gram});
                    gramSteps[yy][xx] = gramSteps[y][x] + 1;
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> t;
    arr.resize(n, vector<int>(m));
    steps.assign(n, vector<int>(m, INT_MAX));
    gramSteps.assign(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    bfs();
    // for (auto i : steps)
    // {
    //     for (auto j : i)
    //     {
    //         if (j == INT_MAX)
    //         {
    //             cout << "x ";
    //             continue;
    //         }
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }

    int minv = min(steps[n - 1][m - 1], gramSteps[n - 1][m - 1]);
    if (minv <= t)
    {
        cout << minv << '\n';
    }
    else
    {
        cout << "Fail" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}