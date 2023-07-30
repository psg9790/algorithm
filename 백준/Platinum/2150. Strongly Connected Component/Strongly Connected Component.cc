#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int v, e;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;
vector<bool> visited;
vector<int> order;
vector<int> components;

void dfs1(int idx)
{
    visited[idx] = true;
    for (auto i : adj[idx])
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    order.push_back(idx);
}

void dfs2(int idx)
{
    visited[idx] = true;
    components.push_back(idx);
    for (auto i : adj_rev[idx])
    {
        if (!visited[i])
        {
            dfs2(i);
        }
    }
}

void solve()
{
    cin >> v >> e;
    adj.resize(v + 1);
    adj_rev.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    visited.assign(v + 1, false);
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());

    vector<vector<int>> scc;
    visited.assign(v + 1, false);
    for (auto i : order)
    {
        if (!visited[i])
        {
            dfs2(i);

            sort(components.begin(), components.end());
            scc.push_back(components);

            components.clear();
        }
    }

    sort(scc.begin(), scc.end(), [](vector<int> a, vector<int> b)
         { return a[0] < b[0]; });

    cout << scc.size() << '\n';
    for (auto i : scc)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << "-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}