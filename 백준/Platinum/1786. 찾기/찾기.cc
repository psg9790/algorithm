#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

vector<int> pi;

void prefix_function(string s)
{
    pi.clear();
    int n = s.length();
    pi.resize(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1]; // find matching prefix
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

vector<int> kmp(string t, string p)
{
    vector<int> result;
    int n = t.length(), m = p.length();
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
        {
            if (j == m - 1)
            {
                result.push_back(i - m + 2);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }

    return result;
}

void solve()
{
    string T, P;
    getline(cin, T);
    getline(cin, P);

    prefix_function(P);

    vector<int> result = kmp(T, P);
    cout << result.size() << '\n';
    for (auto i : result)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}