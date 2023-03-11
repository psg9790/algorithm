#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int plen = p.length();
    int tlen = t.length();
    int pval = stoi(p);
    int isize = tlen - plen;
    for(int i = 0; i <= isize; i++) {
        string _str = t.substr(i, plen);
        cout << _str << '\n';
        int token = stoi(_str);
        if(token <= pval) {
            answer++;
        }
    }
    return answer;
}