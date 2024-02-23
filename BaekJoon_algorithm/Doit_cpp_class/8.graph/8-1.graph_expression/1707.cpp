/*
변수
K 반복 횟수
V 정점 개수
E 간선 개수
-E번 반복...
	u, v = 인접한 두 정점의 번호


vector<int>에 저장하여 인접하지 않는 정점을 표시
제한시간이 2초....
이분 탐색으로 구해보자

---> 서로 안 만나는 애들 2개 집단으로 모아보자....
	 만나는 경우의 수를 저장하자
	 vector에서 원소 하나를 삭제하는 시간복잡도는 O(N)이다.
*/
/*
	----> erase 를 통해 N회 순회를 통한다... E * 2 * O(N)의 시간복잡도가 생겼음 ㅅㅂ
	----> arr[i] --> i번째 종점이 연결되지 않은 종점을 보여준다. == 안 만나는 점끼리 조합할 수 있다.
	----> 
	----> 내일 자고 일어나사ㅓ 하자 ㅎㅎ..무조건 6 30에 일어날거다 ㅅㅂ 10:50 ~ 11:50 까지 약 한 시간정도 고민함.
*/
/*
	---> 조졌다 ㅅㅂ. 벡터끼리 비교해서 같은 벡터인게 확인되면 그대 실행하는 코드를 짰는데,,,,
		너무 무거워져서 어떤 방식을 취해봐도 메모리 초과가 뜬다....
		방법은 무엇일까,,,
		1. 배열로 다시짠다
		2. 고집 그만 부리고 DFS, BFS 로 다시 푼다.
*/

//실패한 코드
/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>>arr;
vector<int>point;


int main(){
	int K, V, E, u,v;
	cin >> K;
	while(K--){
		vector<vector<int>>check;
		cin >> V >> E;
		for(int i =1; i <= V; i++){
			point.push_back(i);
		}
		arr.assign(V+1, point);
		for(int i = 0; i < E; i++){
			cin >> u >> v;
			arr[u].erase(remove(arr[u].begin(), arr[u].end(), v), arr[u].end());
			arr[v].erase(remove(arr[v].begin(), arr[v].end(), u), arr[v].end());
		}
		for(int i = 1; i <= V; i++){	
			if(check.empty()){
				check.push_back(arr[i]);
				continue;
			}
			if(check.front() != arr[i] && check.back() != arr[i]){
				check.push_back(arr[i]);
				if(check.size() <= 2){
					continue;
				}
				else
					break;
			}
		}
		if(check.size() <= 2)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}

*/
/*
for(int i = 1; i <= V; i++){
	cout<<i<<" : ";
	for(const auto& j : arr[i])
		cout<<j<<" ";
	cout<<"\n";
}
cout<<"\n\n";
*/
		
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> arr;
vector<char>seperate;
vector<int>edge;
vector<bool>check;
bool isBipartite(int V);
void BFS(int node);

int main(){
	bool status;
	int K, V, E, u,v;
	cin >> K;
	while(K--){
		cin >> V >> E;
		arr.assign(V+1, edge);
		check.assign(V+1, false);
		seperate.assign(V+1, 'N');
		check[0] = true;
		for(int i = 0; i < E; i++){
			cin >> u >> v;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		for(int i = 1; i <= V; i++)
		{
			if(arr[i].empty())
				continue;
			if(!check[i])
				BFS(i);
		}
		
		 for(int i = 1; i <= V; i++)
			cout<<seperate[i]<<" ";
		cout<<"\n";
		status = isBipartite(V);
		if(status == false)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
	
void BFS(int node){
	queue<int>myq;
	myq.push(node);
	seperate[node] = 'R';
	check[node] = true;
	while(!myq.empty()){
		int front = myq.front();
		myq.pop();
		for(const auto& i : arr[front]){
			//cout<<"front : "<<front<<" i : "<<i<<"\n";
			if(check[i] == false){
				//cout<<i<<" is false\n";
				check[i] = true;
				if(seperate[front] == 'R')
					seperate[i] = 'B';
				else if(seperate[front] == 'B')
					seperate[i] = 'R';
				myq.push(i);
			}
		}
		cout<<"\n\n";
	}
}
	
	
/*
이분 그래프 판별
--> 1 ~ V; 까지 순회, arr[i] 를 탐색함
--> separate[i] 와 arr[i]의 요소의 seperate[] 값이 같은 경우 false 리턴
*/
bool isBipartite(int V){ 
	for(int i = 1; i <= V; i++){
		//cout << "i : "<<i<<" , seperate[i] :"<<seperate[i]<<"\n";
		for(const auto& j : arr[i]){
			//cout<<"j : "<<j<<", seperate[j] : "<<seperate[j]<<"\n";
			if(seperate[i] == seperate[j]){
				return false;
			}
		}
	}
	return true;
}