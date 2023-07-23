#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    while (n--)
    {
        int token;
        cin >> token;
        dq.push_back(token);
    }

    sort(dq.begin(), dq.end());
    int result = 0;
    while (dq.size() >= 2)
    {
        int sideSum = dq.front() + dq.back();
        if (sideSum > k)
        {
            dq.pop_back();
            continue;
        }

        result++;
        dq.pop_front();
        dq.pop_back();
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}