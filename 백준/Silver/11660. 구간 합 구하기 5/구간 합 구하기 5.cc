#include <iostream>
#include <vector>
using namespace std;

int n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    int summa = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i][0] = summa;
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            arr[i][j] += summa;
            summa = arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int rst = 0;
        for (int j = y1; j <= y2; j++)
        {
            rst += arr[j][x2] - arr[j][x1 - 1];
        }
        cout << rst << '\n';
    }
}