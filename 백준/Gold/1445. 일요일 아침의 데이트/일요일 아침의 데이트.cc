#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n, m;
vector<vector<char>> v;
vector<vector<bool>> visited;
ip src, dest;

class path
{
public:
    path(ip _pos, int _garbage, int _near, int _dist) : pos(_pos), garbage(_garbage), near(_near), dist(_dist) {}
    ip pos;
    int garbage, near;
    int dist;
};

struct pathCmp
{
    bool operator()(const path *a, const path *b)
    {
        if (a->garbage == b->garbage)
            return a->near > b->near;
        return a->garbage > b->garbage;
    }
};

int findNear(ip pos)
{
    for (int i = 0; i < 4; i++)
    {
        int yy = pos.first + dy[i];
        int xx = pos.second + dx[i];
        if (yy < 0 || yy >= n || xx < 0 || xx >= m)
            continue;
        if (v[yy][xx] == 'g')
            return true;
    }
    return false;
}

int hue(ip pos)
{
    return abs(pos.first - dest.first) + abs(pos.second - dest.second);
}

path *bfs()
{
    priority_queue<path *, vector<path *>, pathCmp> pq;
    visited.assign(n, vector<bool>(m, false));
    visited[src.first][src.second] = true;
    pq.push(new path(src, 0, 0, hue(src)));

    while (!pq.empty())
    {
        path *frt = pq.top();
        pq.pop();

        int y = frt->pos.first;
        int x = frt->pos.second;
        if (y == dest.first && x == dest.second)
            return frt;

        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy < 0 || yy >= n || xx < 0 || xx >= m)
                continue;
            if (visited[yy][xx])
                continue;

            visited[yy][xx] = true;
            pq.push(new path({yy, xx},
                             (v[yy][xx] == 'g' ? frt->garbage + 1 : frt->garbage),
                             (v[yy][xx] == '.' ? (findNear({yy, xx}) ? frt->near + 1 : frt->near) : frt->near),
                             hue({yy, xx})));
        }
    }

    return nullptr;
}

void solve()
{
    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            v[i].push_back(str[j]);
            if (v[i][j] == 'S')
            {
                src = {i, j};
            }
            if (v[i][j] == 'F')
            {
                dest = {i, j};
            }
        }
    }

    path *rst = bfs();

    cout << rst->garbage << ' ' << rst->near << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}