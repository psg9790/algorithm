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

int n, m, k;
int src, dst;
vector<vector<ip>> adj;
set<tuple<int, int, int>> forbid;
set<tuple<int, int, int>> visited;
ll ans = 0;

class route
{
public:
    int num;
    ll cost;
    ip past;

    vector<route *> Simulate()
    {
        vector<route *> rst;
        for (auto next : adj[num])
        {
            route *rr = new route();
            rr->num = next.first;
            rr->cost = cost + next.second;
            rr->past = {num, past.first};
            rst.push_back(rr);
        }
        return rst;
    }

    tuple<int, int, int> Past3()
    {
        return {num, past.first, past.second};
    }
};
struct routeCmp
{
    bool operator()(route *a, route *b)
    {
        return a->cost > b->cost;
    }
};

void Dijkstra()
{
    priority_queue<route *, vector<route *>, routeCmp> pq;

    route *init = new route();
    init->num = src;
    init->cost = 0;
    init->past = {-1, -1};
    pq.push(init);

    while (!pq.empty())
    {
        route *frt = pq.top();
        pq.pop();

        if (frt->num == dst)
        {
            ans = frt->cost;
            return;
        }

        vector<route *> ret = frt->Simulate();
        for (auto r : ret)
        {
            tuple<int, int, int> t = r->Past3();
            if (visited.find(t) != visited.end()) // 중복케이스
                continue;

            if (forbid.find(t) != forbid.end()) // 금지 루트
                continue;

            visited.insert(t);
            pq.push(r);
        }
    }

    ans = -1;
}

void solve()
{
    cin >> n >> m >> k;
    cin >> src >> dst;

    adj.resize(m + 1);

    for (int i = 0; i < n; i++)
    {
        int ss, ee, cc;
        cin >> ss >> ee >> cc;
        adj[ss].push_back({ee, cc});
    }

    for (int i = 0; i < k; i++)
    {
        int r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        forbid.insert({r1, r2, r3});
        forbid.insert({r3, r2, r1});
    }

    Dijkstra();
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}