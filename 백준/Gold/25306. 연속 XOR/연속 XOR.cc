#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

// void test(int a, int b)
// {
//     int result = a;
//     for (int i = a + 1; i <= b; i++)
//     {
//         result = result ^ i;
//     }
//     cout << result << '\n';
// }

void solve()
{
    ull a, b;
    cin >> a >> b;

    // test(a, b);

    ull result = 0;
    ull i = a;
    while (i <= b)
    {
        if (i % 4 == 0)
        {
            ull indent = (b - i) / 4;
            if (indent > 0)
            {
                indent = indent * 4;
                i += indent;
                continue;
            }
        }
        result = result ^ i;
        i++;
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}