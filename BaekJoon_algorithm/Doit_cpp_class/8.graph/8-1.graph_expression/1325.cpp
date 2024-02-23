/*
한 번 해킹해서 여러개의 컴퓨터 해킹 --> 효율

신뢰관계 / 비신뢰 관계
A 가 B를 신뢰할 경우......B를 해킹하면 A도 해킹할 수 있음.
신뢰관계 --> 단방향 엣지
*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> p;
vector<int>computer;
vector<vector<int>>trust;
vector<int>most;
vector<bool>check;

int DFS(int node, int visit);
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int highest = 0;
	int N, M;
	cin >> N >> M;
	trust.assign(N+1, computer);
	check.assign(N+1, false);
	check[0] = true;
	//cout<<"input\n";
	for(int i = 0; i < M; i++){
		int A, B;
		cin >> A >> B;
		trust[B].push_back(A);
	}
	/*
	cout<<"start\n";
	cout<<"start\n";
	cout<<"start\n";
	cout<<"start\n\n";*/
	for(int i = 1; i <= N; i++){
		p hack = make_pair(DFS(i, 0), i);		//hack[방문 횟수, 시작 노드];
		for(int i = 1; i <=N; i++)
			check[i] = false;
		check[0] = true;
		if(highest < hack.first){				//방문 횟수가 최대 방문 횟수보다 더 많은 경우
			most.clear();						//기존 값 전부 삭제
			most.push_back(hack.second);		//시작 노드 추가
			highest = hack.first;				//최대 방문 횟수 갱신
		}
		else if(highest == hack.first){
			most.push_back(hack.second);
		}
	}
	
	for(const auto& i : most){
		cout<<i<<" ";
	}
	return 0;
}

int DFS(int node, int visit) {
	check[node] = true;
	for(const auto& i : trust[node]){
		if(check[i] == false){
			visit = DFS(i, visit+1);
			//cout<<"visit : "<<visit<<"\n";
		}
	}
	return visit;
}