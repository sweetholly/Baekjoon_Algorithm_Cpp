#include <string>
#include <vector>

using namespace std;
// qr,qc = 퀸의 위치
void mark(vector<vector<int>>& board, int qr, int qc, int n, int value) {
    //열
    for(int c = 0; c < n; c++) board[qr][c] += value;
    //행
    for(int r = 0; r < n; r++) board[r][qc] += value;
    //대각선 우측 아래 , 좌측 위, 우측 위, 좌측 아래
    for (int d = 1; qr + d < n && qc + d < n; d++)      board[qr + d][qc + d] += value;
    for (int d = 1; qr - d >= 0 && qc - d >= 0; d++)    board[qr - d][qc - d] += value;
    for (int d = 1; qr - d >= 0 && qc + d < n; d++)     board[qr - d][qc + d] += value;
    for (int d = 1; qr + d < n && qc - d >= 0; d++)     board[qr + d][qc - d] += value;
}

void dfs(int row, int n, vector<vector<int>>&board, int& answer){
    if(row == n) {
        answer ++;
        return;
    }
    for(int col = 0; col < n; col++){
        if(board[row][col] ==0){
            mark(board, row, col, n, 1);
            dfs(row+1, n, board, answer);
            mark(board, row, col, n, -1);
        }
    }
}

int solution(int n){
    int answer = 0;
    vector<vector<int>>board(n, vector<int>(n, 0));
    dfs(0, n, board, answer);
    return answer;
}