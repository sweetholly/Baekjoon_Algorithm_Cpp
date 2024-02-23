#include<iostream>

/*
유니온 파인드 코드
*/
using namespace std;
int find(int a, int*arr);
void unionfind(int a , int b, int*arr);
bool check(int a, int b, int*arr);
int main(){
	int N, M;
	int start;
	int *arr;
	bool result = true;
	cin >> N >> M;
	arr = new int[N+1];
	for(int i = 0; i <= N; i++){
		arr[i] = i;
	}
		
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			int temp;
			cin >> temp;
			if(temp == 1){
				unionfind(i, j, arr);
			}
		}
	}
	cin >> start;
	while(M--){
		int temp;
		cin >> temp;
		if(check(start, temp, arr) == false){
			result = false;
			break;
		}
		start = temp;
	}
	if(!result)
		cout<<"NO";
	else
		cout<<"YES";
	delete[]arr;
	return 0;
}

int find(int a, int*arr){
	if(arr[a] == a)
		return a;
	else
		return arr[a] = find(arr[a], arr);
}

void unionfind(int a , int b, int*arr){
	a = find(a, arr);
	b = find(b, arr);
	if(a != b){
		arr[b] = a;
	}
}

bool check(int a, int b, int*arr){
	a = find(a, arr);
	b = find(b, arr);
	if(a == b)
		return true;
	else
		return false;
}



/*
DFS 코드
*/