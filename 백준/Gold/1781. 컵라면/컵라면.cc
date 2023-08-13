#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
class prob
{
public:
    prob(int _n, int _d, int _c) : num(_n), dead(_d), cup(_c) {}
    int num, dead, cup;
};
struct probcmp
{
    bool operator()(const prob *a, const prob *b)
    {
        if (a->dead == b->dead)
            return a->cup < b->cup;
        return a->dead > b->dead;
    }
};

priority_queue<prob *, vector<prob *>, probcmp> pq;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d, c;
        cin >> d >> c;
        pq.push(new prob(i, d, c));
    }

    ll result = 0;
    int tt = 1;
    priority_queue<int, vector<int>, greater<int>> mem;
    while (!pq.empty())
    {
        prob *frt = pq.top();
        pq.pop();

        if (frt->dead >= tt)
        {
            result += frt->cup;
            mem.push(frt->cup);
            tt++;
        }

        else if (!mem.empty())
            if (mem.top() < frt->cup) // switch
            {
                result -= mem.top();
                result += frt->cup;
                mem.pop();
                mem.push(frt->cup);
            }
    }

    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}