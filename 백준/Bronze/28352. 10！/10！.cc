#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> divs;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    divs.push_back(7);

    divs.push_back(2);
    divs.push_back(2);
    divs.push_back(2);
    divs.push_back(3);

    divs.push_back(3);
    divs.push_back(2);
    divs.push_back(2);
    divs.push_back(5);

    divs.push_back(3);
    divs.push_back(2);
    divs.push_back(2);
    divs.push_back(5);

    int n;
    cin >> n;
    ll result = 1;
    for (int i = n; i > 0; i--)
    {
        result *= i;
        for (int j = 0; j < divs.size(); j++)
        {
            if (result % divs[j] == 0)
            {
                result /= divs[j];
                divs.erase(divs.begin() + j);
                j = j - 1;
            }
        }
    }
    cout << result << '\n';
}