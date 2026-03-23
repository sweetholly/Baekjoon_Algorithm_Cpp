
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int n, l, r;
int board[51][51];
bool visited[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int days = 0;

    while (true) {
        bool moved = false;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) {
                    continue;
                }
                // BFS로 연합 탐색
                queue<pair<int,int>> q;
                vector<pair<int,int>> united;
                q.push({i, j});
                visited[i][j] = true;
                int total = board[i][j];

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    united.push_back({x, y});

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
                            continue;
                        }
                        int diff = abs(board[x][y] - board[nx][ny]);
                        if (diff < l || diff > r) {
                            continue;
                        }
                        visited[nx][ny] = true;
                        total += board[nx][ny];
                        q.push({nx, ny});
                    }
                }

                // 연합이 2칸 이상이면 인구 이동 발생
                if (united.size() >= 2) {
                    moved = true;
                    int avg = total / (int)united.size();
                    for (auto [x, y] : united)
                        board[x][y] = avg;
                }
            }
        }

        if (!moved) {
            break;
        }
        days++;
    }

    cout << days << '\n';
    return 0;
}