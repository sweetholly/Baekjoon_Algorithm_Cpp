#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> student; // 학생 -> 책 리스트
vector<int>match; // 책 -> 학생 매칭
vector<bool>visited; // 방문 여부

bool dfs(int stNum) {
    for (int i = 0; i < student[stNum].size(); i ++) {
        int book = student[stNum][i];
        if (visited[book]) {
            continue;
        }
        visited[book] = true;
        
        //여기가 핵심임
        //만약, 순차적으로 dfs만 단순히 따지면, 선호 조건을 늦게 입력받은 학생의 경우의 수를 고려하지 못 함
        // 따라서, 어떤 칸이 마음에 들었을 때, 원래 해당 칸을 점유하고 있는 학생이 다른 칸으로 이사할 수 있으면, 가능!
        
        //내가 처음 이 책을 할당 받은 경우 -> 고냥 내가 차지해버려이
        if (match[book] == -1) {
            match[book] = stNum;
            return true;
        }

        //읽고싶은 책인데, 누가 이미 선점한 경우
        else if(match[book] != -1){
            bool result = dfs(match[book]);
            if(result){
                match[book] = stNum;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;

        student.assign(M, {});
        match.assign(N, -1);

        for (int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;
            for (int j = A-1; j < B; j++) {
                student[i].push_back(j);
            }
        }
        int matching = 0;
        for (int i = 0; i < M; i++) {
            visited.assign(N, false);
            if (dfs(i)) {
                matching++;
            }
        }
        
        cout << matching << endl;
    }
    return 0;
}