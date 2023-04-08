#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

int n;
vector<vector<int>> arr;
vector<int> groupA;
int mnv = INT32_MAX;

void BackTracking()
{
    if (groupA.size() == n / 2)
    {
        set<int> groupAset(groupA.begin(), groupA.end());
        int sizeA = 0;
        for (int i = 0; i < n / 2 - 1; i++)
        {
            for (int j = i + 1; j < n / 2; j++)
            {
                sizeA += arr[groupA[i]][groupA[j]];
                sizeA += arr[groupA[j]][groupA[i]];
            }
        }
        int sizeB = 0;
        vector<int> groupB;
        for (int i = 0; i < n; i++)
        {
            if (groupAset.find(i) == groupAset.end())
            {
                groupB.push_back(i);
            }
        }
        for (int i = 0; i < n / 2 - 1; i++)
        {
            for (int j = i + 1; j < n / 2; j++)
            {
                sizeB += arr[groupB[i]][groupB[j]];
                sizeB += arr[groupB[j]][groupB[i]];
            }
        }
        int diff = abs(sizeA - sizeB);
        if (diff < mnv)
        {
            mnv = diff;
        }
        return;
    }

    if (groupA.size() == 0)
    {
        for (int i = 0; i < n; i++)
        {
            groupA.push_back(i);
            BackTracking();
            groupA.pop_back();
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (*(groupA.end() - 1) < i)
            {
                groupA.push_back(i);
                BackTracking();
                groupA.pop_back();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    arr.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    BackTracking();
    cout << mnv << '\n';
}