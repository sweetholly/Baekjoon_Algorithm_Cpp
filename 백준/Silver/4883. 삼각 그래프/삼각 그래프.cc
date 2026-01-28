#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e15;

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case = 1;
    int n;

    // 입력이 0이 될 때까지 반복
    while(cin >> n && n != 0){
        vector<vector<long long>> node(n, vector<long long>(3));
        vector<vector<long long>> dp(n, vector<long long>(3));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                cin >> node[i][j];
            }
        }

        dp[0][0] = INF; 
        dp[0][1] = node[0][1]; // 시작점
        dp[0][2] = dp[0][1] + node[0][2];

        // 2번째 줄부터
        for(int i = 1; i < n; i++){
            // 0번 열: 
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + node[i][0];

            // 1번 열: 
            long long temp_min = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1] = min(dp[i][0], temp_min) + node[i][1];

            // 2번 열:
            long long temp_min2 = min(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = min(dp[i][1], temp_min2) + node[i][2];
        }

        cout << test_case++ << ". " << dp[n-1][1] << "\n";
    }
    return 0;
}
