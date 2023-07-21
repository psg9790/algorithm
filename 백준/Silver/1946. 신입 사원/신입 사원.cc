#include <bits/stdc++.h>
using namespace std;
using ip = pair<int, int>;

struct RankCmp
{
    bool operator()(const ip &a, const ip &b)
    {
        return a.first < b.first;
    }
};

int t;
int n;
vector<ip> ranks;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        ranks.clear();

        while (n--)
        {
            int aRank, bRank;
            cin >> aRank >> bRank;
            ranks.push_back({aRank, bRank});
        }

        sort(ranks.begin(), ranks.end(), RankCmp());

        int result = 0;
        int upperBound = ranks.size() + 1;
        for (int i = 0; i < ranks.size(); i++)
        {
            if (ranks[i].second < upperBound)
            {
                upperBound = ranks[i].second;
                result++;
            }
        }
        cout << result << '\n';
    }
}