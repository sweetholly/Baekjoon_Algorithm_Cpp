#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
pair<int, int> direction[8] = {
    make_pair(0, -1), // 좌
    make_pair(-1, -1), // 좌상
    make_pair(-1, 0), // 상
    make_pair(-1, 1), // 우상
    make_pair(0, 1), // 우
    make_pair(1, 1), // 우하
    make_pair(1, 0), // 하
    make_pair(1, -1) // 좌하
};

//비 내린 후, 대각선칸에 물이 있는 개수만큼 물 증가
vector<pair<int, int>> diag = {
    make_pair(-1, -1), 
    make_pair(-1, 1),
    make_pair(1, -1), 
    make_pair(1, 1)
};

int main() {
    vector<vector<int>> board;
    vector<pair<int, int>> clouds;
    cin >> N >> M;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    // 초기 구름
    clouds = { 
        {N-1, 0}, 
        {N-1, 1}, 
        {N-2, 0}, 
        {N-2, 1} 
    };
    
    for (int m = 0; m < M; m++) {
        int d, s;
        cin >> d >> s;
        vector<pair<int, int>> new_clouds;
        for(int i = 0; i < clouds.size(); i++) {
            pair<int, int> p = clouds[i];
            int nr = p.first, nc = p.second;
            for (int i = 0; i < s; i++) {
                nr += direction[d-1].first;
                nc += direction[d-1].second;
                //범위 나갔는지 체크
                if (nr < 0) nr = N-1;
                else if (nr >= N) nr = 0;
                if (nc < 0) nc = N-1;
                else if (nc >= N) nc = 0;
            }
            new_clouds.push_back(make_pair(nr, nc));
            board[nr][nc]++;
        }
        clouds = new_clouds;

        //이동 후, 대각선칸에 물이 있는 수만큼 물 증가
        for (int i = 0; i < clouds.size(); i ++){
            pair<int, int> p = clouds[i];
            int r = p.first, c = p.second;
            int cnt = 0;
            for (int j = 0; j < 4; j ++) {
                pair<int, int> d = diag[j]; 
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && board[nr][nc] > 0) {
                    cnt++;
                }
            }
            board[r][c] += cnt;
        }

        // 비가 내렸던 자리 제외 물이 2씩 감소해야함. prev_clouds에 임시 저장
        vector<pair<int, int>> prev_clouds;
        for (int i = 0; i < clouds.size(); i ++){
            prev_clouds.push_back(clouds[i]);
        }
        clouds.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] >= 2 && find(prev_clouds.begin(), prev_clouds.end(), make_pair(i, j)) == prev_clouds.end()) {
                    board[i][j] -= 2;
                    clouds.push_back(make_pair(i, j));
                }
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total += board[i][j];
        }
    }
    cout << total << endl;
    return 0;
}