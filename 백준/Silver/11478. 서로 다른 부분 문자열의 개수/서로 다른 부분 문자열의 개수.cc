#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> ss;
string line;
int main()
{
    cin >> line;
    for (int i = 1; i <= line.length(); i++)
    {
        for (int j = 0; j <= line.length() - i; j++)
        {
            string token = line.substr(j, i);
            ss.insert(token);
        }
    }
    cout << ss.size() << '\n';
}