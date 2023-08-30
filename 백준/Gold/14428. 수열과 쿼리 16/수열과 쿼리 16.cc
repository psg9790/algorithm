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

const int MAXN = 400'000;
int n, m;
ip tree[MAXN];

void build(int arr[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        tree[v] = {arr[tl], tl};
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(arr, 2 * v, tl, tm);
        build(arr, 2 * v + 1, tm + 1, tr);

        tree[v] = ((tree[2 * v].first <= tree[2 * v + 1].first) ? (tree[2 * v]) : (tree[2 * v + 1]));
    }
}

void update(int v, int tl, int tr, int tgt, int tgtVal)
{
    if (tl == tr)
    {
        tree[v] = {tgtVal, tgt};
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
        tree[v] = ((tree[2 * v].first <= tree[2 * v + 1].first) ? (tree[2 * v]) : (tree[2 * v + 1]));
    }
}

ip findMinIdx(int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return {INT_MAX, INT_MAX};
    }
    if (tl == l && tr == r)
    {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    ip ip1 = findMinIdx(2 * v, tl, tm, l, min(r, tm));
    ip ip2 = findMinIdx(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    if (ip1.first <= ip2.first)
    {
        return ip1;
    }
    else
    {
        return ip2;
    }
}

void print()
{
#ifndef ONLINE_JUDGE
    for (int i = 0; i < 4 * n; i++)
    {
        cout << "{" << tree[i].first << ' ' << tree[i].second << "}" << ' ';
    }
    cout << '\n';
#endif
}

void solve()
{
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(arr, 1, 0, n - 1);
    print();

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, a, b;
        cin >> s >> a >> b;
        if (s == 1) // update
        {
            update(1, 0, n - 1, a - 1, b);
            print();
        }
        else if (s == 2) // print
        {
            cout << findMinIdx(1, 0, n - 1, a - 1, b - 1).second + 1 << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}