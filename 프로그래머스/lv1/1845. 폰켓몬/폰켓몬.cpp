#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> arr(200'001, 0);
    for(auto x : nums){
        arr[x]++;
    }
    for(auto x : arr){
        if(x > 0){
            answer++;
            if(answer == nums.size() / 2)
                return answer;
        }
    }
    return answer;
}