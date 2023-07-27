#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int find(vector<int> &U, int idx)
{
    if (U[idx] == idx)
        return idx;
    return U[idx] = find(U, U[idx]);
}

bool isUnion(vector<int> &U, int idx1, int idx2)
{
    return find(U, idx1) == find(U, idx2);
}

void Unions(vector<int> &U, int idx1, int idx2)
{
    U[find(U, idx2)] = find(U, idx1);
}

void solve()
{
    int hashValue = 0;
    map<string, int> hash;

    int n;
    cin >> n;

    vector<int> U(2 * n, -1);
    vector<int> US(2 * n, 1);
    for (int i = 0; i < 2 * n; i++)
        U[i] = i;

    for (int i = 0; i < n; i++)
    {
        string astr, bstr;
        cin >> astr >> bstr;

        auto _iter = hash.find(astr);
        int aHash, bHash;
        if (_iter == hash.end())
        {
            aHash = hashValue;
            hash.insert({astr, hashValue++});
        }
        else
        {
            aHash = _iter->second;
        }
        _iter = hash.find(bstr);
        if (_iter == hash.end())
        {
            bHash = hashValue;
            hash.insert({bstr, hashValue++});
        }
        else
        {
            bHash = _iter->second;
        }

        if (!isUnion(U, aHash, bHash))
        {
            US[find(U, aHash)] += US[find(U, bHash)];
            US[find(U, bHash)] = US[find(U, aHash)];
            Unions(U, aHash, bHash);
        }
        cout << US[find(U, aHash)] << '\n';

        // for (auto i : U)
        //     cout << i << ' ';
        // cout << '\n';
        // for (auto i : US)
        //     cout << i << ' ';
        // cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}