#include <bits/stdc++.h>
using namespace std;

class ClockCustom
{
public:
    ClockCustom(string _o, int _h, int _m) : original(_o), hour(_h), minute(_m) {}

    string original;
    int hour;
    int minute;
    float degree;

    void Calculate()
    {
        mDegree = 6.0 * minute;
        hDegree = 30.0 * (hour % 12) + minute * 0.5f;
        degree = min((abs(mDegree - hDegree)), (min(mDegree, 360 - mDegree) + min(hDegree, 360 - hDegree)));
    }

    void Display()
    {
        cout << "--- " << original << " >> h:" << hDegree << " m:" << mDegree << " >> " << degree << '\n';
    }

private:
    float hDegree;
    float mDegree;
};
struct ClockCmp
{
    bool operator()(ClockCustom *a, ClockCustom *b)
    {
        if (a->degree == b->degree)
        {
            if (a->hour == b->hour)
            {
                return a->minute < b->minute;
            }
            return a->hour < b->hour;
        }
        return a->degree < b->degree;
    }
};

void solve()
{
    vector<ClockCustom *> clocks;
    for (int i = 0; i < 5; i++)
    {
        string token;
        cin >> token;

        string hstring(token, 0, 2);
        string mstring(token, 3, 5);
        ClockCustom *lClock = new ClockCustom(token, stoi(hstring), stoi(mstring));
        lClock->Calculate();
        clocks.push_back(lClock);
    }
    sort(clocks.begin(), clocks.end(), ClockCmp());

    // for (auto i : clocks)
    //     i->Display();

    cout << clocks[2]->original << '\n';
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