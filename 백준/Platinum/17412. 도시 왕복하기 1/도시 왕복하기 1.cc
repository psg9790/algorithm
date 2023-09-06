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
vector<vector<int>> adj(401);
vector<vector<int>> capacity(401, vector<int>(401));
vector<int> parent(401, -1);

int bfs(int s, int e) // 하나의 가짓수를 찾음
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<ip> q;
    q.push({s, INT_MAX});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (auto next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == e)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxFlow(int s, int e)
{
    int flow;
    int max_flow = 0;

    while (flow = bfs(1, 2))
    {
        max_flow += flow;

        int cur = 2;
        while (cur != 1) // 유량 역추적
        {
            int prev = parent[cur];
            capacity[prev][cur] -= flow;
            capacity[cur][prev] += flow;
            adj[cur].push_back(prev);
            cur = prev;
        }
    }

    return max_flow;
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        capacity[a][b] = 1; // 같은 경로 재사용 불가
    }

    cout << maxFlow(1, 2) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}