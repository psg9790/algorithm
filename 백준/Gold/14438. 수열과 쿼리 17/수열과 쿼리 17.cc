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

const int MAXN = 100'000;
int n, m;
int tree[4 * MAXN];

void build(int arr[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(arr, 2 * v, tl, tm);
        build(arr, 2 * v + 1, tm + 1, tr);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}
void update(int v, int tl, int tr, int tgt, int tgtVal)
{
    if (tl == tr)
    {
        tree[v] = tgtVal;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (tgt <= tm)
        {
            update(2 * v, tl, tm, tgt, tgtVal);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, tgt, tgtVal);
        }
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}
int findMin(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return INT_MAX;
    if (tl == l && tr == r)
        return tree[v];
    int tm = (tl + tr) / 2;
    return min(findMin(2 * v, tl, tm, l, min(r, tm)), findMin(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve()
{
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, 1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, a, b;
        cin >> s >> a >> b;
        if (s == 1)
        {
            update(1, 0, n - 1, a - 1, b);
        }
        else if (s == 2)
        {
            cout << findMin(1, 0, n - 1, a - 1, b - 1) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}