#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

#ifndef ONLINE_JUDGE
#include "C:\\DEBUG.h"
#else
#define debug(x...)
#endif

const int MAXN = 100'000;
int n, m;
int tree[4 * MAXN];

void build(int arr[], int v, int tl, int tr)
{
    // sum이 아니라 min tree
    if (tl == tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(arr, v * 2, tl, tm);
        build(arr, v * 2 + 1, tm + 1, tr);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
}

int findMin(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return INT_MAX;
    if (tl == l && tr == r)
        return tree[v];
    int tm = (tl + tr) / 2;
    return min(findMin(v * 2, tl, tm, l, min(r, tm)), findMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve()
{
    fill(&tree[0], &tree[4 * MAXN], INT_MAX);
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(arr, 1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << findMin(1, 0, n - 1, s - 1, e - 1) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}