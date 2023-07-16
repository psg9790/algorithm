#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;
int m;

vector<vector<int>> adjs;
vector<int> visited;

int bfs()
{
    visited[a] = 0;
    queue<int> q;
    for (auto i : adjs[a])
    {
        if (visited[a] + 1 < visited[i])
        {
            visited[i] = visited[a] + 1;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int frt = q.front();
        q.pop();

        for (auto i : adjs[frt])
        {
            if (visited[frt] + 1 < visited[i])
            {
                visited[i] = visited[frt] + 1;
                q.push(i);
            }
            if (i == b)
            {
                return visited[i];
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    cin >> m;

    adjs.resize(n + 1);
    visited.resize(n + 1, INT32_MAX);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjs[x].push_back(y);
        adjs[y].push_back(x);
    }

    cout << bfs();
}