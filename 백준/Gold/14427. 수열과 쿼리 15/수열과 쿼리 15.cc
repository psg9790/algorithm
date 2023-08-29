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

struct ipcmp
{
    bool operator()(const ip &a, const ip &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

int n, m;
vector<int> v;
priority_queue<ip, vector<ip>, ipcmp> pq;

void solve()
{
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pq.push({v[i], i});
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int sym;
        cin >> sym;
        if (sym == 1) // change
        {
            int idx, val;
            cin >> idx >> val;
            v[idx] = val;
            pq.push({val, idx});
        }
        else if (sym == 2) // print
        {
            while (pq.top().first != v[pq.top().second])
            {
                pq.pop();
            }
            debug(pq.top().first);
            cout << pq.top().second << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}