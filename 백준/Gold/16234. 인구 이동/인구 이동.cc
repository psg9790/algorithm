#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ip = pair<int, int>;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n, l, r;
vector<vector<int>> arr;
int rst = 0;

bool Simulate()
{
    bool ret = false;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j])
            {
                continue;
            }
            queue<ip> q;
            vector<ip> unites;
            int unitesum = 0;

            visited[i][j] = true;
            unitesum += arr[i][j];
            q.push({i, j});
            unites.push_back({i, j});

            while (!q.empty())
            {
                ip frt = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int yy = frt.first + dy[k];
                    int xx = frt.second + dx[k];
                    if (yy < 0 || yy >= n || xx < 0 || xx >= n)
                    {
                        continue;
                    }
                    if (!visited[yy][xx])
                    {
                        int diff = abs(arr[frt.first][frt.second] - arr[yy][xx]);
                        if (diff >= l && diff <= r)
                        {
                            visited[yy][xx] = true;
                            unitesum += arr[yy][xx];
                            q.push({yy, xx});
                            unites.push_back({yy, xx});
                        }
                    }
                }
            }

            unitesum /= unites.size();
            for (auto x : unites)
            {
                if (arr[x.first][x.second] != unitesum)
                {
                    ret = true;
                    arr[x.first][x.second] = unitesum;
                }
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    arr.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (Simulate())
    {
        rst++;
    }
    cout << rst;
}