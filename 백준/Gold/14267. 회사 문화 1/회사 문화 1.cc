#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<int> p;
vector<vector<int>> adj;
vector<int> please;

void dfs(int idx)
{
    for (auto i : adj[idx])
    {
        please[i] += please[idx];
        dfs(i);
    }
}

void solve()
{
    cin >> n >> m;
    p.resize(n + 1);
    adj.resize(n + 1);
    please.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] != -1)
            adj[p[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        please[a] += b;
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << please[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}