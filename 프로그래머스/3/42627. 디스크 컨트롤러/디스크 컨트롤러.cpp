#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
    시간 > 요청 > 번호 작은 것
    비선점형
    일종의 비선점SJF?
*/
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int completed = 0;
    int jobIndex = 0;
    int n = jobs.size();
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue
        <
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > 
        workQueue;
    
    while(completed < n){
        //현재 시간과, jobs 벡터 맨 앞의 일의 입력 시간 비교
        while (jobIndex < n && jobs[jobIndex][0] <= currentTime)         {
            workQueue.push({jobs[jobIndex][1], jobs[jobIndex][0]});
            jobIndex++;
        }
        if (workQueue.empty()) {
            currentTime = jobs[jobIndex][0];
            continue;
        }
        auto [work_time, requestTime] = workQueue.top();
        workQueue.pop();

        currentTime += work_time;
        totalTurnaroundTime += currentTime - requestTime;
        completed++;
    }
    answer = totalTurnaroundTime / n;
    return answer;
}