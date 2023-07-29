#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

string s;
vector<int> pi;

int prefix_function()
{
    int result = 0;
    int n = s.length();
    for (int cnt = 0; cnt < n; cnt++)
    {
        pi.clear();
        pi.assign(n - cnt, 0);
        for (int i = 1; i < n - cnt; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && (s[i + cnt] != s[j + cnt]))
                j = pi[j - 1];
            if (s[i + cnt] == s[j + cnt])
                j++;
            pi[i] = j;
            result = max(result, pi[i]);
        }
    }
    return result;
}

void solve()
{
    cin >> s;
    cout << prefix_function() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
