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
ll n, k;
ll tree[4 * MAXN];

int conv(int val)
{
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}
void build(ll arr[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        tree[v] = conv(arr[tl]);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(arr, v * 2, tl, tm);
        build(arr, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] * tree[v * 2 + 1];

        // 양수, 음수, 0인지만 중요
        tree[v] = conv(tree[v]);
    }
}

ll mult(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 1;
    if (tl == l && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    return mult(v * 2, tl, tm, l, min(r, tm)) * mult(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int tgt, int tgtVal)
{
    if (tl == tr)
    {
        tree[v] = conv(tgtVal);
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (tgt <= tm)
            update(v * 2, tl, tm, tgt, tgtVal);
        else
            update(v * 2 + 1, tm + 1, tr, tgt, tgtVal);
        tree[v] = tree[v * 2] * tree[v * 2 + 1];
    }
}
void print()
{
#ifndef ONLINE_JUDGE
    for (int i = 0; i < 4 * n; i++)
        cout << tree[i] << ' ';
    cout << '\n';
#endif
}
void solve()
{
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, 1, 0, n - 1);
    print();
    for (int i = 0; i < k; i++)
    {
        char sym;
        int a, b;
        cin >> sym >> a >> b;
        if (sym == 'C')
        {
            update(1, 0, n - 1, a - 1, b);
        }
        else if (sym == 'P')
        {
            int res = mult(1, 0, n - 1, a - 1, b - 1);
            if (res > 0)
                cout << '+';
            else if (res < 0)
                cout << '-';
            else
                cout << '0';
        }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> k)
        solve();
}