#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#include <vector> 
using namespace std;

int answer = 0;
bool visited[8] = {0,};
void exp(int seek, int k, vector<vector<int>> &dungeons){
    if(seek > answer) answer = seek; 

    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && dungeons[i][0] <= k){
            visited[i] = true; 
            exp(seek + 1, k - dungeons[i][1], dungeons); 
            visited[i] = false;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    exp(0, k, dungeons);
    return answer;
}