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
int n, m, cx, cy;
int parent[500001];

int findRoot(int x)
{
    if (x != parent[x])
    {
        parent[x] = findRoot(parent[x]);
    }
    return parent[x];
}

void unionNode(int x, int y)
{
    x = findRoot(x);
    y = findRoot(y);

    if (x < y)
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> cx >> cy;
        int px = findRoot(cx);
        int py = findRoot(cy);

        if (px != py)
        {
            unionNode(px, py);
        }
        else
        {
            cout << i << "\n";
            return;
        }
    }

    cout << 0 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}