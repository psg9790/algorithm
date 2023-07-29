#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;

class Trie
{
public:
    Trie()
    {
        _v.assign(10, nullptr);
        _end = false;
    }

    void insert(string &_str, int _idx)
    {
        int _tgt = _str[_idx] - '0';
        if (_v[_tgt] == nullptr)
        {
            Trie *newTrie = new Trie;
            _v[_tgt] = newTrie;
        }
        if (_idx == _str.length() - 1)
        {
            _v[_tgt]->setEnd(true);
            return;
        }
        _v[_tgt]->insert(_str, _idx + 1);
    }

    void setEnd(bool _isEnd)
    {
        _end = _isEnd;
    }

    bool getEnd()
    {
        return _end;
    }

    bool isGood()
    {
        for (int i = 0; i < 10; i++)
        {
            if (_v[i] != nullptr)
            {
                if (_end)
                {
                    return false;
                }
                else
                {
                    if (_v[i]->isGood() == false)
                        return false;
                }
            }
        }
        return true;
    }

private:
    vector<Trie *> _v;
    bool _end;
};

void solve()
{
    cin >> n;
    Trie *root = new Trie;
    for (int i = 0; i < n; i++)
    {
        string token;
        cin >> token;
        root->insert(token, 0);
    }
    bool result = root->isGood();
    cout << (result ? "YES" : "NO") << '\n';
    root = nullptr;
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