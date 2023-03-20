#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[16][16] = {{0}};
int ts[16] = {0};
int ps[16] = {0};
int maxi = 0;

void PrintArr()
{
    cout << "=========================\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ts[i] >> ps[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i + ts[i] - 1 > n)
            continue;

        for (int j = i; j < ts[i] + i; j++)
        {
            dp[i][j] = max(dp[i][j], ps[i]);
            maxi = max(dp[i][j], maxi);
        }

        // 이전에 담았던거 확인
        for (int j = 1; j < i; j++)
        {
            if (dp[j][i] == 0)
            {
                for (int k = 1; k < i; k++)
                {
                    dp[i][i] = max(dp[i][i], dp[j][k] + ps[i]);
                }
            }
        }
        for (int j = i; j < ts[i] + i; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i][i]);
            maxi = max(dp[i][j], maxi);
        }
        // PrintArr();
    }
    cout << maxi << '\n';
}