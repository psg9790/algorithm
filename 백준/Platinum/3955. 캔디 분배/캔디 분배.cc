#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int k, c;

ll gcd(ll _a, ll _b)
{
    ll div = _a % _b;
    if (div == 0)
        return _b;
    return gcd(_b, div);
}
ll exEuclid(ll _a, ll _b)
{
    vector<int> s, t, r, q;
    s.push_back(1);
    s.push_back(0);
    t.push_back(0);
    t.push_back(1);
    r.push_back(_a);
    r.push_back(_b);

    while (r[r.size() - 2] % r[r.size() - 1] != 0)
    {
        q.push_back(r[r.size() - 2] / r[r.size() - 1]);
        r.push_back(r[r.size() - 2] % r[r.size() - 1]);
        s.push_back(s[s.size() - 2] - s[s.size() - 1] * q.back());
        t.push_back(t[t.size() - 2] - t[t.size() - 1] * q.back());
    }
    return (s.back() < 0) ? (s.back() + _b) : s.back();
}

void solve()
{
    cin >> k >> c;
    if (gcd(k, c) != 1) // impossible
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    if (c == 1)
    {
        if ((k / c + 1) > (ll)1e9)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << (k / c + 1) << '\n';
        return;
    }

    if (k == 1)
    {
        cout << 1 << '\n';
        return;
    }

    ll result = exEuclid(c, k);
    if (result > (ll)1e9)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << result << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}