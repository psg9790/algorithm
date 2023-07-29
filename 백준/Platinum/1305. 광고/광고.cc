#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
string s;
vector<int> pi;
int prefix_function()
{
    pi.clear();
    pi.assign(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && (s[i] != s[j]))
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    // for (auto i : pi)
    //     cout << i << ' ';
    // cout << '\n';

    return n - pi[n - 1];
}

void solve()
{
    cin >> n >> s;
    pi.resize(n);

    cout << prefix_function() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}