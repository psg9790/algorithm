#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int v, e, p;
vector<vector<ip>> adjs;
vector<int> dist;

struct pqcmp
{
    bool operator()(const ip &a, const ip &b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int start)
{
    dist.clear();
    dist.assign(v + 1, INT_MAX);

    priority_queue<ip, vector<ip>, pqcmp> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        int cur = pq.top().first, curCost = pq.top().second;
        pq.pop();

        if (curCost > dist[cur])
            continue;

        for (int i = 0; i < adjs[cur].size(); i++)
        {
            int next = adjs[cur][i].first, nextCost = adjs[cur][i].second;
            int stepCost = curCost + nextCost;
            if (dist[next] <= stepCost)
                continue;
            dist[next] = stepCost;
            pq.push({next, stepCost});
        }
    }
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

    dijkstra(1);
    int shortcut = dist[v];
    int geonwoo = dist[p];
    dijkstra(p);
    geonwoo += dist[v];

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