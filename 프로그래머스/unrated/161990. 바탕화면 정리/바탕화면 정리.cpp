#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int mnr = wallpaper.size();
    int mnc = wallpaper[0].length();
    int mxr = 0;
    int mxc = 0;
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j< wallpaper[0].length(); j++){
            if(wallpaper[i][j] == '#'){
                if(i < mnr)
                    mnr = i;
                if(i > mxr)
                    mxr = i;
                if(j < mnc)
                    mnc = j;
                if(j > mxc)
                    mxc = j;
            }
        }
    }
    answer.push_back(mnr);
    answer.push_back(mnc);
    answer.push_back(mxr + 1);
    answer.push_back(mxc + 1);
    return answer;
}