/*
	그리디 알고리즘
		- 
*/


#include<iostream>
#include<vector>

using namespace std;
vector<string>A;
vector<string>B;

void change(int x, int y){
	for(int i = x; i < 3+x; i++){
		for(int j = y; j < 3+y; j++) {
			if(A[i][j] =='0') A[i][j] = '1';
			else if(A[i][j] == '1') A[i][j] ='0';
			//cout<<A[i][j]<<" ";
		}
		//cout<<"\n";
	}
}

int main() {
	int N, M;
	int count = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string temp;
		cin >> temp;
		A.push_back(temp);
	}
	for(int i = 0; i < N; i++){
		string temp;
		cin >> temp;
		B.push_back(temp);
	}
	
	for(int i = 0; i < N-2; i++) { 
		for(int j= 0; j < M-2; j++) {
			if(A[i][j] != B[i][j]) {
				change(i, j);
				count ++;
			}
		}
	}
	//확인
	for(int i = 0; i< N; i++){
		if(A[i].compare(B[i]) != 0)
		{
			cout<<-1;
			return 0;
		}
	}
	cout <<count;
	return 0;
}

