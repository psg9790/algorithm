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

const int MAXN = 1'000'000;
ll n, m, k;
ll tree[4 * MAXN];
ll lazy[4 * MAXN] = {0};

void print()
{
#ifndef ONLINE_JUDGE
    cout << "=======================\n";
    cout << "tree: ";
    for (int i = 0; i < n * 4; i++)
    {
        cout << tree[i] << ", ";
    }
    cout << '\n';
    cout << "lazy: ";
    for (int i = 0; i < n * 4; i++)
    {
        cout << lazy[i] << ", ";
    }
    cout << '\n';
    cout << "=======================\n";
#endif
}

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
    push(v, tl, tr); // lazy 확인 후 밀어줌

    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        tree[v] += (r - l + 1) * val; // 범위만큼의 변화를 더해줌

        if (l != r) // 자식노드가 있으면 lazy 처리
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

ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    push(v, tl, tr); // lazy 확인 후 밀어줌

    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void solve()
{
    cin >> n >> m >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(arr, 1, 0, n - 1);
    print();

    for (int i = 0; i < m + k; i++)
    {
        ll a, b, c, d;
        cin >> a;

        if (a == 1) // update
        {
            cin >> b >> c >> d;
            update(1, 0, n - 1, b - 1, c - 1, d);
        }
        else if (a == 2) // sum
        {
            cin >> b >> c;
            cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
        }

        print();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}