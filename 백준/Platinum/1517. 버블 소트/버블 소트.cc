#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ip = pair<int,int>;
using ll = long long;

int n;
vector<int> tree;
vector<ip> idxMap;

void printTree()
{
    cout << "====================\n";
    for(int i = 0 ; i < n*4 ; i++)
    {
        cout << "v: " << i << " val: " << tree[i] << '\n';
    }
    cout << "====================\n";
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return (ll)tree[v];
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int tgt)
{
    if(tl == tr)
    {
        tree[v] = 1;
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
    tree.resize(n * 4);
    for(int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        idxMap.push_back({token, i});
    }
    sort(idxMap.begin(), idxMap.end());

    ll ans = 0;
    for(int i = 0; i < idxMap.size(); i++)
    {
        ans += query(1, 0, n-1, idxMap[i].second + 1, n-1);
        update(1, 0, n - 1, idxMap[i].second);

        // cout << "item: " << idxMap[i].first << " mapped: " << idxMap[i].second << " ans: " << ans << '\n';
        // cout << "get " << idxMap[i].second + 1 << " ~ " << n-1 << '\n';
        // cout << "inserted: " << idxMap[i].second << '\n';
        // cout << "-------------\n";
        // printTree();
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}