#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

void dfs(int idx)
{
    visited[idx] = true;
    for (auto i : adj[idx])
        if (!visited[i])
            dfs(i);
    ans.push_back(idx);
}

void topology_sort()
{
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
    }
    topology_sort();
    for (vector<int>::iterator _iter = --ans.end(); _iter != --ans.begin(); _iter--)
        cout << *_iter << ' ';
}
