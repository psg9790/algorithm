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

int n, m, x, y;
int gcd(int a, int b)
{
    int div = a % b;
    if (div == 0)
        return b;
    return gcd(b, div);
}

void solve()
{
    cin >> n >> m >> x >> y;
    y %= m;

    int lcm = (n * m) / gcd(n, m);

    for (int i = x; i <= lcm; i += n)
    {
        int tgt = i % m;
        if (tgt == y)
        {
            cout << i << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}