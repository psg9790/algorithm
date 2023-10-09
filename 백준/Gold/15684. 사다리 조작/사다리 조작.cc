#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int n, m, h;
int ans = -1;
vector<set<int>> adj;

bool Simulate()
{
    for (int i = 1; i <= n; i++)
    {
        int idx = i;
        for (int j = 1; j <= h; j++)
        {
            if (adj[j].count(idx - 1))
            {
                idx--;
            }
            else if (adj[j].count(idx))
            {
                idx++;
            }
        }
        if (idx == i)
            continue;
        else
            return false;
    }
    return true;
}

bool dfsdfs(int cnt, int cur, int ival, int jval)
{
    if (cnt == cur)
    {
        if (Simulate())
        {
            ans = cnt;
            return true;
        }
        return false;
    }

    for (int i = ival; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (adj[i].count(j) != 0 || adj[i].count(j - 1) != 0 || adj[i].count(j + 1) != 0)
                continue;
            debug(cnt, cur, i, j);

            adj[i].insert(j);
            if (dfsdfs(cnt, cur + 1, i, j + 2))
                return true;
            adj[i].erase(j);
        }
    }
    return false;
}
void dfs()
{
    for (int i = 1; i <= 3; i++)
    {
        if (dfsdfs(i, 0, 1, 1))
            return;
    }
}
void solve()
{
    cin >> n >> m >> h;
    adj.resize(h + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
    }
    if (Simulate())
    {
        cout << 0 << '\n';
        return;
    }
    dfs();
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}