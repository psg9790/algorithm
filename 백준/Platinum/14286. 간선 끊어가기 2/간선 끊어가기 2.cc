#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ip = pair<int,int>;

int n, m;
int s, t;
vector<vector<int>> adj;
vector<vector<int>> capacity;

int bfs(int s, int e, vector<int> &parent)
{
    parent.assign(n+1, -1);
    parent[s] = -2;
    queue<ip> q;
    q.push({s, INT32_MAX});

    while(!q.empty())
    {
        int cur = q.front().first;
        int curFlow = q.front().second;
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(parent[nxt] == -1 && capacity[cur][nxt])
            {
                parent[nxt] = cur;
                int new_flow = min(curFlow, capacity[cur][nxt]);
                if(nxt == e)
                    return new_flow;
                q.push({nxt, new_flow});
            }
        }
    }
    return 0;
}

int maxFlow(int s, int e)
{
    int flow = 0;
    vector<int> parent(n+1, -1);
    int new_flow;

    while(new_flow = bfs(s, e, parent))
    {
        flow += new_flow;
        
        int cur = e;
        while(cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void solve()
{
    cin >> n >> m;
    adj.resize(n+1);
    capacity.resize(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 간선 추가
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] += c;
        capacity[b][a] += c;
    }
    cin >> s >> t;
    cout << maxFlow(s, t) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}