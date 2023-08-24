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
ll tree[4 * MAXN];
int n, m;

void build(ll arr[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(arr, 2 * v, tl, tm);
        build(arr, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
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
            update(2 * v, tl, tm, tgt, tgtVal);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, tgt, tgtVal);
        }
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return tree[v];
    ll tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            if (b > c)
                cout << sum(1, 0, n - 1, c - 1, b - 1) << '\n';
            else
                cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
        }
        else if (a == 1)
        {
            update(1, 0, n - 1, b - 1, c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}