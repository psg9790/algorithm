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

int n;
vector<vector<int>> adj;
vector<vector<int>> capacity;

int bfs(int s, int e, vector<int> &parent)
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
            if (parent[next] == -1 && capacity[cur][next]) // 아직 방문하지 않은 노드이고 용량이 남아있을 때
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]); // 해당 파이프로 흐를 수 있는 최소 유량
                if (next == e)
                    return new_flow;
                q.push({next, new_flow});
                // cout << cur << ' ' << next << " new_flow: " << new_flow << " -> \n";
            }
        }
    }
    return 0;
}

int maxflow(int s, int e)
{
    int flow = 0;
    vector<int> parent(52);
    int new_flow;

    while (new_flow = bfs(s, e, parent)) // 새롭게 목적지에 도달하는 유량이 존재
    {
        flow += new_flow; // 해당 유량을 추가

        int cur = e; // 추가한 유량을 역추적
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow; // 진행한 용량을 차감
            capacity[cur][prev] += new_flow; // 반대로 흐를 수 있는 유량을 추가
            cur = prev;
            // cout << (char)(cur + 'A') << ' ';
        }

        // cout << "new_flow: " << new_flow << '\n';
    }

    return flow;
}
bool isUpper(char alpha)
{
    if (alpha - 'A' >= 0 && alpha - 'A' < 26)
        return true;
    return false;
}
void solve()
{
    cin >> n;
    adj.resize(52);
    capacity.resize(52, vector<int>(52, 0));
    for (int i = 0; i < n; i++)
    {
        char a, b;
        int cap;
        cin >> a >> b >> cap;
        int aidx = isUpper(a) ? (a - 'A') : (26 + a - 'a');
        int bidx = isUpper(b) ? (b - 'A') : (26 + b - 'a');
        adj[aidx].push_back(bidx);
        adj[bidx].push_back(aidx); // 역방향간선을 추가해야 반대유량 case를 추가할 수 있음
        capacity[aidx][bidx] += cap;
        capacity[bidx][aidx] += cap;
    }
    cout << maxflow(0, 25) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}