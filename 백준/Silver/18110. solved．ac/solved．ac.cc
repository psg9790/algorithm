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

int n;
vector<int> v;
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        v.push_back(token);
    }
    sort(v.begin(), v.end());

    double amount = n * 0.15;
    int amounti = round(amount);

    int sumv = 0;
    int num = 0;
    for (int i = amounti; i < n - amounti; i++)
    {
        sumv += v[i];
        num++;
    }
    if (num == 0)
    {
        cout << 0;
        return;
    }
    cout << round((double)sumv / num);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}