/*
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int checkFront(int front, int nowtimes, vector<bool>&check, vector<vector<int>>&prev, vector<int>&times);

int main(){
	vector<int>indegree;		// 해당 건물을 거쳐야 하는 건물의 수
	vector<vector<int>>A;		// 해당 인덱스의 건물을 짓는데 필요한 건물들
	vector<int>time;			// 해당 인덱스의 건물을 짓는데 걸리는 시간
	int N;
	cin >> N;
	time.resize(N+1);
	A.resize(N+1);
	indegree.assign(N+1, 0);
	for(int i = 1; i <= N; i++) {
		int require;  int temp = 0;
		cin >> require;
		time[i] = require;		//인덱스 실행에 걸리는 시간
		while(1){
			cin >> temp;
			if(temp == -1){
				break;
			}
			else{
				A[temp].push_back(i);
				indegree[i]++;
			}
		}
	}
	queue<int> myq;
	for(int i = 1; i <= N; i++){
		if(indegree[i] == 0){
			myq.push(i);
		}
	}
	vector<int> result;
	result.resize(N+1);
	while(!myq.empty()){
		int now = myq.front();	//indegree == 0인 인덱스(건물)
		myq.pop();
		for(int next : A[now]){
			indegree[next]--;
			result[next] = max(result[next], result[now] + time[now]);
			if(indegree[next] == 0){
				myq.push(next);
			}
		}
	}
	for(int i = 1; i <= N; i++){
		cout<<result[i] + time[i]<<"\n";
	}
	return 0;
}
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	vector<int>timeNeeds;				// 건설 소요 시간
	vector<vector<int>>prev;			// 선행 건물
	vector<int>count;					// 필요한 선행 건물 수
	vector<int>result;					// 정답
	queue<int>myq;						// 위상정렬
	int N;
	cin >> N;
	timeNeeds.resize(N+1);
	prev.resize(N+1);
	count.resize(N+1);
	result.resize(N+1);
	for(int i = 1; i <= N; i ++){
		int temp;
		cin >> temp;
		timeNeeds[i] = temp;
		while(1){
			cin >> temp;
			if(temp == -1){
				break;
			}
			else{
				prev[i].push_back(temp);
				timeNeeds[temp]++;
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		if(timeNeeds[i] == 0){
			myq.push(i);
		}	
	}
	while(!myq.empty()){
		int temp = myq.front();
		myq.pop();
		for(const auto& i : prev[temp]){
			count[i] --;
			result[i] = max(result[i], result[temp] + timeNeeds[i]);
			if(count[i] == 0){
				myq.push(i);
			}
		}
	}
	for(int i = 1; i <= N; i++){
		cout<<result[i] + timeNeeds[i]<<"\n"; 
	}
	return 0;
}