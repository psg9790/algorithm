#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> imos(n, vector<int>(m, 0));
    for(vector<int> &x : skill){
        if(x[0] == 1){
            imos[x[1]][x[2]] -= x[5];
            if(x[3] + 1 < n){
                imos[x[3] + 1][x[2]] += x[5];
            }
            if(x[4] + 1 < m){
                imos[x[1]][x[4] + 1] += x[5];
            }
            if(x[3] + 1 < n &&
              x[4] + 1 < m){
                imos[x[3] + 1][x[4] + 1] -= x[5];
            }
        } else if(x[0] == 2){
            imos[x[1]][x[2]] += x[5];
            if(x[3] + 1 < n){
                imos[x[3] + 1][x[2]] -= x[5];
            }
            if(x[4] + 1 < m){
                imos[x[1]][x[4] + 1] -= x[5];
            }
            if(x[3] + 1 < n &&
              x[4] + 1 < m){
                imos[x[3] + 1][x[4] + 1] += x[5];
            }
        }
    }
    // sweep right
    for(int c = 1; c < m; c++){
        for(int r =0 ;r < n; r++){
            imos[r][c] += imos[r][c - 1];
        }
    }
    // sweep down
    for(int r =1; r<n; r++){
        for(int c =0; c<m; c++){
            imos[r][c] +=imos[r-1][c];
        }
    }
    // add
    for(int r =0; r<n; r++){
        for(int c =0; c<m; c++){
            board[r][c] += imos[r][c];
            if(board[r][c] > 0){
                answer++;
            }
        }
    }
    return answer;
}