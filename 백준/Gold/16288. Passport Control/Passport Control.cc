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

int n, k;
vector<int> res;
vector<int> idx;

bool push(int num)
{
    for (int i = 0; i < k; i++)
    {
        if (num > idx[i])
        {
            idx[i] = num;
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n >> k;
    idx.resize(k, -1);
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        res.push_back(token);
    }
    for (auto i : res)
    {
        if (push(i) == false)
        {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}