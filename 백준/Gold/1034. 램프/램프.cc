#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<string> lines;
vector<vector<int>> arr;
int k;
map<string, int> _map;

int countZeros(vector<vector<int>> &_arr, int ridx)
{
    int result = 0;
    for (int i = 0; i < m; i++)
        if (_arr[ridx][i] == 0)
            result++;
    return result;
}

int countWhole(vector<vector<int>> &_arr)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        bool good = true;
        for (int j = 0; j < m; j++)
            if (_arr[i][j] == 0)
                good = false;
        if (good)
            result++;
    }
    return result;
}

void convertColumns(vector<vector<int>> &_arr, int cidx)
{
    for (int i = 0; i < n; i++)
        if (_arr[i][cidx] == 1)
            _arr[i][cidx] = 0;
        else
            _arr[i][cidx] = 1;
}

void tryRows(int ridx)
{
    if (_map.find(lines[ridx]) != _map.end())
        return;

    int zeroCnt = countZeros(arr, ridx);
    if (((zeroCnt % 2) != (k % 2)) || (zeroCnt > k))
        return;

    vector<vector<int>> arr2 = arr;
    for (int i = 0; i < m; i++)
    {
        if (arr[ridx][i] == 0)
        {
            convertColumns(arr2, i);
        }
    }

    _map.insert({lines[ridx], countWhole(arr2)});
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        lines.push_back(line);
        for (int j = 0; j < m; j++)
            arr[i][j] = line[j] - '0';
    }
    cin >> k;

    for (int i = 0; i < n; i++) // for n rows
        tryRows(i);

    int ans = 0;
    for (auto i : _map)
        ans = max(ans, i.second);
    cout << ans << '\n';
}