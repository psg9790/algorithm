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
const ll MOD = 1'000'000'007;
ll n, m, k;
ll tree[4 * MAXN];

void build(ll arr[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        debug(v, tl);
        tree[v] = arr[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(arr, v * 2, tl, tm);
        build(arr, v * 2 + 1, tm + 1, tr);
        tree[v] = (tree[2 * v] * tree[2 * v + 1]) % MOD;
    }
}

ll multi(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 1;
    if (tl == l && tr == r)
        return tree[v];
    ll tm = (tl + tr) / 2;
    return (multi(v * 2, tl, tm, l, min(r, tm)) * multi(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
}

void update(ll v, ll tl, ll tr, ll pos, ll posNum)
{
    if (tl == tr)
    {
        tree[v] = posNum;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, posNum);
        else
            update(v * 2 + 1, tm + 1, tr, pos, posNum);
        tree[v] = (tree[2 * v] * tree[2 * v + 1]) % MOD;
    }
}

void solve()
{
    fill(&tree[0], &tree[4 * MAXN], 1);
    cin >> n >> m >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, 1, 0, n - 1);
    for (int i = 0; i < m + k; i++)
    {
        ll s, a, b;
        cin >> s >> a >> b;
        if (s == 1)
        {
            update(1, 0, n - 1, a - 1, b);
        }
        else
        {
            // for (int j = 0; j < 4 * n; j++)
            //     cout << tree[j] << ' ';
            // cout << '\n';
            cout << multi(1, 0, n - 1, a - 1, b - 1) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}