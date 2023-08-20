#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

class trie
{
public:
    void insert(string s, int nxt);
    void find(vector<char> &a, string s, int nxt);

    int count = 0;
    int endCount = 0;
    trie *tries[26];
};

int n;
int num;
void solve()
{
    trie *root = new trie();

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        num = 0;
        string str;
        cin >> str;

        root->insert(str, 0);

        vector<char> cv;
        root->find(cv, str, 0);
        string result = string(string(cv.begin(), cv.end()));
        debug(result);
        cout << result;
        if (num >= 2)
            cout << num;
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}

void trie::insert(string s, int nxt)
{
    int alpha = s[nxt] - 'a';

    if (tries[alpha] == nullptr)
        tries[alpha] = new trie();

    tries[alpha]->count++;

    if (nxt + 1 >= s.length())
    {
        tries[alpha]->endCount++;
        return;
    }

    tries[alpha]->insert(s, nxt + 1);
}

void trie::find(vector<char> &a, string s, int nxt)
{
    int alpha = s[nxt] - 'a';

    a.push_back(s[nxt]);

    if (nxt + 1 >= s.length()) // end
    {
        debug(s, s[nxt], tries[alpha]->endCount);
        if (tries[alpha]->endCount >= 2)
            num = tries[alpha]->endCount;
        // a.push_back((tries[alpha]->endCount + '0'));
        return;
    }
    if (tries[alpha]->count > 1)
        tries[alpha]->find(a, s, nxt + 1);
}