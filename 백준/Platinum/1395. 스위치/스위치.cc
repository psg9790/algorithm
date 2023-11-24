#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int n, m;
vector<int> tree;
vector<int> lazy;
void printTree()
{
    cout << "=====================\n";
    cout << "tree\n";
    for (int i = 0; i < n * 4; i++)
    {
        cout << i << " val: " << tree[i] << '\n';
    }
    cout << "lazy\n";
    for (int i = 0; i < n * 4; i++)
    {
        cout << i << " val: " << lazy[i] << '\n';
    }
    cout << "=====================\n";
}

void push(int v, int s, int e)
{
    lazy[v] %= 2;
    if (lazy[v] != 0)
    {
        tree[v] = (e - s + 1) - tree[v];
        if (s != e)
        {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        else
        {
            tree[v] %= 2;
        }
        lazy[v] = 0;
    }
}

void update(int v, int s, int e, int l, int r)
{
    push(v, s, e);
    if (s > r || e < l)
        return;
    if (l <= s && e <= r)
    {
        // lazy
        tree[v] = (e - s + 1) - tree[v];
        if (s != e)
        {
            lazy[v * 2] += 1;
            lazy[v * 2 + 1] += 1;
        }
        else
        {
            tree[v] %= 2;
        }
        return;
    }
    int tm = (s + e) / 2;
    update(v * 2, s, tm, l, r);
    update(v * 2 + 1, tm + 1, e, l, r);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int query(int v, int s, int e, int l, int r)
{
    push(v, s, e);
    if (s > r || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[v];
    int tm = (s + e) / 2;
    return query(v * 2, s, tm, l, r) + query(v * 2 + 1, tm + 1, e, l, r);
}

void solve()
{
    cin >> n >> m;
    tree.resize(n * 4);
    lazy.resize(n * 4);
    for (int i = 0; i < m; i++)
    {
        int sym, a, b;
        cin >> sym >> a >> b;
        if (sym == 0) // 반전
        {
            update(1, 0, n - 1, a - 1, b - 1);

            // printTree();
        }
        else if (sym == 1) // 확인
        {
            cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';

            // printTree();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}