#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<ll, ll>;

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

const ll MAXN = 100'000;
ll tree[4 * MAXN];
ll n, q;

void build(ll arr[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(arr, v * 2, tl, tm);
        build(arr, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}
void update(ll v, ll tl, ll tr, ll tgt, ll tgtVal)
{
    if (tl == tr)
    {
        tree[v] = tgtVal;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (tgt <= tm)
        {
            update(v * 2, tl, tm, tgt, tgtVal);
        }
        else
        {
            update(v * 2 + 1, tm + 1, tr, tgt, tgtVal);
        }
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tree[v];
    ll tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void solve()
{
    cin >> n >> q;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, 1, 0, n - 1);

    for (ll i = 0; i < q; i++)
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x <= y)
            cout << sum(1, 0, n - 1, x - 1, y - 1) << '\n';
        else
            cout << sum(1, 0, n - 1, y - 1, x - 1) << '\n';
        update(1, 0, n - 1, a - 1, b);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}