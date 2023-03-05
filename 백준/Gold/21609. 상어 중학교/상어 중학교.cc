#include <bits/stdc++.h>
using namespace std;

using ip = pair<int, int>;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n, m;
int arr[21][21];
int score = 0;
const int delbit = -9;
void PrintArr()
{
    cout << "==================\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == delbit)
            {
                cout << 'x' << ' ';
                continue;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

class Data
{
public:
    ip pos;
    int type;
    vector<ip> rainbows;
    vector<ip> types;
    Data(ip _pos, int _type) : pos(_pos), type(_type) {}
};
struct pqcmp
{
    bool operator()(Data *a, Data *b)
    {
        if (a->types.size() + a->rainbows.size() == b->types.size() + b->rainbows.size())
        {
            if (a->rainbows.size() == b->rainbows.size())
            {
                if (a->pos.first == b->pos.first)
                {
                    return a->pos.second < b->pos.second;
                }
                return a->pos.first < b->pos.first;
            }
            return a->rainbows.size() < b->rainbows.size();
        }
        return a->types.size() + a->rainbows.size() < b->types.size() + b->rainbows.size();
    }
};

bool simulate()
{
    priority_queue<Data *, vector<Data *>, pqcmp> pq;
    bool v[n + 1][n + 1] = {{false}};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] <= 0)
                continue;
            if (v[i][j])
                continue;

            queue<ip> q;
            Data *newdata = new Data({i, j}, arr[i][j]);
            newdata->types.push_back({i, j});
            q.push({i, j});
            v[i][j] = true;
            while (!q.empty())
            {
                ip frt = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int yy = frt.first + dy[k];
                    int xx = frt.second + dx[k];
                    if (yy<1 | yy> n | xx<1 | xx> n)
                        continue;
                    if (v[yy][xx])
                        continue;

                    if (arr[yy][xx] == 0)
                    {
                        v[yy][xx] = true;
                        q.push({yy, xx});
                        newdata->rainbows.push_back({yy, xx});
                    }
                    else if (arr[yy][xx] == newdata->type)
                    {
                        v[yy][xx] = true;
                        q.push({yy, xx});
                        newdata->types.push_back({yy, xx});
                    }
                }
            }
            // 무지개 타일 rollback
            for (int r = 0; r < newdata->rainbows.size(); r++)
            {
                ip tgt = newdata->rainbows[r];
                v[tgt.first][tgt.second] = false;
            }
            pq.push(newdata);
        }
    }
    if (pq.empty())
    {
        return false;
    }
    Data *block = pq.top();
    int earned = block->types.size() + block->rainbows.size();
    if (earned < 2)
    {
        return false;
    }
    earned *= earned;
    score += earned;
    for (int i = 0; i < block->types.size(); i++)
    {
        ip tgt = block->types[i];
        arr[tgt.first][tgt.second] = delbit;
    }
    for (int i = 0; i < block->rainbows.size(); i++)
    {
        ip tgt = block->rainbows[i];
        arr[tgt.first][tgt.second] = delbit;
    }
    return true;
}

void gravity()
{
    for (int x = 1; x <= n; x++)
    {
        for (int y = n; y >= 1; y--)
        {
            if (arr[y][x] >= 0)
            {
                ip tgt = {y, x};
                while (true)
                {
                    if (tgt.first + 1 > n)
                        break;

                    if (arr[tgt.first + 1][tgt.second] == delbit)
                    {
                        tgt = {tgt.first + 1, tgt.second};
                    }
                    else
                    {
                        break;
                    }
                }
                // swap
                int ins = arr[tgt.first][tgt.second];
                arr[tgt.first][tgt.second] = arr[y][x];
                arr[y][x] = ins;
            }
        }
    }
}
void reverse_clockwise()
{
    int narr[n + 1][n + 1];
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            narr[n + 1 - x][y] = arr[y][x];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = narr[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (simulate())
    {
        // 중력
        gravity();
        // 반시계
        reverse_clockwise();

        // 중력
        gravity();
        // PrintArr();
    }

    cout << score << '\n';
}