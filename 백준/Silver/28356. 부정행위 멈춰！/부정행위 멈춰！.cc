#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> even({3, 2, 4, 2});
vector<int> odd({4, 1, 3, 1});

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if (n == 1 || m == 1)
    {
        cout << min(2, n * m) << '\n';
        vector<int> local({1, 2});
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << local[(i + j) % 2] << ' ';
            }
            cout << '\n';
        }
    }
    else
    {
        cout << 4 << '\n';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i % 2 == 0) // even
                    cout << even[j % 4] << ' ';
                else // odd
                    cout << odd[j % 4] << ' ';
            }
            cout << '\n';
        }
    }
}