#include<iostream>
#include<vector>

using namespace std;

int N;
long long scores[5] = {0, 1, 10, 100, 1000};
long long total = 0;
int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

int main(){
    cin >> N;
    vector<int>students(N*N);
    vector<vector<int>>likes(N*N+1, vector<int>(4));
    vector<vector<int>>cell(N, vector<int>(N, 0));

    for(int i = 0; i < N*N; i++){
        cin >> students[i];
        for(int j = 0; j < 4; j++){
            cin >> likes[students[i]][j];
        }
    }

    // 배치
    for(int i = 0; i < N*N; i++){
        int student = students[i];
        int bestLike = -1;
        int bestEmpty = -1;
        int finalRow = -1, finalCol = -1;

        for(int row = 0; row < N; row++){
            for(int col = 0; col < N; col++){
                if(cell[row][col] != 0) continue;
                int likedCount = 0;
                int emptyCount = 0;
                for(int d = 0; d < 4; d++){
                    int nrow = row + drow[d];
                    int ncol = col + dcol[d];
                    if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N) continue;
                    if(cell[nrow][ncol] == 0) emptyCount++;
                    else{
                        for(int k = 0; k < 4; k++){
                            if(cell[nrow][ncol] == likes[student][k]){
                                likedCount++;
                                break;
                            }
                        }
                    }
                }
                if(likedCount > bestLike){
                    bestLike = likedCount;
                    bestEmpty = emptyCount;
                    finalRow = row;
                    finalCol = col;
                }
                else if(likedCount == bestLike && emptyCount > bestEmpty){
                    bestEmpty = emptyCount;
                    finalRow = row;
                    finalCol = col;
                }
            }
        }
        cell[finalRow][finalCol] = student;
    }

    // 만족도 계산
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            int student = cell[row][col];
            int likedCount = 0;
            for(int d = 0; d < 4; d++){
                int nrow = row + drow[d];
                int ncol = col + dcol[d];
                if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N) continue;
                for(int k = 0; k < 4; k++){
                    if(cell[nrow][ncol] == likes[student][k]){
                        likedCount++;
                        break;
                    }
                }
            }
            total += scores[likedCount];
        }
    }

    cout << total << "\n";
    return 0;
}