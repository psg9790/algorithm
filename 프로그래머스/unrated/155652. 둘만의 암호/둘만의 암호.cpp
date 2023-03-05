#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    //string answer = "";
    bool skp[26] = {false};
    for(int i =0; i< skip.length(); i++){
        skp[skip[i] - 'a'] = true;
    }
    vector<char> result;
    for(int i =0; i< s.length(); i++){
        int cnt =0;
        char tgt = s[i];
        while(cnt < index){
            if(tgt == 'z'){
                tgt='a';
            }else{
                tgt+=1;
            }
            if(skp[tgt-'a']){
                continue;
            }
            cnt++;
        }
        result.push_back(tgt);
    }
    string answer(result.begin(), result.end());
    return answer;
}