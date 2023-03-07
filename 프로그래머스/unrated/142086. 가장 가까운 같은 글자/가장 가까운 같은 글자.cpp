#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> mem(26, -1);
    for(int i =0; i< s.length(); i++){
        int idx = s[i] - 'a';
        if(mem[idx] == -1)
            answer.push_back(-1);
        else
            answer.push_back(i - mem[idx]);
        mem[idx] = i;
    }
    return answer;
}