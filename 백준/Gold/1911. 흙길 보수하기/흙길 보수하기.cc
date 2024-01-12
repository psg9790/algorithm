#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using ip = pair<int, int>;

struct logCmp
{
    bool operator()(ip a, ip b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int N, L;
vector<ip> logs;
void solve()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        logs.push_back({s, e - 1});
    }
    sort(logs.begin(), logs.end(), logCmp());

    int sumv = 0;
    int start = logs[0].first, end = logs[0].second;
    for (int i = 0; i < logs.size(); i++)
    {
        int prevPoolSize = end - start + 1;
        int prevLogs = ceil(prevPoolSize / (float)L);
        int prevLogsCount = prevLogs * L;
        int prevLogsReach = start + prevLogsCount - 1;

        // 전에 배치 예정했던 통나무가 연결될 수 있을 때
        if (prevLogsReach >= logs[i].first)
        {
            end = logs[i].second;
        }
        // 새로운 통나무 배치 시작
        else
        {
            sumv += prevLogs;

            start = logs[i].first;
            end = logs[i].second;
        }
    }
    int prevPoolSize = end - start + 1;
    int prevLogs = ceil(prevPoolSize / (float)L);
    sumv += prevLogs;
    cout << sumv << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}