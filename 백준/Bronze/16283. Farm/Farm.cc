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

bool ans = false;
int ans1 = -1, ans2 = -1;
int a, b, n, w;
void solve()
{
    cin >> a >> b >> n >> w;
    int lamb = 1;
    int goat;
    while (goat = n - lamb)
    {
        int sumv = lamb * a + goat * b;
        if (sumv == w)
        {
            if (ans)
            {
                cout << -1 << '\n';
                return;
            }
            ans = true;
            ans1 = lamb;
            ans2 = goat;
        }
        lamb++;
    }
    if (ans)
    {
        cout << ans1 << ' ' << ans2 << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}