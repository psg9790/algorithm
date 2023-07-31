#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<vector<int>> adj;
vector<int> inDegree;

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    inDegree.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            pq.push(i);

    while (!pq.empty())
    {
        int frt = pq.top();
        pq.pop();

        cout << frt << ' ';
        for (auto u : adj[frt])
        {
            if (--inDegree[u] == 0)
            {
                pq.push(u);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
