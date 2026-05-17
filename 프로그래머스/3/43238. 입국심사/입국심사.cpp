#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    최대 시간과 최소시간을 알 수 있음.
      -> 가장 짧게 걸리는 심사관의 시간, 
      -> 가장 길게 걸리는 심사관의 시간

    최대/최소의 중앙값인 mid를 계산하고, mid의 값까지 시간 내에 각 면접관이
    얼마나 통과 가능한지 검증
    만약 mid 시간 내에 모두 통과 안되면? -> 오른쪽 범위 탐색
    시간 안에 통과하면? -> 왼쪽 범위로 다시 탐색해보기
*/
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min_time = 1;
    sort(times.begin(), times.end(), greater<int>());
    long long max_time = (long long) n*times[0];
    while(min_time <= max_time){
        long long mid = (min_time + max_time) /2;
        
        long long count = 0;
        for(int i = 0; i < times.size(); i ++){
            count += mid / times[i];
        }
        // 현재 시간보다 더 줄일 수 있을 때 (주어진 시간에 n명보다 많이 처리할 떄)
        if(count >= n){
            answer = mid;
            max_time = mid -1;
        }
        // 시간이 더 필요할 때 
        else{
            min_time = mid + 1;
        }
    }
    return answer;
}