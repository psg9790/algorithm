#include <iostream>
#include <vector>
using namespace std;
using ip = pair<int, int>;

const int dy[5] = {0, 0, 0, -1, 1};
const int dx[5] = {0, 1, -1, 0, 0};
int n, m, t;
struct Dice
{
    ip pos;
    int U = 0;
    int D = 0;
    int L = 0;
    int R = 0;
    int F = 0;
    int B = 0;
    void RollFront();
    void RollBack();
    void RollLeft();
    void RollRight();
};

int arr[20][20];
Dice *dice = new Dice();
vector<int> result;

void Simulation(int dir)
{
    int yy = dice->pos.first + dy[dir];
    int xx = dice->pos.second + dx[dir];
    if (yy < 0 | yy >= n | xx < 0 | xx >= m)
    {
        return;
    }
    dice->pos = {yy, xx};

    switch (dir)
    {
    case 1:
        dice->RollRight();
        break;

    case 2:
        dice->RollLeft();
        break;

    case 3:
        dice->RollFront();
        break;

    case 4:
        dice->RollBack();
        break;
    }

    if (arr[dice->pos.first][dice->pos.second] == 0)
    {
        arr[dice->pos.first][dice->pos.second] = dice->D;
    }
    else
    {
        dice->D = arr[dice->pos.first][dice->pos.second];
        arr[dice->pos.first][dice->pos.second] = 0;
    }

    result.push_back(dice->U);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dicey, dicex;
    cin >> n >> m >> dicey >> dicex >> t;
    dice->pos = {dicey, dicex};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        int token;
        cin >> token;
        Simulation(token);
    }

    for (auto x : result)
    {
        cout << x << '\n';
    }
}

void Dice::RollFront()
{
    int ins = dice->U;
    dice->U = dice->B;
    dice->B = dice->D;
    dice->D = dice->F;
    dice->F = ins;
}

void Dice::RollBack()
{
    int ins = dice->U;
    dice->U = dice->F;
    dice->F = dice->D;
    dice->D = dice->B;
    dice->B = ins;
}

void Dice::RollLeft()
{
    int ins = dice->U;
    dice->U = dice->R;
    dice->R = dice->D;
    dice->D = dice->L;
    dice->L = ins;
}

void Dice::RollRight()
{
    int ins = dice->U;
    dice->U = dice->L;
    dice->L = dice->D;
    dice->D = dice->R;
    dice->R = ins;
}