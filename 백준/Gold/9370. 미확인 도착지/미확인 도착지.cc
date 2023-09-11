#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int n, m, t;
int ss, g, h;
int interDist;
vector<vector<ip>> adj;
vector<int> ans;

int Dijkstra(int _s, int _e)
{
    priority_queue<ip> pq;
    vector<int> visited(n + 1, INT_MAX);

    pq.push({_s, 0});
    visited[_s] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int curCost = pq.top().second;
        pq.pop();

        if (visited[cur] < curCost)
            continue;

        for (auto i : adj[cur])
        {
            int nxt = i.first;
            int nxtCost = curCost + i.second;

            if (visited[nxt] > nxtCost)
            {
                // debug(cur, nxt);
                visited[nxt] = nxtCost;
                pq.push({nxt, nxtCost});
            }
        }
    }

    return visited[_e];
}

void solve()
{
    cin >> n >> m >> t;
    cin >> ss >> g >> h;
    adj = vector<vector<ip>>(n + 1);
    ans = vector<int>();

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});

        if ((a == g && b == h) || (a == h && b == g))
            interDist = c;
    }

    int toG = Dijkstra(ss, g) + interDist;
    int toH = Dijkstra(ss, h) + interDist;
    debug(toG, toH);

    for (int i = 0; i < t; i++)
    {
        int ee;
        cin >> ee;

        int minDist = Dijkstra(ss, ee);
        debug(ss, ee, minDist);
        int GtoH = toG + Dijkstra(h, ee);
        int HtoG = toH + Dijkstra(g, ee);
        debug(GtoH, HtoG);

        if (GtoH == minDist || HtoG == minDist)
            ans.push_back(ee);
    }

    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}