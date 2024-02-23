#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int,int>p;

vector<int>answer;			//조건을 만족하는 노드 저장
vector<p>g_node;			//pair vector을 위한 단위 저장
vector<vector<p>>graph;		//(노드,에지) pair 벡터
vector<bool>check;			//방문 확인 벡터
int N, M, K, X;
void BFS(int node);

int main(){
	cin>>N>>M>>K>>X;
	graph.assign(N+1, g_node);
	check.assign(N+1, false);
	
	graph[X].push_back(make_pair(X,0)); //시작점 초기화
	check[0] = true;
	
	for(int i = 1; i <= M; i++){
		int node , edge;
		cin >> node >> edge;
		graph[node].push_back(make_pair(edge,0));
	}

	if(K == 0) {
		cout<<X;
		return 0;
	}
	else{
		BFS(X);
		if(!answer.empty()){
			sort(answer.begin(), answer.end());
			for(int i = 0; i < answer.size(); i++){
				cout<<answer[i]<<"\n";
			}
		}
		
		else{
			cout <<-1;
		}
		return 0;
	}	
}

void BFS(int node){
	queue<p>q;						//노드 , 에지 pair 큐
	q.push(graph[node].front()); 	//node에 해당하는 pair을 q에 삽입
	check[node] = true;				//방문 체크
	while(!q.empty()){				//큐에 자료형이 남지 않을 때까지
		int front = q.front().first;
		int visit = q.front().second;
		q.pop();
		for(const auto& i : graph[front]){
			if(check[i.first] == false){
				q.push(make_pair(i.first, visit + 1));
				check[i.first] = true;
				if((visit + 1) == K) {
					answer.push_back(i.first);
				}
			}
		}
	}
}



/*
void DFS(int node, int visit){
	cout<<"node : "<<node<<" / visit : "<<visit<<"\n";
	if(!graph[node].empty()){
		for(auto i : graph[node]) {
			if(check[i] == false){
				cout<<i<<" is next node\n";
				check[i] = true;
				DFS(i, visit + 1);
			}
		}
	}
	
	if(check[node] == true){
		cout<<node<<" return\n";
		if(visit == K){
			cout<<"visited is "<<visit<<", count ++\n\n";
			count ++;
			return;
		}
		else
			return;
	}
}
*/