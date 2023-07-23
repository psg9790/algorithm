#include <bits/stdc++.h>
using namespace std;

vector<int> target = {202021, 20202021, 202002021, 202012021, 202022021, 202032021, 202042021, 202052021, 202062021, 202072021, 202082021, 202092021};

void solve()
{
    int n;
    long result = 0;
    vector<int> nums;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        nums.push_back(token);
    }

    sort(nums.begin(), nums.end());

    for (int j = 0; j < nums.size(); j++)
    {
        for (int i = 0; i < 12; i++)
        {
            int targetSize = target[i] - nums[j];
            if (targetSize > nums[j])
                break;
            result += upper_bound(nums.begin(), nums.end(), targetSize) - lower_bound(nums.begin(), nums.end(), targetSize);
        }
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}