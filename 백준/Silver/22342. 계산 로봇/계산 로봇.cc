#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int weight[2001][2001];
int out[2001][2001]; // 출력 값

int main()
{
    int M, N;
    cin >> M >> N;

    for(int i = 1; i <= M; i++){
        string input;
        cin >> input;
        for(int j = 1; j <= N; j++)
            weight[i][j] = input[j-1] - '0';
    }

    int ans = 0;

    // 첫 열: 저장 값 = 0, 출력 값 = weight
    for(int i = 1; i <= M; i++) {
        out[i][1] = weight[i][1];
    }
    
    // 둘째 열부터
    for(int j = 2; j <= N; j++){
        for(int i = 1; i <= M; i++){
            int store = out[i][j-1];
            if(i > 1) {
                store = max(store, out[i-1][j-1]);
            }
            if(i < M) {
                store = max(store, out[i+1][j-1]);
            }
            ans = max(ans, store);      
            out[i][j] = store + weight[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}