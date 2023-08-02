#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using it = tuple<int, int, int>;

int n;
vector<int> mutalisk;

bool TryAddQueue(queue<vector<int>> &_q, const vector<int> &_frt, set<vector<int>> &_visited)
{
    vector<int> newOption(n);
    for (int opt1 = 0; opt1 < n; opt1++) // -9
    {
        newOption[opt1] = _frt[opt1] - 9;

        if (n == 1)
        {
            if (_visited.find(newOption) != _visited.end()) // already added
                continue;
            _visited.insert(newOption);
            _q.push(newOption);
            // isFinished
            bool isFinished = true;
            for (auto u : newOption)
                if (u > 0)
                    isFinished = false;
            if (isFinished)
                return true;
            continue;
        }

        for (int opt2 = 0; opt2 < n; opt2++) // -3
        {
            if (opt2 == opt1)
                continue;
            newOption[opt2] = _frt[opt2] - 3;

            if (n == 2)
            {
                if (_visited.find(newOption) != _visited.end()) // already added
                    continue;
                _visited.insert(newOption);
                swap(newOption[0], newOption[1]);
                _visited.insert(newOption);
                _q.push(newOption);
                // isFinished
                bool isFinished = true;
                for (auto u : newOption)
                    if (u > 0)
                        isFinished = false;
                if (isFinished)
                    return true;
                continue;
            }
            for (int opt3 = 0; opt3 < n; opt3++) // -1
            {
                if (opt3 == opt1 || opt3 == opt2)
                    continue;
                newOption[opt3] = _frt[opt3] - 1;

                if (_visited.find(newOption) != _visited.end()) // already added
                    continue;

                // for (auto u : _frt)
                //     cout << u << ' ';
                // cout << " -> ";
                // for (auto v : newOption)
                //     cout << v << ' ';
                // cout << '\n';

                vector<int> combi(n);
                for (int i = 0; i < n; i++)
                {
                    combi[i] = newOption[0];
                    for (int j = 0; j < n; j++)
                    {
                        if (i == j)
                            continue;
                        combi[j] = newOption[1];
                        for (int k = 0; k < n; k++)
                        {
                            if (k == i || k == j)
                                continue;
                            combi[k] = newOption[2];
                            _visited.insert(combi);
                        }
                    }
                }

                // isFinished
                bool isFinished = true;
                for (auto u : newOption)
                    if (u > 0)
                        isFinished = false;
                if (isFinished)
                    return true;

                _q.push(newOption);
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n;
    mutalisk.resize(n);
    for (int i = 0; i < n; i++)
        cin >> mutalisk[i];

    set<vector<int>> visited;
    queue<vector<int>> q;
    q.push(mutalisk);
    int level = 0;
    while (!q.empty())
    {
        // three options
        int qsize = q.size();
        level++;

        for (int i = 0; i < qsize; i++)
        {
            vector<int> frt = q.front();
            q.pop();

            if (TryAddQueue(q, frt, visited))
            {
                cout << level << '\n';
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}