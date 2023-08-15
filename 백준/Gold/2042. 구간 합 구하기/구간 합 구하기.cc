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
ll n, m, k;
ll seg[4 * MAXN];

void build(ll arr[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        seg[v] = arr[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(arr, v * 2, tl, tm);
        build(arr, v * 2 + 1, tm + 1, tr);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return seg[v];
    ll tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        seg[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

void solve()
{
    cin >> n >> m >> k;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    build(arr, 1, 0, n - 1);

    for (ll i = 0; i < m + k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) // update
        {
            update(1, 0, n - 1, b - 1, c);
        }
        else if (a == 2) // print
        {
            cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}