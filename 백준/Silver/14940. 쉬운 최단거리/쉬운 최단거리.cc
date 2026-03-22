/*
14849: 쉬운 최단거리
제한시간 1초 : 1억회 연산 가능

N과 M의 범위가 둘다 1000 1000 이므로,
log(N*M) = 20 정도로, O(N*M*log(N*M)) 알고리즘이 가능할 것으로 보인다.
BFS로 최단거리를 구하는 문제로 보임
기준점부터 시작해서 모든 지점으로 가는 최단거리를 구하는 문제인데...사실 이걸 굳이 최단거리를 구할 생각을 안 해도 될 것 같다.
기준점으로부터 시작해서 모든 방향으로 BFS를 돌리면 어차피 자연스럽게 최단 거리가 구해질 것이다.
모든 지역

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ds[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    pair<int, int> start;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> mindistance(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                start = {i, j};
                mindistance[i][j] = 0;
            }
            else if(map[i][j] == 0) {
                mindistance[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    mindistance[start.first][start.second] = 0;
    // BFS로 탐색하면서, 각 지점까지의 최단거리를 구하기
    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        for(int i= 0; i < 4; i++){
            int nextX = current.first + ds[i][0];
            int nextY = current.second + ds[i][1];
            if(nextX <0 || nextX >= n || nextY < 0 || nextY >= m) continue;
            if(map[nextX][nextY] == 1 && mindistance[nextX][nextY] == 0) {
                mindistance[nextX][nextY] = mindistance[current.first][current.second] + 1;
                q.push({nextX, nextY});
            }
        }
    }
       

    // 출력 
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j] == 1 && mindistance[i][j] == 0) {
                cout << -1 << " ";
            }
            else {
                cout << mindistance[i][j] << " ";
            }

        }
        cout <<"\n";
    }

    return 0;
}