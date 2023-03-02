#include <iostream>
#include <algorithm>
#include <deque>
#include <tuple>
#include <set>
using namespace std;
#define ip pair<int, int>
#define dtuple tuple<ip, int, int, int>

int n, m, k;
int INF = 10'000'000;
int rst = INF;
int arr[1'001][1'001];
bool visited[4][1'001][1'001] = {
    {
        {
            false,
        },
    },
};

ip startPos;
ip endPos;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int BannedDir(int dir)
{
    if (dir == 0)
        return 1;
    else if (dir == 1)
        return 0;
    else if (dir == 2)
        return 3;
    else if (dir == 3)
        return 2;

    return dir;
}

// 길이 막힐 수도 있을것 같음
int BFS()
{
    // 좌표, 이전 이동 방향
    deque<dtuple> q;
    q.push_back({startPos, -1, 0, 0});

    int rst = 0;
    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            ip pos;
            int banDir, prev, pprev;
            tie(pos, banDir, prev, pprev) = q.front();
            q.pop_front();

            // 도착
            if (pos.first == endPos.first &
                pos.second == endPos.second)
            {
                return rst;
            }

            banDir = BannedDir(banDir);
            for (int j = 0; j < 4; j++)
            {
                // 되돌아가기 x
                if (j == banDir)
                    continue;

                int yy = pos.first + dy[j];
                int xx = pos.second + dx[j];

                if (yy >= 1 & yy <= n & xx >= 1 & xx <= m)
                {
                    if (arr[yy][xx] != -1)
                    {
                        // 지난 세번의 움직임 합 확인
                        if (arr[yy][xx] + prev + pprev <= k)
                        {
                            // 방문했는지 확인
                            if (!visited[j][yy][xx])
                            {
                                visited[j][yy][xx] = true;
                                q.push_back({{yy, xx}, j, arr[yy][xx], prev});
                            }
                        }
                    }
                }
            }
        }
        rst++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= m; j++)
        {
            if (line[j - 1] - 'A' >= 0 & line[j - 1] - 'A' <= 26)
            {
                arr[i][j] = 0;

                if (line[j - 1] == 'S')
                    startPos = {i, j};
                else if (line[j - 1] == 'H')
                    endPos = {i, j};
                else if (line[j - 1] == 'X')
                    arr[i][j] = -1;
            }
            else
            {
                arr[i][j] = line[j - 1] - '0';
            }
        }
    }
    cout << BFS() << '\n';
}