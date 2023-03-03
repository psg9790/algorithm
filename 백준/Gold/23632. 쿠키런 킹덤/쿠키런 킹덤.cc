#include <bits/stdc++.h>
using namespace std;

int n, m, t;
queue<int> q;
vector<vector<int>> S_G;
vector<vector<int>> G_S;
vector<bool> vG;
vector<int> inDegree;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    S_G.resize(n + 1);
    G_S.resize(n + 1);
    vG.resize(n + 1, false);
    inDegree.resize(n + 1, 0);
    dp.resize(n + 1, 0);

    // 이미 건축
    for (int i = 0; i < m; i++) {
        int token;
        cin >> token;
        q.push(token);
        dp[token] = 1;
    }
    // 건물->자원
    for (int i = 1; i <= n; i++) {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++) {
            int token;
            cin >> token;
            S_G[i].push_back(token);
        }
    }
    // 자원->건물
    for (int i = 1; i <= n - m; i++) {
        int sNum;
        cin >> sNum;

        int size;
        cin >> size;
        for (int j = 0; j < size; j++) {
            int token;
            cin >> token;
            G_S[token].push_back(sNum);
            inDegree[sNum]++;
        }
    }

    while (!q.empty()) {
        int curStruct = q.front();
        q.pop();
        // cout << "====================\n"
        //  << "? curStruct: " << curStruct << '\n';

        // Structure -> Gem
        for (int i = 0; i < S_G[curStruct].size(); i++) {
            int targetGem = S_G[curStruct][i];
            // cout << "targetGem: " << targetGem << '\n';
            if (vG[targetGem]) {
                continue;
            }
            vG[targetGem] = true;
            // Gem -> Structure
            for (int j = 0; j < G_S[targetGem].size(); j++) {
                int targetStruct = G_S[targetGem][j];
                // cout << "targetStruct: " << targetStruct << '\n';
                if (--inDegree[targetStruct] == 0) {
                    // cout << "! satisfied: " << targetStruct << '\n';
                    q.push(targetStruct);
                }
                dp[targetStruct] = max(dp[targetStruct], dp[curStruct] + 1);
            }
        }
    }

    // cout << "dp: ";
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << "\n==================\n";

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > 0 && dp[i] <= t + 1) {
            if (inDegree[i] <= 0) {
                result.push_back(i);
            }
        }
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}