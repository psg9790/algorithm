#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;
vector<bool> visited;
vector<int> order;
vector<int> component;

void topology_dfs(int idx)
{
    visited[idx] = true;
    for (auto i : adj[idx])
        if (!visited[i])
            topology_dfs(i);
    order.push_back(idx);
}

void scc_dfs(int idx)
{
    visited[idx] = true;
    component.push_back(idx);
    for (auto i : adj_rev[idx])
        if (!visited[i])
            scc_dfs(i);
}

void solve()
{
    cin >> n >> m;
    adj.clear();
    adj_rev.clear();
    adj.resize(n + 1);
    adj_rev.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    order.clear();
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            topology_dfs(i);
    reverse(order.begin(), order.end());

    vector<int> roots(n + 1);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n + 1);
    visited.assign(n + 1, false);
    for (auto i : order)
        if (!visited[i])
        {
            scc_dfs(i);

            int root = component.front();
            for (auto u : component)
                roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }

    for (int i = 1; i <= n; i++)
        for (auto u : adj[i])
            if (roots[u] != roots[i])
                adj_scc[roots[i]].push_back(roots[u]);

    int result = 0;
    visited.assign(n + 1, false);
    for (int i = 0; i < root_nodes.size(); i++)
    {
        int idx = root_nodes[i];
        if (!visited[idx])
        {
            result++;
            queue<int> q;
            q.push(idx);
            visited[idx] = true;

            while (!q.empty())
            {
                int frt = q.front();
                q.pop();

                for (auto u : adj_scc[frt])
                {
                    if (!visited[u])
                    {
                        visited[u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}