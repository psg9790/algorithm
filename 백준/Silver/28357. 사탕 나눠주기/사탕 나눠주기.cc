#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll clamp(ll num, ll lower, ll upper)
{
    if (num < lower)
        return lower;
    if (num > upper)
        return upper;
    return num;
}

int n;
ll k;
vector<ll> students;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    students.resize(n);
    for (int i = 0; i < n; i++)
        cin >> students[i];

    sort(students.begin(), students.end());
    ll lower = 0;
    ll upper = students[students.size() - 1];
    ll mid, buffer;
    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        ll nsum = 0;
        for (auto i : students)
        {
            nsum += clamp(i - mid, (ll)0, __LONG_LONG_MAX__);
            if (nsum > k)
                goto OVERFLOWED;
        }

        // cout << "lower upper : " << lower << ' ' << upper << '\n';
        // cout << "mid: " << mid << ' ' << nsum << '\n';
        if (nsum > k) // too many
        {
        OVERFLOWED:
            lower = mid + 1;
        }
        else if (nsum < k) // can get more?
        {
            buffer = mid;
            upper = mid - 1;
        }
        else // profit!
        {
            buffer = mid;
            break;
        }
    }
    // cout << mid << ' ' << buffer << '\n';
    mid = buffer;
    cout << mid << '\n';
}