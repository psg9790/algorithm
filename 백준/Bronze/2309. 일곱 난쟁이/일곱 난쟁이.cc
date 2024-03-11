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

int t = 9;
vector<int> arr;

void solve()
{
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (i == j)
                continue;
            int sumv = 0;
            for (int k = 0; k < t; k++)
            {
                if (k != i && k != j)
                {
                    sumv += arr[k];
                }
            }
            if (sumv == 100)
            {
                for (int k = 0; k < t; k++)
                {
                    if (k != i && k != j)
                    {
                        cout << arr[k] << '\n';
                    }
                }
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < t; i++)
    {
        int token;
        cin >> token;
        arr.push_back(token);
    }
    sort(arr.begin(), arr.end());
    solve();
}