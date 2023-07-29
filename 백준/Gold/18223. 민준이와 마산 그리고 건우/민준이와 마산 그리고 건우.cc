#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int v, e, p;
vector<vector<ip>> adjs;

struct pqcmp
{
    bool operator()(const ip &a, const ip &b)
    {
        return a.second > b.second;
    }
};

int dijkstra(int start, int end)
{
    int result = 0;
    priority_queue<ip, vector<ip>, pqcmp> pq;
    vector<bool> visited(v + 1);
    visited[1] = true;
    for (int i = 0; i < adjs[start].size(); i++)
        pq.push(adjs[start][i]);

    while (!pq.empty())
    {
        ip frt = pq.top();
        int cur = frt.first, curCost = frt.second;
        pq.pop();
        if (cur == end)
        {
            result = curCost;
            break;
        }

        if (visited[cur])
            continue;
        visited[cur] = true;

        for (int i = 0; i < adjs[cur].size(); i++)
        {
            int next = adjs[cur][i].first, nextCost = adjs[cur][i].second;
            if (visited[next])
                continue;
            pq.push({next, curCost + nextCost});
        }
    }
    return result;
}

void solve()
{
    cin >> v >> e >> p;
    adjs.clear();
    adjs.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjs[a].push_back({b, c});
        adjs[b].push_back({a, c});
    }

    int shortcut = dijkstra(1, v);
    int geonwoo = dijkstra(1, p) + dijkstra(p, v);
    if (shortcut == geonwoo)
        cout << "SAVE HIM" << '\n';
    else
        cout << "GOOD BYE" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}