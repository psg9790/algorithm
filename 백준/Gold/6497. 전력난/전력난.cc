#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ipp = pair<int, pair<int, int>>;

struct ippCmp
{
    bool operator()(const ipp &a, const ipp &b)
    {
        return a.first > b.first;
    }
};

priority_queue<ipp, vector<ipp>, ippCmp> pq;
vector<int> unionSet;

int find(int a)
{
    if (unionSet[a] == a)
        return a;
    return unionSet[a] = find(unionSet[a]);
}

bool isUnion(int a, int b)
{
    return find(a) == find(b);
}

void bindUnion(int a, int b)
{
    unionSet[find(a)] = find(b);
}

void solve(int n, int m)
{
    unionSet.clear();
    pq = priority_queue<ipp, vector<ipp>, ippCmp>();

    unionSet.resize(n);
    for (int i = 0; i < n; i++)
        unionSet[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }
    int saved = 0;

    while (!pq.empty())
    {
        ipp frt = pq.top();
        pq.pop();

        if (!isUnion(frt.second.first, frt.second.second))
        {
            bindUnion(frt.second.first, frt.second.second);
            // cout << "--- " << frt.second.first << ' ' << frt.second.second << '\n';
        }
        else
        {
            saved += frt.first;
            // cout << "+++ " << frt.second.first << ' ' << frt.second.second << '\n';
        }
    }
    cout << saved << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solve(n, m);
    }
}