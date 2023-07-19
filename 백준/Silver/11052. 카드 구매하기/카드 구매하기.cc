#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;
vector<int> dp;
int solve()
{
    dp = p;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j >= 1)
            {
                dp[i] = max(dp[i], dp[i - j] + p[j]);
                // for (auto t : dp)
                //     cout << t << ' ';
                // cout << '\n';
            }
        }
    }
    return dp[n];
}

int main()
{
    cin >> n;
    p.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        p.push_back(token);
    }
    cout << solve() << '\n';
}