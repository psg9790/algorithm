#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

class Trie
{
public:
    Trie()
    {
        _next.assign(26, nullptr);
        _end = false;
    }

    void Insert(string &_str, string::iterator _iter)
    {
        int _idx = (*_iter) - 'a';
        if (_next[_idx] == nullptr)
        {
            Trie *newT = new Trie();
            _next[_idx] = newT;
        }

        if (_iter == --_str.end())
        {
            _next[_idx]->_end = true;
            return;
        }
        _next[_idx]->Insert(_str, next(_iter, 1));
    }

    bool IsPrefix(string &_str, string::iterator _iter)
    {
        int _idx = (*_iter) - 'a';
        if (_next[_idx] == nullptr)
            return false;
        if (_iter == --_str.end())
            return true;
        return _next[_idx]->IsPrefix(_str, next(_iter, 1));
    }

private:
    vector<Trie *> _next;
    bool _end;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Trie *root = new Trie;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string token;
        cin >> token;
        root->Insert(token, token.begin());
    }
    int rst = 0;
    for (int i = 0; i < m; i++)
    {
        string token;
        cin >> token;
        if (root->IsPrefix(token, token.begin()))
            rst++;
    }
    cout << rst << '\n';
}
