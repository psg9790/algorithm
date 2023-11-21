#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
const int MAXN = 100'000;
int minTree[MAXN * 4];
int maxTree[MAXN * 4];

void minBuild(int arr[], int v, int tl , int tr)
{
    if(tl == tr)
    {
        minTree[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        minBuild(arr, v*2, tl, tm);
        minBuild(arr, v*2+1, tm+1, tr);
        minTree[v] = min(minTree[v*2], minTree[v*2+1]);
    }
}
int minCalc(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return INT_MAX;
    if(l == tl && r == tr)
    {
        return minTree[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return min(minCalc(v*2, tl, tm, l, min(tm, r)),
            minCalc(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

void maxBuild(int arr[], int v, int tl, int tr)
{
    if(tl == tr)
    {
        maxTree[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        maxBuild(arr, v*2, tl, tm);
        maxBuild(arr, v*2+1, tm+1, tr);
        maxTree[v] = max(maxTree[v*2], maxTree[v*2+1]);
    }
}
int maxCalc(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
    {
        return maxTree[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return max(maxCalc(v*2, tl, tm, l, min(tm, r)),
            maxCalc(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

void solve()
{
    fill(&minTree[0], &minTree[MAXN * 4], INT_MAX);
    fill(&maxTree[0], &maxTree[MAXN * 4], 0);

    cin >> n >> m;

    // 입력
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        int token;
        cin >> token;
        arr[i] = token;
    }
    // 트리 초기화
    minBuild(arr, 1, 0, n-1);
    maxBuild(arr, 1, 0, n-1);

    for(int i = 0 ; i < m ; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << minCalc(1, 0, n-1, a-1, b-1) << ' ' << maxCalc(1, 0, n-1, a-1, b-1) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}