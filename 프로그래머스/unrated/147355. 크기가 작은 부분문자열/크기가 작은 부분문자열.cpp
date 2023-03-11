#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int plen = p.length();
    int tlen = t.length();
    int isize = tlen - plen;
    for(int i = 0; i <= isize; i++) {
        string _str = t.substr(i, plen);
        if(_str <= p) {
            answer++;
        }
    }
    return answer;
}