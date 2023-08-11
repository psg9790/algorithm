#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<int> divs;
vector<ll> prefix;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    divs.assign(1'000'001, 0);
    for (int i = 1; i <= 1'000; i++)
    {
        for (int j = i; (j * i) <= 1'000'000; j++)
        {
            if (i == j)
                divs[j * i] += i;
            else
                divs[j * i] += (j + i);
        }
    }

    prefix.resize(1'000'001, 0);
    prefix[1] = 1;
    for (int i = 2; i <= 1'000'000; i++)
        prefix[i] = prefix[i - 1] + divs[i];

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << prefix[n] << '\n';
    }
}