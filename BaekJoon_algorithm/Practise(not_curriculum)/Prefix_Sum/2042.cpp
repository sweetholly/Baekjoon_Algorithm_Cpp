//--> 세그먼트 트리..?

#include<iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int *PrefixSum = nullptr;
	int *arr = nullptr;
	int N, M, K  = 0;
	int temp = 0;
	cin >> N >> M >> K;
	PrefixSum = new int[N];
	arr = new int[N];
	for(int i = 0; i < N; i++){
		cin >> temp;
		arr[i] = temp;
		if( i == 0){
			PrefixSum[i] = temp;
		}
		else {
			PrefixSum[i] = PrefixSum[i-1] + temp;
		}
	}
	while(K > 0 || M > 0){
		cin >> temp;
		if(temp == 2){
			K--;
			int start, end;
			cin >> start >> end;
			cout<<PrefixSum[end-1] - PrefixSum[start-2]<<"\n";
		}
		else if(temp == 1){
			M--;
			int index, prev, value, result;
			cin >> index >> value;
			prev = arr[index-1];
			result = value - prev;
			for(int i = index-1; i < N; i++){
				PrefixSum[i] -= prev;
				PrefixSum[i] += value;
			}
		}
	}
	delete[] PrefixSum;
	delete[] arr;
	return 0;
}



//이전 코드(파악 불가)
/*
#include<iostream>
#include<vector>


using namespace std;

int main()
{
	vector<long long>arr;
	vector<long long>prefix;
	int N = 0; //줄의 개수
	int M = 0; //수의 변경 횟수
	int K = 0; //구간 합 구하기
	
	long long a = 0; //명령 구분(1 == 교환 , 2 == 구간합)
	long long b = 0; //b번째 수
	long long c = 0; //c번째 수
	long long count = 0;
	cin >> N >> M >> K;
	arr.push_back(0);
	prefix.push_back(0);
	for(int i = 0; i< N; i++)
	{
		long long temp = 0;
		cin >> temp;
		prefix.push_back(prefix.back() + temp);
		arr.push_back(temp);
	}
	count = M+K;
	
	while(count--)
	{
		cin>>a>>b>>c;
		if(a == 1)  //b 번째 값을 c로 바꾸는 경우....
		{
			long long temp = c;  //바꿀 값을 임시로 지정
			for(long long i = b; i<= N; i++)	//합배열에 포함되는 범위까지 값 수정
			{
				prefix[i] = prefix[i] - arr[b] + c;
			}
			arr[b] = c;
		}
			
		else if(a == 2)
		{
			cout<<prefix[c] - prefix[b-1]<<'\n';
		}
	}
	return 0;
}

*/
//세그먼트 트리