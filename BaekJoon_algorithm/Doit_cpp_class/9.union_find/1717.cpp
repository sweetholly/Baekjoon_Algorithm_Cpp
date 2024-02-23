#include<iostream>

using namespace std;

int find(int a);
void unionf(int a, int b);
bool check(int a, int b);
int *arr;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	arr = new int[N+1];
	for(int i = 0; i <= N; i++){
		arr[i] = i;
	}
	while(M--){
		int temp = 0;
		int a = 0,b = 0;
		cin >> temp >> a >> b;
		if(temp == 0){
			unionf(a,b);
		}
		
		else if(temp == 1){
			if(check(a,b) == false)
				cout<<"NO\n";
			else
				cout<<"YES\n";
		}
	}
	delete[] arr;
	return 0;
}

int find(int a){		//유니온 파인드 find 연산
	if(a == arr[a])
		return a;		//대표 노드값과 인덱스가 같다면 return 인덱스값
	else{
		return arr[a] = find(arr[a]);	
		//아닐 경우 대표 노드값을 find(arr[a])로 바꿔주며 재귀호출
	}
}

void unionf(int a, int b){		//유니온 파인트 uniton 연산
	a = find(a);		//a값을 arr[a]의 대표노드값으로
	b = find(b);		//b값을 arr[b]의 대표노드값으로
	if(a != b){			
		arr[b] = a;
	}
}

bool check(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a == b){
		return true;
	}
	else{
		return false;
	}
}