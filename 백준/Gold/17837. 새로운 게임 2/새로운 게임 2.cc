
/*
각 체스판은 흰색,빨간색,파란색 중 하나로 색칠됨
한 판에는 여러개 말이 존재할 수 있음

말은 1~K번까지 번호가 매겨짐
각 말의 이동 방향은 미리 정해져 있으며, 상하좌우 중 하나임

턴 한 번에 위에 올려져있는 마롣 같이 이동함

말이 4개 이상 쌓이는 순간 게임이 끝남

말이 이동하려는 방향의 칸에 따라서 이동이 달라짐

각 턴당 1~K번 말이 모두 이동함

EX) 말 A를 움직이게 하려고 할 때,
칸이 흰색인 경우 -> 해당 칸으로 이동함, 가장 위에 A번 말을 올림
A번 말의 위에 다른 말이 있는 경우, A번 말과 위에 있는 모든 말이 이동
ABC 가 이동하면, 이동 칸에 DE가 있으면, DE-ABC 순서대로 쌓임

빨간색인 경우 -> 이동한 후, A번 말과 그 위에 있는 모든 말의 쌓인 순서 반대로
ABC -> CBA
ADFG -> ECB가 있으면, ECB-GFDA가 된다.

파란색인 경우 -> A번 말의 이동 방향을 반대로 하고 한 칸 이동
방향을 반대로 바꾸고 가려는 칸도 파란색이면 가만히 있음



접근법
1. 각 말 별로, 현재 위치, 방향, 위에 있는 말을 가리키는 자료구조를 하나 만들자, 쌓을 수 있다 했으니 링크드 리스트로 하면 될 듯
2. 칸도 자료구조로 만들자, 칸은 2차원 벡터로 만들고, 각 칸의 자료형을 자료구조로 만들어야 함.
3. 제한시간은 0.5초, 5천만번 수행 가능하다
4. 턴은 최대 1000턴까지 진행되므로, 1000턴 * K번, K는 최대값이 10이므로, 10000번 수행 가능하다
5. 자료구조만 잘 정의해서 10000회 수행하면 될 듯?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

struct piece {
    int x;
    int y;
    int direction;
    piece* above;
} pieces[10];

struct cells {
    piece* bottom;
    int pieceCount;
    int color;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<cells>> board(n, vector<cells>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j].color;
            board[i][j].bottom = nullptr;
            board[i][j].pieceCount = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> pieces[i].x >> pieces[i].y >> pieces[i].direction;
        pieces[i].x--;
        pieces[i].y--;
        pieces[i].direction--;
        pieces[i].above = nullptr;

        if (board[pieces[i].x][pieces[i].y].bottom == nullptr) {
            board[pieces[i].x][pieces[i].y].bottom = &pieces[i];
        } else {
            piece* top = board[pieces[i].x][pieces[i].y].bottom;
            while (top->above != nullptr) top = top->above;
            top->above = &pieces[i];
        }
        board[pieces[i].x][pieces[i].y].pieceCount++;
    }

    int turn = 0;
    bool gameEnd = false;

    while (!gameEnd && turn < 1000) {
        turn++;
        for (int i = 0; i < k; i++) {
            int r = pieces[i].x;
            int c = pieces[i].y;
            int d = pieces[i].direction;
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || 
                board[nr][nc].color == BLUE) {
                if(d == 0) d = 1;
                else if(d == 1) d = 0;
                else if(d == 2) d = 3;
                else if(d == 3) d = 2;
                pieces[i].direction = d;
                nr = r + dr[d];
                nc = c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n 
                    || board[nr][nc].color == BLUE) {
                    continue;
                }
            }

            // 위에 쌓이 말은 같이 이동해야 하므로, linkedlist 따라가며 이동시키기
            // 체인 자료형 선언, linkedlist를 따라가면서 말들을 엮어서 이동시키기
            vector<piece*> chain;
            piece* p = board[r][c].bottom;
            bool found = false;
            while (p) {
                if (p == &pieces[i]) found = true;
                if (found) chain.push_back(p);
                p = p->above;
            }

            if (chain.empty()) continue;

            // 현재 칸에서 체인 끊기
            board[r][c].pieceCount -= chain.size();
            piece* check = board[r][c].bottom;
            if (board[r][c].bottom == chain[0]) {
                board[r][c].bottom = nullptr;
            } 
            else {
                while(check->above) {
                    if(check->above == chain[0]) {
                        check->above = nullptr;
                        break;
                    }
                    check = check->above;
                }
            }

            // 빨간색인 경우 -> 이동한 후, A번 말과 그 위에 있는 모든 말의 쌓인 순서 반대로
            // 순서 반대로 하고 다시 링크 생성     
            if (board[nr][nc].color == RED) {
                reverse(chain.begin(), chain.end());
                for (int j = 0; j + 1 < chain.size(); j++) {
                    chain[j]->above = chain[j + 1];
                }
                chain.back()->above = nullptr;
            }


            // 처음이면, 맨 위칸을
            if (board[nr][nc].bottom == nullptr) {
                board[nr][nc].bottom = chain[0];
            } 
            
            // 기존 말의 위에 올림 -> 링크드 리스트 따라가기
            else {
                piece* top = board[nr][nc].bottom;
                while (top->above != nullptr) {
                    top = top->above;
                }
                top->above = chain[0];
            }
            for(int j = 0; j < chain.size(); j++){
                chain[j]->x = nr;
                chain[j]->y = nc;
            }

            board[nr][nc].pieceCount += chain.size();
            if (board[nr][nc].pieceCount >= 4) {
                gameEnd = true;
                break;
            }
        }
    }

    if (gameEnd) {
        cout << turn << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}