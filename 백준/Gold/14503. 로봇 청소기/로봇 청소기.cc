#include <iostream>
using namespace std;
using ip = pair<int, int>;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;
int arr[50][50];
bool v[50][50] = {false};

struct Robot
{
    ip pos;
    int dir;
    bool Move();
    Robot(int y, int x, int d) : pos({y, x}), dir(d) {}
};
Robot *robot;

int result = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int y, x, d;
    cin >> y >> x >> d;
    robot = new Robot(y, x, d);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    while (robot->Move())
    {
    }
    cout << result;
}

bool Robot::Move()
{
    if (!v[pos.first][pos.second])
    {
        v[pos.first][pos.second] = true;
        result++;
    }

    bool canMove = false;
    for (int i = 1; i <= 4; i++)
    {
        int _dir = dir - i;
        if (_dir < 0)
            _dir += 4;
        int yy = pos.first + dy[_dir];
        int xx = pos.second + dx[_dir];
        if (arr[yy][xx] != 1)
        {
            if (!v[yy][xx])
            {
                dir = _dir;
                pos = {yy, xx};
                return true;
            }
        }
    }

    int opposite = dir - 2;
    if (opposite < 0)
        opposite += 4;
    int yy = pos.first + dy[opposite];
    int xx = pos.second + dx[opposite];
    if (arr[yy][xx] != 1)
    {
        pos = {yy, xx};
        return true;
    }

    return false;
}