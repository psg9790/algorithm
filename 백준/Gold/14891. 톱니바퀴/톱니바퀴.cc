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

vector<string> t(5);
int n;

void clockwise(int tgt)
{
    char temp = t[tgt][t[tgt].length() - 1];
    for (int i = t[tgt].length() - 2; i >= 0; i--)
    {
        t[tgt][i + 1] = t[tgt][i];
    }
    t[tgt][0] = temp;
}

void nonclockwise(int tgt)
{
    char temp = t[tgt][0];
    for (int i = 0; i < t[tgt].length() - 1; i++)
    {
        t[tgt][i] = t[tgt][i + 1];
    }
    t[tgt][t[tgt].length() - 1] = temp;
}

void Simulate(int tgt, int dir)
{
    vector<int> turn(5, 0);
    turn[tgt] = dir;
    queue<int> q;
    q.push(tgt);
    while (!q.empty())
    {
        int frt = q.front();
        q.pop();
        if (frt - 1 >= 1)
        {
            // lft compare
            if (turn[frt - 1] == 0)
                if (t[frt - 1][2] != t[frt][6])
                {
                    turn[frt - 1] = (turn[frt] == 1 ? -1 : 1);
                    q.push(frt - 1);
                }
        }

        if (frt + 1 <= 4)
        {
            // rgt compare
            if (turn[frt + 1] == 0)
                if (t[frt + 1][6] != t[frt][2])
                {
                    turn[frt + 1] = (turn[frt] == 1 ? -1 : 1);
                    q.push(frt + 1);
                }
        }
    }
    debug(turn);

    for (int i = 1; i <= 4; i++)
    {
        if (turn[i] == 1)
        {
            clockwise(i);
        }
        else if (turn[i] == -1)
        {
            nonclockwise(i);
        }
    }
    debug(t);
}

void solve()
{
    cin >> t[1] >> t[2] >> t[3] >> t[4];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tgt, dir;
        cin >> tgt >> dir;
        Simulate(tgt, dir);
    }
    int ans = 0;
    if (t[1][0] == '1')
        ans += 1;
    if (t[2][0] == '1')
        ans += 2;
    if (t[3][0] == '1')
        ans += 4;
    if (t[4][0] == '1')
        ans += 8;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}