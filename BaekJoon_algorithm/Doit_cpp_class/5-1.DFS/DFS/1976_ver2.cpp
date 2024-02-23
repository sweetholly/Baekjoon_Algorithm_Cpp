#include<iostream>
#include<vector>
/*
DFS 코드
*/
using namespace std;

vector<bool>check;
vector<int>city;
vector<vector<int>>arr;

void DFS(int start);
int main(){
	int N, M;
	int start = 0;
	cin >> N >> M;
	arr.assign(N, city);
	check.assign(N, false);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int temp;
			cin >> temp;
			if(temp == 1){
				arr[i].push_back(j);
			}
		}
	}

	
	while(M--){
		int temp; 
		cin >> temp;
		if(check[temp-1] == false){
			DFS(temp-1);
			start ++;
		}
	}
	if(start == 1) 
		cout<<"YES";
	else 
		cout<<"NO";
	return 0;
}

void DFS(int start){
	if(check[start] == true)
		return;
	check[start] = true;
	for(const auto &i : arr[start]){
		if(check[i] == false) {
			DFS(i);
		}
	}
}


/*
DFS 코드
*/