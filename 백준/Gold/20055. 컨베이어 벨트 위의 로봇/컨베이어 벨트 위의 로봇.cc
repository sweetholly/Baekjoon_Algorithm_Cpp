#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>


using namespace std;
int main(){
    int n, k;
    int dropPoint;
    int raisePoint = 0;
    int round = 0;
    int zeroCount = 0;


    cin >> n >> k;
    dropPoint = n-1;
    vector<pair<int,bool>>belt (2*n, {0,0});
    deque<int>robot;
    for(int i = 0; i < 2*n; i ++){
        // 내구도
        cin >> belt[i].first;
    }
    while(1){
        //1. 한 칸 벨트를 돌리기 -> raisePoint랑, dropPoint 인덱스만 바꾸면 된다.
        raisePoint -= 1;
        if(raisePoint < 0) raisePoint = 2*n-1;
        dropPoint -= 1;
        if(dropPoint < 0) dropPoint = 2*n-1;
        if(belt[dropPoint].second){
            robot.pop_front();
            belt[dropPoint].second = false;
        }

        //2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동
        deque<int>nextRobot;
        while(!robot.empty()){
            int cur = robot.front();
            robot.pop_front();

            int next = cur + 1;
            if(next == 2*n) next = 0;
            
            if(belt[next].first > 0 && !belt[next].second){
                belt[cur].second = false;
                belt[next].first--;
                if(belt[next].first == 0) zeroCount ++;
                
                if(next != dropPoint){
                    belt[next].second = true;
                    nextRobot.push_back(next);
                }
            }
            else{
                nextRobot.push_back(cur);
            }
        }
        robot = nextRobot;
        // 만약 현재 raisePoint에 로봇을 올릴 수 있으면 올리기
        if(belt[raisePoint].first > 0 && !belt[raisePoint].second) {
            robot.push_back(raisePoint);
            belt[raisePoint].first --;
            belt[raisePoint].second = true;
            if(belt[raisePoint].first == 0) zeroCount ++;
        }
        round++;
        if(zeroCount >= k)
            break;
    }
    cout <<round;
}