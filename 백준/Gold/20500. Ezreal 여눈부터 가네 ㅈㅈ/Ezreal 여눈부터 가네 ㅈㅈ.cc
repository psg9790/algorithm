#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull MOD = 1e9 + 7;

ull n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ull nVal = 0;
    for (ull i = 1; i < n; i++)
    {
        if (i % 2 == 1) // odd
        {
            nVal = (nVal + nVal + 1) % MOD;
        }
        else // even
        {
            nVal = (nVal + nVal - 1) % MOD;
        }
    }
    cout << nVal << '\n';
}
