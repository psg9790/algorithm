#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<vector<ip>> syms;
vector<int> dp;
vector<int> zeros;

int symToInt(char c)
{
    switch (c)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    default:
        break;
    }
    return -1;
}

int symCalc(int a, int b, int sym)
{
    switch (sym)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    default:
        break;
    }
    return -1;
}

void dp1()
{
    dp.assign(n + 1, INT_MIN);
    zeros.assign(n + 1, INT_MIN);
    dp[0] = 1;
    zeros[0] = 1;
    for (int i = 1; i <= n; i++) // original dp
    {
        dp[i] = max(dp[i], symCalc(dp[i - 1], syms[i][0].first, syms[i][0].second));
        dp[i] = max(dp[i], symCalc(dp[i - 1], syms[i][1].first, syms[i][1].second));
        zeros[i] = dp[i - 1]; // skip step
        if (dp[i] <= 0)
            break;
    }

    for (int i = n; i > 0; i--)
    {
        if (zeros[i] > dp[i]) // skipable
        {
            if (i == n)
            {
                dp[i] = zeros[i];
                continue;
            }
            int target = zeros[i];
            for (int j = i + 1; j <= n; j++) // redo dp
            {
                int calc1 = symCalc(target, syms[j][0].first, syms[j][0].second);
                int calc2 = symCalc(target, syms[j][1].first, syms[j][1].second);
                if (max(calc1, calc2) > dp[j])
                {
                    dp[j] = max(calc1, calc2);
                }
                else
                {
                    break;
                }
                target = dp[j];
                if (dp[j] <= 0)
                    break;
            }
        }
    }
}
void solve()
{
    cin >> n;
    syms.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string a, b;
        cin >> a >> b;

        syms[i].push_back({a[1] - '0', symToInt(a[0])});
        syms[i].push_back({b[1] - '0', symToInt(b[0])});
    }

    dp1();

    if (dp[n] <= 0)
        cout << "ddong game" << '\n';
    else
        cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}