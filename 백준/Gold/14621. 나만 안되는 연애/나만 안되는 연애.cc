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

class option
{
public:
    option(int _s, int _e, int _x) : s(_s), e(_e), x(_x) {}
    int s, e, x;
};

struct pqcmp
{
    bool operator()(const option *a, const option *b)
    {
        return a->x > b->x;
    }
};

int n, m;
vector<char> univS;
priority_queue<option *, vector<option *>, pqcmp> pq;
vector<int> t;
int find(int idx)
{
    if (t[idx] == idx)
        return idx;
    return t[idx] = find(t[idx]);
}
bool isUnion(int lhv, int rhv)
{
    return find(lhv) == find(rhv);
}
void doUnion(int lhv, int rhv)
{
    t[find(lhv)] = find(rhv);
}

void solve()
{
    cin >> n >> m;
    univS.push_back('B'); // 인덱스 조절용 더미
    for (int i = 0; i < n; i++)
    {
        char sex;
        cin >> sex;
        univS.push_back(sex);
    }

    for (int i = 0; i < m; i++)
    {
        int s, e, x;
        cin >> s >> e >> x;
        pq.push(new option(s, e, x));
    }

    t.resize(n + 1); // union 초기화
    for (int i = 0; i < n; i++)
        t[i] = i;
    int ans = 0;
    while (!pq.empty()) // 최소경로 탐색
    {
        option *frt = pq.top();
        pq.pop();

        if (univS[frt->s] == univS[frt->e]) // 같은 성별끼리 케이스 제외
            continue;

        if (!isUnion(frt->s, frt->e)) // 새로운 최소 경로
        {
            debug(frt->s, frt->e, frt->x);
            doUnion(frt->s, frt->e);
            ans += frt->x;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!isUnion(1, i))
        {
            cout << -1 << '\n';
            return;
        }
    }
    debug(t);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}