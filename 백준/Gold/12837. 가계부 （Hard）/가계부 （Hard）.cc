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

const ll MAXN = 1'000'000;
ll n, q;
ll tree[4 * MAXN] = {0};

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    {
        tree[v] += val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(2 * v, tl, tm, pos, val);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }
        tree[v] = (tree[2 * v] + tree[2 * v + 1]);
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
    {
        return 0;
    }
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void solve()
{
    cin >> n >> q;

    for (int i = 0; i < q; i++)
    {
        ll s, a, b;
        cin >> s >> a >> b;
        if (s == 1) // add
        {
            update(1, 0, n - 1, a - 1, b);
        }
        else if (s == 2) // print
        {
            cout << sum(1, 0, n - 1, a - 1, b - 1) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}