#include <string>
#include <vector>
#include <queue>
#include<utility> 
#include<iostream>

using namespace std;
/*
    edge = {a, b} -> a노드와 b노드에 간선이 있음
    
    1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인가? -> 1번 노드에서 따라갔을 때, 가장 멀리 있는 값이 무엇인가
    -> 1번 노드에서, 연결된 노드를 따라 다른 이어진 노드로 탐색
    -> pair 구조로 사용, first는 1번 노드로부터 거리, second는 방문 여부
*/
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 노드 간, 연결된 관계를 담기 위한 벡터 선언
    vector<vector<int>> vertexPerNum(n+1);
    for(int i = 0; i < edge.size(); i ++){
        vertexPerNum[edge[i][0]].push_back(edge[i][1]);
        vertexPerNum[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    q.push(1);

    //방문 여부 + 현재 깊이
    vector<pair<int, bool>> dist(n + 1, {0, false});
    dist[1] = {0, true};
    int maxdist = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < vertexPerNum[cur].size(); i++){
            int next = vertexPerNum[cur][i];
            // 아직 방문 안 한 노드 = second가 false
            if(!dist[next].second){
                dist[next].first = dist[cur].first + 1;
                dist[next].second = true;
                maxdist = max(maxdist, dist[next].first);
                q.push(next);
            }
        }
    }
    
    // 최댓값과 같은 거리의 노드 개수 세기
    for(int i = 1; i <= n; i++){
        if(dist[i].second && dist[i].first == maxdist) {
            //cout<<dist[i].first <<","<<dist[i].second<<" .. ";
            answer++;
        }
    }
    return answer;
}