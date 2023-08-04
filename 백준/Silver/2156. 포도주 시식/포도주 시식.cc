#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<int> drinks;
vector<int> dp;
void solve()
{
    cin >> n;
    drinks.assign(n + 1, 0);
    dp.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> drinks[i];

    dp[1] = drinks[1];
    dp[2] = drinks[1] + drinks[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + drinks[i]);
        dp[i] = max(dp[i], dp[i - 3] + drinks[i - 1] + drinks[i]);
    }
    cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}