#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT32_MAX;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

class node
{
public:
    int y, x;
    int cost;

public:
    node()
    {
        y = 0;
        x = 0;
        cost = 0;
    }
    node(node *tgt)
    {
        this->y = tgt->y;
        this->x = tgt->x;
        this->cost = tgt->cost;
    }
};

struct nodeCmp
{
    bool operator()(node *a, node *b)
    {
        return a->cost > b->cost;
    }
};

int times = 1;
int n;
vector<vector<int>> board;
void solve()
{
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    node *init = new node();
    init->y = 0;
    init->x = 0;
    init->cost = board[0][0];

    vector<vector<int>> visited(n, vector<int>(n, INF));
    visited[0][0] = board[0][0];
    priority_queue<node *, vector<node *>, nodeCmp> pq;
    pq.push(init);

    // cout << times << '\n';
    while (pq.empty() == false)
    {
        node *frt = pq.top();
        pq.pop();
        // cout << "do " << frt->y << ' ' << frt->x << '\n';

        if (frt->y == n - 1 && frt->x == n - 1)
        {
            cout << "Problem " << times << ": " << frt->cost << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int yy = frt->y + dy[i];
            int xx = frt->x + dx[i];
            if (yy < 0 || yy >= n || xx < 0 || xx >= n)
                continue;
            int nextCost = frt->cost + board[yy][xx];
            if (visited[yy][xx] <= nextCost)
                continue;
            visited[yy][xx] = nextCost;
            node *nextNode = new node();
            nextNode->y = yy;
            nextNode->x = xx;
            nextNode->cost = nextCost;
            pq.push(nextNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        solve();
        times++;
    }
}