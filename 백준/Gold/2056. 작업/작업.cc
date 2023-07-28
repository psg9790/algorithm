#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<int> costs;
vector<vector<int>> adjs;
vector<vector<int>> adjsB;
vector<bool> visited;
vector<int> orders;

void dfs(int idx)
{
    visited[idx] = true;
    for (auto i : adjs[idx])
        if (!visited[i])
            dfs(i);
    orders.push_back(idx);
}
void topology_sort()
{
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
    reverse(orders.begin(), orders.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    costs.assign(n + 1, 0);
    adjs.resize(n + 1);
    adjsB.resize(n + 1);
    visited.assign(n + 1, false);

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> costs[i];
        result = max(result, costs[i]);
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int pre;
            cin >> pre;
            adjs[pre].push_back(i);
            adjsB[i].push_back(pre);
        }
    }

    vector<int> rst = costs;
    topology_sort();
    for (auto i : orders)
    {
        for (auto j : adjsB[i])
        {
            rst[i] = max(rst[i], rst[j] + costs[i]);
            result = max(result, rst[i]);
        }
    }
    cout << result << '\n';
}