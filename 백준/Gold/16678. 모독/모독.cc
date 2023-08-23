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
priority_queue<ll, vector<ll>, greater<ll>> pq;
ll ans = 0;
ll tgt = 1;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll token;
        cin >> token;
        pq.push(token);
    }

    while (!pq.empty())
    {
        ll diff = pq.top() - tgt;
        debug(pq.top(), tgt);
        pq.pop();

        if (diff >= 0) // 해당 tgt 수가 존재하면
        {
            ans += diff;
            tgt++; // 다음 타겟
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}