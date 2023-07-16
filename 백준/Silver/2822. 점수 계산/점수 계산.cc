#include <bits/stdc++.h>
using namespace std;

using ip = pair<int, int>;
struct ipcmp
{
    bool operator()(const ip &a, const ip &b)
    {
        return a.first > b.first;
    }
};
vector<ip> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 8; i++)
    {
        int token;
        cin >> token;
        v.push_back({token, i});
    }

    sort(v.begin(), v.end(), ipcmp());

    int sum = 0;
    vector<int> res;
    for (int i = 0; i < 5; i++)
    {
        sum += v[i].first;
        res.push_back(v[i].second);
    }
    sort(res.begin(), res.end());

    cout << sum << '\n';
    for (auto i : res)
        cout << i << ' ';
}
