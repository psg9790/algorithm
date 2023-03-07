#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> ss;
    for(auto x : nums){
        ss.insert(x);
    }
    answer = min(nums.size() / 2, ss.size());
    return answer;
}