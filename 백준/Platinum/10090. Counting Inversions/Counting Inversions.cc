#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ip = pair<int,int>;
using ll = long long;

int n;
vector<ip> idxMap;
vector<int> tree;

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
        + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int tgt)
{
    if(tl == tr)
    {
        tree[v]++;
        return;
    }
    int tm = (tl + tr) / 2;
    if(tgt <= tm)
        update(v*2, tl, tm, tgt);
    else
        update(v*2+1, tm+1, tr, tgt);
    tree[v] = tree[v*2] + tree[v*2+1];
}

void solve()
{
    cin >> n;

    tree.resize(n*4, 0);

    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        idxMap.push_back({token-1, i});
    }
    sort(idxMap.begin(), idxMap.end());

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += query(1, 0, n-1, idxMap[i].second + 1, n - 1);
        update(1, 0, n-1, idxMap[i].second);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}