#include <iostream>
#include <vector>
#include <queue>
using namespace std;

auto pqcmp = [](pair<int, int> &a, pair<int, int> &b) -> bool
{
    return a.first > b.first;
};

int v, e, k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e >> k;
    vector<vector<pair<int, int>>> edges(v + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    vector<int> d(v + 1, INT32_MAX);
    d[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pqcmp)> pq(pqcmp);
    pq.push({d[k], k});

    while (!pq.empty())
    {
        int curWeight = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (d[curNode] < curWeight)
            continue;

        for (int i = 0; i < edges[curNode].size(); i++)
        {
            int &nextNode = edges[curNode][i].first;
            int &nextCost = edges[curNode][i].second;

            if (d[nextNode] > curWeight + nextCost)
            {
                d[nextNode] = curWeight + nextCost;
                pq.push({d[nextNode], nextNode});
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (d[i] == INT32_MAX)
        {
            cout << "INF" << '\n';
            continue;
        }
        cout << d[i] << '\n';
    }
    return 0;
}