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
    int OppositeDir();
    Robot(int y, int x, int d) : pos({y, x}), dir(d) {}
};
Robot *robot;
int result = 0;

void PrintArr()
{
    cout << "=============\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (robot->pos.first == i &&
                robot->pos.second == j)
            {
                if (robot->dir == 0)
                {
                    cout << "^ ";
                }
                else if (robot->dir == 1)
                {
                    cout << "> ";
                }
                else if (robot->dir == 2)
                {
                    cout << "v ";
                }
                else if (robot->dir == 3)
                {
                    cout << "< ";
                }
                continue;
            }
            else if (v[i][j])
            {
                cout << 'C' << ' ';
                continue;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

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
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // PrintArr();
    while (robot->Move())
    {
        // cout << robot->dir << '\n';
        // PrintArr();
        // cout << robot->pos.first << ' ' << robot->pos.second << ' ' << robot->dir << '\n';
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

    int opposite = OppositeDir();
    int yy = pos.first + dy[opposite];
    int xx = pos.second + dx[opposite];
    if (arr[yy][xx] != 1)
    {
        pos = {yy, xx};
        return true;
    }

    return false;
}
int Robot::OppositeDir()
{
    if (dir == 0)
    {
        return 2;
    }
    else if (dir == 1)
    {
        return 3;
    }
    else if (dir == 2)
    {
        return 0;
    }
    else if (dir == 3)
    {
        return 1;
    }
}