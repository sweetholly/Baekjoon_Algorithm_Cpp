/*
	수 제한이 100000이므로 에라토스 테네스를 끝까지 돌려도 메모리/시간 초과 걱정 X
	에라토스테네스의 체를 이용 -> sqrt(B)의 소수의 개수를 구한다.
	
	
	signal: floating point exception (core dumped) : / 0 이 포함된 경우다.
*/

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int A, B;
	int count = 0;
	vector<bool>arr;
	vector<int>result;
	cin >> A >> B;
	arr.assign(B, false);
	arr[0] = true;
	arr[1] = true;
	for(int i = 2; i <= B; i++){
		if(arr[i] == true)
			continue;
		else
			result.push_back(i);
			
		for(long j = i + i; j <= B; j+=i)
			arr[j] = true;
	}

	for(int i = A; i <= B; i++){
		int temp = i;
		int curcount = 0;
		//cout<<"start , temp : "<<temp<<"\n";
		for(int j = 0; j < result.size(); j++){
			if(temp <= 1){
				break;
			}	
			while(temp % result[j] == 0){
				temp /= result[j];
				curcount ++;
			}	
		}
		if(arr[curcount] == false)
			count ++;
	}
	cout<<count;
	return 0;
}
