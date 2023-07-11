#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map<string, int> table;
    for(int i =0 ; i< name.size(); i++) {
        table.insert({name[i], yearning[i]});
    }
    for(vector<string> p : photo) {
        int score = 0;
        for(int i =0; i< p.size(); i++) {
            map<string, int>::iterator iter = table.find(p[i]);
            if(iter != table.end()) {
                score += iter->second;
            }
        }
        answer.push_back(score);
    }
    return answer;
}