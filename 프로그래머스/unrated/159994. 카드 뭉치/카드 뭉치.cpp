#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int ptr1 =0;
    int ptr2 =0;
    for(int i = 0; i< goal.size(); i++){
        if(ptr1<cards1.size() && goal[i] == cards1[ptr1]){
            ptr1++;
        }else if(ptr2<cards2.size() && goal[i] == cards2[ptr2]){
            ptr2++;
        }else{
            answer="No";
            break;
        }
    }
    return answer;
}