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
vector<int> roots;
vector<int> root_nodes;
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

void solve()
{
    cin >> n >> m;
    adj.clear();
    adj_rev.clear();
    adj.resize(n);
    adj_rev.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    order.clear();
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);
    reverse(order.begin(), order.end());

    roots.clear();
    root_nodes.clear();
    adj_scc.clear();
    roots.resize(n);
    adj_scc.resize(n);
    visited.assign(n, false);
    for (auto u : order)
        if (!visited[u])
        {
            dfs2(u);

            int root = component.front();
            for (auto v : component)
                roots[v] = root;
            root_nodes.push_back(root);

            component.clear();
        }

    for (int i = 0; i < n; i++)
        for (auto j : adj[i])
            if (roots[i] != roots[j])
                adj_scc[roots[i]].push_back(roots[j]);

    // can travel all?
    set<int> canVisitAll;
    queue<int> q;
    q.push(root_nodes.front());
    canVisitAll.insert(root_nodes.front());
    while (!q.empty())
    {
        int frt = q.front();
        q.pop();

        for (auto u : adj_scc[frt])
        {
            if (canVisitAll.find(u) == canVisitAll.end())
            {
                canVisitAll.insert(u);
                q.push(u);
            }
        }
    }

    if (canVisitAll.size() == root_nodes.size())
    {
        int target = root_nodes.front();
        vector<int> result;
        for (int i = 0; i < n; i++)
            if (roots[i] == target)
                result.push_back(i);
        sort(result.begin(), result.end(), less<int>());
        for (auto i : result)
            cout << i << '\n';
        cout << '\n';
    }
    else
    {
        cout << "Confused" << '\n'
             << '\n';
    }
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