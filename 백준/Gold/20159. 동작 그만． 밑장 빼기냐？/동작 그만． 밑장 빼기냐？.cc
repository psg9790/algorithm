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
vector<int> v;
vector<int> odd;
vector<int> even;
void solve()
{
    cin >> n;
    v.resize(n + 2);
    odd.resize(n + 2, 0);
    even.resize(n + 2, 0);
    for (int i = 2; i < n + 2; i++)
    {
        cin >> v[i];
        if (i % 2 == 0)
            even[i] += even[i - 2] + v[i];
        else
            odd[i] += odd[i - 2] + v[i];
    }
    int maxv = even[n];
    debug(maxv);
    for (int i = 2; i < n + 2; i++)
    {
        if (i % 2 == 0)
            maxv = max(maxv, even[i - 2] + odd[odd.size() - 1] - odd[i - 1]);
        else
            maxv = max(maxv, even[i - 1] + odd[odd.size() - 3] - odd[i - 2]);
    }
    cout << maxv << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}