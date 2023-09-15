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

ll n;
void solve()
{
    cin >> n;
    int i = 1;
    while (++i)
    {
        ll mulv = i * pow((ll)2, i - 1);
        debug(i, mulv);
        if (mulv > n / 2)
        {
            cout << i - 1 << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}