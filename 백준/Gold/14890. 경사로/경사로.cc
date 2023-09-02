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

int n, l;
vector<vector<int>> v;
int ans = 0;

void solve()
{
    cin >> n >> l;
    v.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    // row
    for (int i = 0; i < n; i++)
    {
        vector<bool> built(n, false);

        for (int j = 0; j < n - 1; j++)
        {
            int diff = v[i][j + 1] - v[i][j];
            if (abs(diff) >= 2)
            {
                goto FAIL1;
            }
            if (diff > 0) // 오르막
            {
                if (j + 1 < l) // 공간부족
                {
                    goto FAIL1;
                }
                // 지난 길 확인
                for (int t = j; t > j - l; t--)
                {
                    if (built[t])
                    {
                        goto FAIL1;
                    }
                    if (v[i][t] != v[i][j])
                    {
                        goto FAIL1;
                    }
                }
                // 경사로 세우기
                for (int t = j; t > j - l; t--)
                {
                    built[t] = true;
                }
            }
            else if (diff < 0) // 내리막
            {
                if (n - 1 - j < l) // 공간부족
                {
                    goto FAIL1;
                }
                // 갈 길 확인
                for (int t = j + 1; t <= j + l; t++)
                {
                    if (built[t])
                    {
                        goto FAIL1;
                    }
                    if (v[i][t] != v[i][j + 1])
                    {
                        goto FAIL1;
                    }
                }
                // 경사로 세우기
                for (int t = j + 1; t <= j + l; t++)
                {
                    built[t] = true;
                }
            }
        }

        ans++;

    FAIL1:
        continue;
    }

    // column
    for (int i = 0; i < n; i++)
    {
        vector<bool> built(n, false);

        for (int j = 0; j < n - 1; j++)
        {
            int diff = v[j + 1][i] - v[j][i];
            if (abs(diff) >= 2)
            {
                goto FAIL2;
            }
            if (diff > 0) // 오르막
            {
                if (j + 1 < l) // 공간부족
                {
                    goto FAIL2;
                }
                // 지난 길 확인
                for (int t = j; t > j - l; t--)
                {
                    if (built[t])
                    {
                        goto FAIL2;
                    }
                    if (v[t][i] != v[j][i])
                    {
                        goto FAIL2;
                    }
                }
                // 경사로 세우기
                for (int t = j; t > j - l; t--)
                {
                    built[t] = true;
                }
            }
            else if (diff < 0) // 내리막
            {
                if (n - 1 - j < l) // 공간부족
                {
                    goto FAIL2;
                }
                // 갈 길 확인
                for (int t = j + 1; t <= j + l; t++)
                {
                    if (built[t])
                    {
                        goto FAIL2;
                    }
                    if (v[t][i] != v[j + 1][i])
                    {
                        goto FAIL2;
                    }
                }
                // 경사로 세우기
                for (int t = j + 1; t <= j + l; t++)
                {
                    built[t] = true;
                }
            }
        }

        ans++;

    FAIL2:
        continue;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}