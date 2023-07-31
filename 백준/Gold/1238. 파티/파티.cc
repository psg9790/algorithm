#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

struct ipcmp
{
    bool operator()(const ip &a, const ip &b)
    {
        return a.second > b.second;
    }
};

int n, m, x;
vector<vector<ip>> adj;

vector<int> dijkstra(int start)
{
    vector<int> result(n + 1, INT_MAX);
    priority_queue<ip, vector<ip>, ipcmp> pq;
    result[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        int curNum = pq.top().first, curCost = pq.top().second;
        pq.pop();

        if (result[curNum] < curCost)
            continue;

        for (auto u : adj[curNum])
        {
            int nextNum = u.first, nextCost = curCost + u.second;
            if (result[nextNum] < nextCost)
                continue;
            result[nextNum] = nextCost;
            pq.push({nextNum, nextCost});
        }
    }

    return result;
}

void solve()
{
    cin >> n >> m >> x;
    adj.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int result = 0;
    vector<int> xtoall = dijkstra(x);
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        int icost = dijkstra(i)[x] + xtoall[i];
        result = max(result, icost);
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
