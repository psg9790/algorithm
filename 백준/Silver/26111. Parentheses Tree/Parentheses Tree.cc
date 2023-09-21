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

string str;
stack<char> stk;
int lvl = -1;
char lastCmd = '(';
ll ans = 0;
void solve()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            stk.push(str[i]);
            if (lastCmd == '(')
                lvl++;
        }
        else if (str[i] == ')')
        {
            if (lastCmd == ')')
                lvl--;
            debug(i, lvl);
            if (i - 1 >= 0 && str[i - 1] == '(')
                ans += (ll)lvl;
        }
        lastCmd = str[i];
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}