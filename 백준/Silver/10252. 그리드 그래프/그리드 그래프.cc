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

int n, m;

void solve()
{
    cin >> n >> m;
    cout << 1 << '\n';
    cout << "(0,0)" << '\n';
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) // right
        {
            for (int j = 1; j < m; j++)
            {
                cout << '(' << i << ',' << j << ')' << '\n';
            }
        }
        else // left
        {
            for (int j = m - 1; j > 0; j--)
            {
                cout << '(' << i << ',' << j << ')' << '\n';
            }
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        cout << '(' << i << ',' << 0 << ')' << '\n';
    }
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