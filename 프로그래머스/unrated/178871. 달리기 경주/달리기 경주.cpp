#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> result;
    
    map<string, int> findByPlayer;
    map<int, string> findByRank;
    for(int i =0 ; i< players.size(); i++){
        findByPlayer.insert({players[i], i});
        findByRank.insert({i, players[i]});
    }
    
    for(int i = 0; i < callings.size(); i++) {
        string curPlayer = callings[i];
        int curRank = findByPlayer.find(curPlayer)->second;
        int targetRank = curRank - 1;
        string targetPlayer = findByRank.find(targetRank)->second;
        
        findByPlayer.find(targetPlayer)->second = curRank;
        findByRank.find(targetRank)->second = curPlayer;
        findByPlayer.find(curPlayer)->second = targetRank;
        findByRank.find(curRank)->second = targetPlayer;
    }
    
    result.resize(players.size());
    for(auto iter = findByPlayer.begin(); iter != findByPlayer.end(); iter++) {
        result[iter->second] = iter->first;
    }
    return result;
}