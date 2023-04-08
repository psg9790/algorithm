#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ip = pair<int, int>;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n, m;
vector<vector<int>> arr;
vector<ip> chickenHouses;
vector<ip> chosen;
int RESULT = INT32_MAX;

void BackTracking(int lastidx)
{
    if (chosen.size() == m)
    {
        queue<ip> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (auto x : chosen)
        {
            q.push({x.first, x.second});
            visited[x.first][x.second] = true;
        }

        int lev = 1;
        int rst = 0;
        while (!q.empty())
        {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++)
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
                        visited[yy][xx] = true;
                        q.push({yy, xx});
                        if (arr[yy][xx] == 1)
                        {
                            rst += lev;
                        }
                    }
                }
            }
            lev++;
        }
        if (RESULT > rst)
        {
            RESULT = rst;
        }
        return;
    }
    if (chosen.size() == 0)
    {
        for (int i = 0; i < chickenHouses.size(); i++)
        {
            chosen.push_back(chickenHouses[i]);
            BackTracking(i);
            chosen.pop_back();
        }
    }
    else
    {
        for (int i = lastidx + 1; i < chickenHouses.size(); i++)
        {
            chosen.push_back(chickenHouses[i]);
            BackTracking(i);
            chosen.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                chickenHouses.push_back({i, j});
            }
        }
    }
    BackTracking(0);
    cout << RESULT;
}