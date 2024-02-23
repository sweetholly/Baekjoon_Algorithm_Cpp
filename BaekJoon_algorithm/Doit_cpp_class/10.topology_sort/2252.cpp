#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	vector<vector<int>>arr;
	vector<int>line;
	queue<int>myq;
	int N, M;
	cin >> N >> M;
	arr.resize(N+1);
	line.resize(N+1);
	for(int i = 0; i < M; i++){
		int front, back;
		cin >> front >> back;
		arr[front].push_back(back);
		line[back]++;
	}

	//line : 한 숫자를 가리키고 있는 (뒤에 서있는) 수
	//arr : 각 숫자와 그 숫자 앞에 있는 수를 저장한 이차원 벡터
	for(int i = 1; i <= N; i++){
		if(line[i] == 0)
			myq.push(i);
	}
	while(!myq.empty()){
		int now = myq.front();
		myq.pop();
		cout<<now<<" ";
		for(auto i : arr[now]){
			line[i]--;
			if(line[i] == 0){
				myq.push(i);
			}
		}
	}
	return 0;
}