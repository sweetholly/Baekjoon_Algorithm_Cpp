/*
1~N 까지의 수에서 소수를 판별 할 때,
N의 제곱수를 n 이라고 하자. 
범위 내의 어떤 수도 n 보다 클 경우 제곱값이 N을 초과하게 된다.
따라서 에라토스 테네시의 체를 이용할 경우 탐색 범위는 sqrt(N) 을 기준으로 한다
--> 데이터 범위 확보 가능, 복잡도 감소(실행횟수 감소)...etc
*/


#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	long long A, B;
	int count = 0;
		
	cin >>A >> B;
	//cout<<A<<" "<<B<<"\n";
	vector<bool>arr;
	arr.assign(sqrt(B)+1, false);
		
	arr[0] = true; arr[1] = true;
	for(long i = 2; i<= sqrt(B)+1; i++) { 
		if(arr[i] == true) {
			continue;
		}
		
		for(long j = i+i; j <= sqrt(B)+1; j +=i) {
			arr[j] = true;
		}
	}	
	
	/*
		for(long j = 0; j < primary.size(); j ++) {
			cout<<primary[j]<<" ";
		}
		cout<<"\n";
		- 고려사항 1. 제곱으로 판단 X, 3~n 제곱의 수가 위에 포함되어 있을 수 있음.
				=> 조건문을 추가함, 일단 소수면 전부 곱해보고 결과값이 A미만이면 count 안 함
		- 고려사항 2. 이미 탐색한 적 있는 제곱수를 중복으로 선택할 수도 있음.
				=> 소수인데 중복으로 선택할리가,,,,
	*/
	
	for(long long a = 2; a<= sqrt(B); a++){
		if(arr[a] == false) {
			long long temp = a;
			long long AlmostPri = temp;
			while(AlmostPri <= B / temp)
			{
				AlmostPri *= temp;
				//cout<<AlmostPri<<" ";
				if(AlmostPri >= A)
					count ++;
			}
			//cout<<" !"<<"\n";
		}
	}	
	cout<<count;
	return 0;
}		