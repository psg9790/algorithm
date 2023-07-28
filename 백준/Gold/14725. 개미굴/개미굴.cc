#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

class Trie
{
public:
    void push_back(vector<string> &_strlines, int idx)
    {
        if (idx == _strlines.size())
            return;
        map<string, Trie *>::iterator _iter = _map.find(_strlines[idx]);
        if (_iter != _map.end()) // found
        {
            _iter->second->push_back(_strlines, idx + 1);
        }
        else
        {
            Trie *newTrie = new Trie;
            _map.insert({_strlines[idx], newTrie});
            newTrie->push_back(_strlines, idx + 1);
        }
    }
    void print(int _level)
    {
        // 자식 프린트
        for (map<string, Trie *>::iterator _iter = _map.begin(); _iter != _map.end(); _iter++)
        {
            for (int dash = 0; dash < 2 * _level; dash++)
                cout << '-';
            cout << _iter->first << '\n';
            _iter->second->print(_level + 1);
        }
    }

private:
    map<string, Trie *> _map;
};

void solve()
{
    int n;
    cin >> n;
    Trie *root = new Trie;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<string> lines;
        for (int j = 0; j < m; j++)
        {
            string token;
            cin >> token;
            lines.push_back(token);
        }
        root->push_back(lines, 0);
    }
    root->print(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}