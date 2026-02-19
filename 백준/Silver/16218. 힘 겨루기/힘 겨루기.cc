#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> player_values;
vector<int> robot_values;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    int overpower = 0;
    int winner = 0;
    int player_prev = 0, robot_prev = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i ++) {
        int player_value, robot_value;
        cin >> player_value >> robot_value;
        if(winner == 1 || winner == -1){
            continue;
        }

        if(overpower > 0){
            player_value -= player_value/2;
            overpower = -1;
        }

        // 플레이어와 로봇의 값을 누적하여 저장
        player_values.push_back(player_value);
        player_values[i] += player_prev;
        robot_values.push_back(robot_value);
        robot_values[i] += robot_prev;

        player_prev = player_values[i];
        robot_prev = robot_values[i];

        // 로봇 혹은 플레이어가 K 이상이 된 경우,,
        if(robot_values[i] >= K || player_values[i] >= K){
            //1. 플레이어가 K 이상 달성
            if(player_values[i] >= K){
                winner = 1;
            }
            if(robot_values[i] >= K){
                if(player_values[i] >= K && overpower == 0){
                    winner = 1;
                }
                else{
                    winner = -1;
                }
            }
            continue;
        }
        

        // 플레이어가 overpower을 이용해 k를 넘길 수 있다면, 플레이어 승리
        else if(player_values[i] + player_value/2 >= K && overpower == 0){
            overpower = player_value/2;
            winner = 1;
            continue;
        }

        // 플레이어가 K 이상이 아니지만, 로봇보다 50 이상 높다면, 플레이어 승리
        else if(player_values[i] + player_value/2 >= robot_values[i] + 50 && overpower == 0){
            overpower = player_value/2;
            winner = 1;
            continue;
        }

        // 플레이어가 마지막 라운드에서 overpower을 이용할 때 로봇보다 50 이상 높다면, 플레이어 승리
        else if(i == N-1 && overpower == 0 && player_values[i] + player_value/2 >= robot_values[i] + 50){
            overpower = player_value/2;
            winner = 1;
            continue;
        }
    }
    cout<<winner;
    return 0;
}