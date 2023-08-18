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

int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;
vector<bool> visited;
vector<int> order;
vector<int> component;

vector<int> root_nodes;
vector<int> roots;
vector<vector<int>> adj_scc;

void dfs1(int idx)
{
    visited[idx] = true;
    for (auto u : adj[idx])
        if (!visited[u])
            dfs1(u);
    order.push_back(idx);
}

void dfs2(int idx)
{
    visited[idx] = true;
    component.push_back(idx);
    for (auto u : adj_rev[idx])
        if (!visited[u])
            dfs2(u);
}
void dfs3(int idx)
{
    visited[idx] = true;
    for (auto u : adj_scc[idx])
        if (!visited[u])
            dfs3(u);
}
void solve()
{
    cin >> n >> m;

    adj.resize(n + 1);
    adj_rev.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w);
        adj_rev[w].push_back(v);
    }

    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);
    reverse(order.begin(), order.end());
    debug(order);

    visited.assign(n + 1, false);
    roots.resize(n + 1);
    for (auto i : order)
        if (!visited[i])
        {
            dfs2(i);

            debug(component);

            int root = component.front();
            root_nodes.push_back(root);
            for (auto u : component)
                roots[u] = root;

            component.clear();
        }

    adj_scc.resize(n + 1);
    for (int i = 1; i <= n; i++)
        for (auto u : adj[i])
            if (roots[i] != roots[u])
                adj_scc[roots[i]].push_back(roots[u]);

    debug(adj_scc);
    for (auto i : root_nodes)
    {
        visited.assign(n + 1, false);
        dfs3(i);

        for (auto j : root_nodes)
        {
            if (!visited[j]) // FAIL
            {
                cout << "No" << '\n';
                return;
            }
        }
    }
    cout << "Yes" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}