#include <string>
#include <vector>
#include <iostream>
using namespace std;

using ip = pair<int,int>;


int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int FindoutDir(char sym)
{
    switch(sym)
    {
        case 'N':
            return 0;
            break;
        case 'S':
            return 1;
            break;
        case 'W':
            return 2;
            break;
        case 'E':
            return 3;
            break;
        default:
            break;
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    ip start;
    for(int i = 0; i< park.size(); i++)
    {
        for(int j = 0; j< park[0].size(); j++)
        {
            if(park[i][j] == 'S')
            {
                start = {i, j};
            }
        }
    }
    
    for(int i = 0; i < routes.size(); i++)
    {
        int dir = FindoutDir(routes[i][0]);
        int power = routes[i][2] - '0';
        
        int yy = start.first;
        int xx = start.second;
        
        for(int j = 0; j< power; j++)
        {
            yy += dy[dir];
            xx += dx[dir];
            if(yy < 0 || yy >= park.size() || xx < 0 || xx >= park[0].size())
                goto NOMOVE;
            else if(park[yy][xx] == 'X')
                goto NOMOVE;
        }
        start = {yy, xx};
        
        NOMOVE:
            continue;
    }
    
    answer.push_back(start.first);
    answer.push_back(start.second);
    
    return answer;
}