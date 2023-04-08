#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ip = pair<int, int>;
using iip = pair<ip, int>;

int n, m;
vector<int> p;

int find(int x)
{
    if (x == p[x])
    {
        return x;
    }
    return p[x] = find(p[x]);
}

void Union(int a, int b)
{
    p[find(a)] = find(b);
}

bool isUnion(int a, int b)
{
    return find(a) == find(b);
}

struct pqcmp
{
    bool operator()(iip a, iip b)
    {
        return a.second > b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }

    priority_queue<iip, vector<iip>, pqcmp> pq;
    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        pq.push({{s, e}, c});
    }

    int rst = 0;
    while (!pq.empty())
    {
        int a = pq.top().first.first;
        int b = pq.top().first.second;
        int c = pq.top().second;
        pq.pop();

        if (!isUnion(a, b))
        {
            Union(a, b);
            rst += c;
        }
    }
    cout << rst;
}