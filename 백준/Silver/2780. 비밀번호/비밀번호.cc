#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int t;
bool keypad[4][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 0, 0}};
vector<vector<vector<int>>> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        dp.resize(n, vector<vector<int>>(4, vector<int>(3, 1)));

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    int localSum = 0;
                    for (int idx = 0; idx < 4; idx++)
                    {
                        int yy = j + dy[idx];
                        int xx = k + dx[idx];
                        if (yy < 0 || yy >= 4 || xx < 0 || xx >= 3 || keypad[yy][xx] == false)
                            continue;
                        localSum = (localSum + dp[i - 1][yy][xx]) % 1'234'567;
                    }
                    dp[i][j][k] = localSum;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                if (keypad[i][j])
                    result = (result + dp[dp.size() - 1][i][j]) % 1'234'567;
        cout << result << '\n';
    }
}