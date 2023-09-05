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

const ll MAXN = 100'000;
ll tree[MAXN * 4];
ll lazy[MAXN * 4];
ll n, m;

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

void push(ll v, ll tl, ll tr)
{
    if (lazy[v] != 0)
    {
        tree[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr)
        {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    push(v, tl, tr);
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        tree[v] += (r - l + 1) * val;
        if (l != r)
        {
            lazy[v * 2] += val;
            lazy[v * 2 + 1] += val;
        }
    }
    else
    {
        ll tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), val);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    push(v, tl, tr);
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void solve()
{
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, 1, 0, n - 1);

    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll sym;
        cin >> sym;
        if (sym == 1) // add
        {
            ll a, b, c;
            cin >> a >> b >> c;
            update(1, 0, n - 1, a - 1, b - 1, c);
        }
        else if (sym == 2) // search
        {
            ll a;
            cin >> a;
            cout << sum(1, 0, n - 1, a - 1, a - 1) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}