#include <iostream>
#include <vector>
using namespace std;

int money;
vector<int> stock;

class Order
{
public:
    Order(int _price, int _count) : price(_price), count(_count) {}
    int price;
    int count;
};

int BNP()
{
    vector<Order *> orders;
    int curMoney = money;

    for (int i = 0; i < 14; i++)
    {
        if (curMoney >= stock[i])
        {
            int amount = (curMoney / stock[i]);
            orders.push_back(new Order(stock[i], amount));
            curMoney -= stock[i] * amount;
        }
    }

    int count = 0;
    for (auto i : orders)
    {
        count += i->count;
    }
    return curMoney + count * stock[13];
}

int TIMING()
{
    vector<Order *> orders;
    int curMoney = money;

    int dir = 0;

    for (int i = 1; i < 14; i++)
    {
        if (stock[i] > stock[i - 1]) // increase
        {
            if (dir < 0)
                dir = 0;
            dir++;
        }
        else if (stock[i] < stock[i - 1]) // decrease
        {
            if (dir > 0)
                dir = 0;
            dir--;
        }
        else // same
        {
            dir = 0;
        }

        // buy signal
        if (dir <= -3)
        {
            if (curMoney >= stock[i])
            {
                int amount = (curMoney / stock[i]);
                orders.push_back(new Order(stock[i], amount));
                curMoney -= stock[i] * amount;
            }
        }
        // sell signal
        else if (dir >= 3)
        {
            for (auto smallOrder : orders)
            {
                curMoney += smallOrder->count * stock[i];
            }
            orders.clear();
        }
    }

    int result = curMoney;
    for (auto smallOrder : orders)
    {
        result += smallOrder->count * stock[13];
    }
    return result;
}

int main()
{
    cin >> money;
    for (int i = 0; i < 14; i++)
    {
        int token;
        cin >> token;
        stock.push_back(token);
    }

    int bnp = BNP();
    int timing = TIMING();

    // cout << bnp << ' ' << timing << '\n';

    if (bnp > timing)
        cout << "BNP" << '\n';
    else if (bnp < timing)
        cout << "TIMING" << '\n';
    else
        cout << "SAMESAME" << '\n';
}