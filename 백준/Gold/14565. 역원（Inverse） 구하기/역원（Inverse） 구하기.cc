#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

ll n, a;
ll gcd(ll _a, ll _b)
{
    ll div = _a % _b;
    if (div == 0)
        return _b;
    return gcd(_b, div);
}

ll exEuclid(ll _a, ll _b)
{
    vector<ll> s, t, r, q;
    s.push_back(1);
    s.push_back(0);
    t.push_back(0);
    t.push_back(1);
    r.push_back(_a);
    r.push_back(_b);

    while ((r[r.size() - 2] % r[r.size() - 1]) != 0)
    {
        q.push_back(r[r.size() - 2] / r[r.size() - 1]);
        r.push_back(r[r.size() - 2] % r[r.size() - 1]);
        s.push_back(s[s.size() - 2] - s[s.size() - 1] * q.back());
        t.push_back(t[t.size() - 2] - t[t.size() - 1] * q.back());
    }

    if (s.back() < 0)
        return s.back() + _b;
    return s.back();
}

void solve()
{
    cin >> n >> a;
    cout << n - a << ' ';

    ll _gcd = gcd(n, a);
    if (_gcd != (ll)1) // no ans
    {
        cout << -1 << '\n';
        return;
    }

    cout << exEuclid(a, n) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}