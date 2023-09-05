#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int n;
string str1, str2; // s1 to s2
int i1, i2;
vector<bool> used(2, false);
bool appeared = false;
int z1, z2;

void solve()
{
    cin >> n;
    cin >> str1 >> str2;
    cin >> i1 >> i2;

    for (auto i : str1)
        if (i == 'o')
            z1++;

    for (auto i : str2)
        if (i == 'o')
            z2++;

    if (z1 != z2)
    {
        cout << "NO" << '\n';
        return;
    }

    int ptr1 = 0;
    int ptr2 = 0;

    while (ptr1 < n && ptr2 < n)
    {
        if (!appeared && str1[i1] == str2[ptr2])
        {
            appeared = true;
            debug(appeared, str1[i1]);
        }
        if (ptr1 == i1 || ptr1 == i2) // skip
        {
            debug(ptr1, "skip");
            ptr1++;
            continue;
        }
        debug(ptr1, ptr2, str1[ptr1], str2[ptr2]);

        if (str1[ptr1] == str2[ptr2])
        {
            ptr1++;
            ptr2++;
            continue;
        }

        // if different

        // check two block
        if (used[0] == false) // use block 0
        {
            if (str1[i1] == str2[ptr2]) // success
            {
                debug("use 0");
                ptr2++;
                used[0] = true;
                continue;
            }
            else // fail
            {
                // one chance
                if (appeared == true)
                {
                    if (str1[i2] == str2[ptr2])
                    {
                        debug("hack 1");
                        ptr2++;
                        used[0] = true;
                        used[1] = true;
                        continue;
                    }
                }
                cout << "NO" << '\n';
                return;
            }
        }
        else if (used[1] == false) // use block 1
        {
            if (str1[i2] == str2[ptr2])
            {
                debug("use 1");
                ptr2++;
                used[1] = true;
                continue;
            }
            else // fail
            {
                cout << "NO" << '\n';
                return;
            }
        }
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }

    // if not used every block

    // check first or last
    bool fst = true, lst = true;
    if (used[1] == false)
    {
        if (str1[i2] != str2[n - 1])
        {
            lst = false;
        }
        if (str1[i2] != str2[1])
        {
            fst = false;
        }
    }
    if (used[0] == false)
    {
        if (str1[i1] != str2[n - 2])
        {
            lst = false;
        }
        if (str1[i1] != str2[0])
        {
            fst = false;
        }
    }

    if (!fst && !lst)
    {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}