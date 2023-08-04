#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<int> cost;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;

// topology
vector<int> order;
vector<bool> visited;

// scc
vector<int> component;

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
    cin >> n;
    cost.resize(n + 1);
    adj.resize(n + 1);
    adj_rev.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= n; j++)
        {
            if (str[j - 1] == '1')
            {
                adj[i].push_back(j);
                adj_rev[j].push_back(i);
            }
        }
    }

    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);
    reverse(order.begin(), order.end());

    int result = 0;
    visited.assign(n + 1, false);
    for (auto i : order)
    {
        if (!visited[i])
        {
            dfs2(i);

            int minv = INT_MAX;
            for (auto u : component)
                minv = min(minv, cost[u]);
            result += minv;

            component.clear();
        }
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}