#include <bits/stdc++.h>
using namespace std;

int t;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ants(m);
    for (int i = 0; i < m; i++)
        cin >> ants[i];
    sort(ants.begin(), ants.end());

    int fastest = 0, slowest = 0;
    for (auto i : ants)
    {
        fastest = max(fastest, min(i - 0, n - i));
        slowest = max(slowest, max(i - 0, n - i));
    }

    cout << fastest << ' ' << slowest << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        solve();
    }
}