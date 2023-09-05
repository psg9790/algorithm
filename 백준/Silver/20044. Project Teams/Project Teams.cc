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
int ans = INT_MAX;
void solve()
{
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        int token;
        cin >> token;
        v.push_back(token);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int sumv = v[i] + v[2 * n - 1 - i];
        ans = min(ans, sumv);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}