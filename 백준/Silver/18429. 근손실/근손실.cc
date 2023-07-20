#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> kits;
int result = 0;

void BackTraking(int count, int curWeight, vector<bool> &visited)
{
    if (count == n)
    {
        result++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        if (curWeight + kits[i] - k < 500)
            continue;
        visited[i] = true;
        BackTraking(count + 1, curWeight + kits[i] - k, visited);
        visited[i] = false;
    }
}

void solve()
{
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (kits[i] - k < 0)
            continue;
        visited[i] = true;
        BackTraking(1, 500 + kits[i] - k, visited);
        visited[i] = false;
    }
}

int main()
{
    cin >> n >> k;
    kits.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        kits.push_back(token);
    }

    solve();
    cout << result << '\n';
}