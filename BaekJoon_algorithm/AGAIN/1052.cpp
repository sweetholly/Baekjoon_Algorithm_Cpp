#include<iostream>
using namespace std;

/*
	1. 같은 용량을 지닌 물을 나를 수 있다
	2. 
	1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> 128 -> 256 -> 512 ->
	
*/

int main(){
	int N, K;
	int answer = 0;
	cin >> N >> K;
	if(K >= N){
		cout<<"0";
		return 0;
	}

	while(1){
		int cnt = 0;
		int temp = N;
		while(temp > 0){
			if(temp % 2 != 0){
				cnt ++;
			}
			temp /= 2;
		}
		if(cnt <= K){
			//cout<<cnt<<" "<<K<<"\n";
			break;
		}
		
		N++;
		answer++;
	}
	cout << answer;
	return 0;
}