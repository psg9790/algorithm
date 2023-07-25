#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int token;
            cin >> token;
            arr[i].push_back(token);
        }
    }
    int rstToken = min(arr[1][0], arr[1][1]), rstValue = 1;
    vector<vector<int>> dp(n + 1, vector<int>(2, 1));
    for (int i = 1; i < n; i++)
    {
        // 전 테이블에 있는지 확인
        for (int j = 0; j < 2; j++)
        {
            for (int nxt = 0; nxt < 2; nxt++)
            {
                if (arr[i][j] == arr[i + 1][nxt])
                {
                    dp[i + 1][nxt] = dp[i][j] + 1;
                }

                if (rstValue < dp[i + 1][nxt])
                {
                    rstToken = arr[i][j];
                    rstValue = dp[i + 1][nxt];
                }
                else if (rstValue == dp[i + 1][nxt])
                {
                    if (rstToken > arr[i + 1][nxt])
                    {
                        rstToken = arr[i][j];
                        rstValue = dp[i + 1][nxt];
                    }
                }
            }
        }
    }

    // cout << " ============= " << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << " ============= " << '\n';

    cout << rstValue << ' ' << rstToken << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}