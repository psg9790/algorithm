#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int n, m, k;
int a, b;
vector<bool> used;
vector<vector<int>> dp;
void knapsack(int amount)
{
    dp.assign(amount + 1, vector<int>());
    for (int i = 1; i <= amount; i++)
    {
        if (used[i] == true)
            continue;
        for (int j = 1; j <= amount; j++)
        {
            if (i == j)
                continue;
            if (dp[j].size() > 0)
                if (i + j <= amount)
                {
                    dp[i + j].push_back(i);
                }
        }
        dp[i].push_back(i);
    }
}
int dfs(int amount)
{
    // debug(dp);
    int ans = 0;
    bool bval = false;
    // select 2
    for (int i = amount; i >= 1; i--)
    {
        if (dp[i].size() > 0)
        {
            int a = dp[i].back();
            int b = i - dp[i].back();
            debug(a, b);
            used[a] = true;
            used[b] = true;
            ans += (amount - i);
            bval = true;
            break;
        }
    }
    if (bval == false)
    {
        ans = amount * 2;
        return ans;
    }

    dp.clear();
    knapsack(amount);
    // debug(dp);
    for (int i = amount; i >= 1; i--)
    {
        if (dp[i].size() > 0)
        {
            int a = dp[i].back();
            int b = i - dp[i].back();
            debug(a, b);
            ans += amount - i;
            return ans;
        }
    }
    debug(amount);
    return ans + amount;
}
void solve()
{
    cin >> n >> m >> k;
    used.resize(n + 1, false);
    used[m] = true;
    a = k;
    b = n - (m + k);
    if (a == 0 && b == 0)
    {
        cout << 0 << '\n';
        return;
    }

    if (a != b)
    {
        if (used[a] == false) // b만 고려
        {
            debug(a);
            used[a] = true;
            knapsack(b);
            for (int i = b; i >= 1; i--)
            {
                if (dp[i].size() > 0)
                {
                    debug(dp[i].back(), i - dp[i].back());
                    cout << b - i << '\n';
                    return;
                }
            }
            cout << b << '\n';
        }
        else if (used[b] == false) // a만 고려
        {
            debug(b);
            used[b] = true;
            knapsack(a);
            for (int i = a; i >= 1; i--)
            {
                if (dp[i].size() > 0)
                {
                    debug(dp[i].back(), i - dp[i].back());
                    cout << a - i << '\n';
                    return;
                }
            }
            cout << a << '\n';
        }
    }
    else
    {
        knapsack(a);
        cout << dfs(a) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}