#include <bits/stdc++.h>
using namespace std;

void Gazua(int in)
{
    while (in > 1)
    {
        if (in % 2 == 0)
        {
            in /= 2;
        }
        else
        {
            cout << "Gazua" << '\n';
            return;
        }
    }
    cout << "GoHanGang" << '\n';
}

int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;

        Gazua(k);
    }
}