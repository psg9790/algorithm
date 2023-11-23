#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using ip = pair<int, int>;

int n, m;
vector<ll> tree;
vector<ll> lazy;
vector<int> parent;

void printTree()
{
    cout << "====================\n";
    for (int i = 0; i < m * 4; i++)
    {
        cout << "tree v: " << i << " val: " << tree[i] << '\n';
    }
    for (int i = 0; i < m * 4; i++)
    {
        cout << "lazy v: " << i << " val: " << lazy[i] << '\n';
    }
    cout << "====================\n";
}

void push(int v, int s, int e)
{
    // lazy 요소 확인, leafNode들에 더한 값을 퉁쳤다는 가정이므로 (leafNode개수 * value)만큼 현재노드에 더해줌
    if (lazy[v] != 0)
    {
        tree[v] += lazy[v] * (e - s + 1);
        if (s != e)
        {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void update(int v, int s, int e, int l, int r, int tgtVal)
{
    push(v, s, e);
    if (l > e || r < s)
        return;
    if (l <= s && e <= r) // 범위를 좁히다가, 감싸는 형태가 되면 lazy에 저장
    {
        tree[v] += tgtVal * (e - s + 1);
        if (s != e) // 하위노드가 있으므로 lazy 계승
        {
            lazy[v * 2] += tgtVal;
            lazy[v * 2 + 1] += tgtVal;
        }
        return;
    }
    int tm = (s + e) / 2;
    update(v * 2, s, tm, l, r, tgtVal);
    update(v * 2 + 1, tm + 1, e, l, r, tgtVal);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

ll query(int v, int s, int e, int l, int r)
{
    push(v, s, e);
    if (l > e || r < s)
        return 0;
    if (l <= s && e <= r)
    {
        return tree[v];
    }
    int tm = (s + e) / 2;
    return query(v * 2, s, tm, l, r) + query(v * 2 + 1, tm + 1, e, l, r);
}

void solve()
{
    cin >> n >> m;
    tree.resize(m * 4, 0);
    lazy.resize(m * 4, 0);
    parent.resize(n, -1);

    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, c = 0;

        cin >> a >> b >> c;
        update(1, 0, m - 1, i, i, c);
        for (int j = a - 1; j <= b - 1; j++)
            parent[j] = i;
    }
    // printTree();

    while (true)
    {
        int token;
        cin >> token;
        if (token == 1) // 확인
        {
            int a, b;
            cin >> a >> b;
            ll ans = 0;
            int prev = -1;
            if (a <= b)
            {
                ans += query(1, 0, m - 1, parent[a - 1], parent[b - 1]);
            }
            else
            {
                ans += query(1, 0, m - 1, 0, parent[b - 1]);
                ans += query(1, 0, m - 1, parent[a - 1], m - 1);
            }
            cout << ans << '\n';
        }
        else if (token == 2) // 저장
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (a <= b) // 초기 값 저장
            {

                update(1, 0, m - 1, parent[a - 1], parent[b - 1], c);
            }
            else
            {
                update(1, 0, m - 1, parent[a - 1], m - 1, c);
                update(1, 0, m - 1, 0, parent[b - 1], c);
            }
        }
        else if (token == 0)
        {
            cin >> token >> token;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}