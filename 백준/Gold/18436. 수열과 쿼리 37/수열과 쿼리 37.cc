#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ip = pair<int,int>;

int n, m;
vector<ip> tree;
const int MAXN = 100'000;

void build(vector<int> &arr, int v, int tl, int tr)
{
    if(tl == tr)
    {
        if(arr[tl] % 2 == 0)
            tree[v] = {0, 1};
        else
            tree[v] = {1, 0};
        return;
    }
    int tm = (tl + tr) / 2;
    build(arr, v*2, tl, tm);
    build(arr, v*2+1, tm+1, tr);
    tree[v] = { tree[v*2].first + tree[v*2+1].first, tree[v*2].second + tree[v*2+1].second };
    //cout << "v: " << v << " odd: " << tree[v].first << " even: " << tree[v].second << '\n';
}

ip query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return {0, 0};
    if(l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    ip q1 = query(v*2, tl, tm, l, min(r, tm));
    ip q2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return { q1.first + q2.first, q1.second + q2.second };
}

void update(int v, int tl, int tr, int tgt, int tgtVal)
{
    if(tl == tr)
    {
        
        if(tgtVal % 2 == 0)
            tree[v] = {0, 1};
        else
            tree[v] = {1, 0};
        return;
    }
    int tm = (tl + tr) / 2;
    if(tgt <= tm)
    {
        update(v*2, tl, tm, tgt, tgtVal);
    }
    else
    {
        update(v*2+1, tm+1, tr, tgt, tgtVal);
    }
    tree[v] = { tree[v*2].first + tree[v*2+1].first, tree[v*2].second + tree[v*2+1].second };
}

void solve()
{
    // 초기화
    tree.resize(MAXN * 4);

    vector<int> arr;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int token;
        cin >> token;
        arr.push_back(token);
    }
    // 트리 생성
    build(arr, 1, 0, n-1);

    cin >> m;
    for(int i = 0 ; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)  // update
        {
            update(1, 0, n-1, b-1, c);
        }
        else if(a == 2)     // even
        {
            cout << query(1, 0, n-1, b-1, c-1).second << '\n';
        }
        else if(a == 3)     // odd
        {
            cout << query(1, 0, n-1, b-1, c-1).first << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}