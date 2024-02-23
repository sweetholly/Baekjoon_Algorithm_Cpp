#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>arr;
bool compare(int a , int b);
int main(){
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N, K;
	int count = 0;
	long long most = 0;
	long long left, right, mid;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);
	/*
		이분 탐색
		1. rigth = 1, left = 가장 큰 값의 끝 값, mid (left + right)/2
			while(left <= right)
		2. if(count > K) 면....
			left ++; --> mid값을 키우고
			최대값을 비교하여 지정한다.
		3. if(count < K) 면... 
			right --; --> mid값을 줄인다.
	*/
	left = 1; right = arr.front();
	
	while(left <= right){
		mid = (left + right) / 2;
		for(const auto& i : arr){
			count += i / mid;
		}
		//cout<<"mid :"<<mid<<" , "<<count<<"\n";
		if (count >= K) //현재값으로 나눴을 때 K보다 크거나 같으면
		{
			left = mid + 1;
			most = mid;
		}
		else //현재값으로 나눴을 때 K보다 작으면
		{
				right = mid - 1;
		}
		count = 0;
	}
	cout<<most;
	return 0;
}


//a 왼쪽 , b 오른쪽
bool compare(int a , int b){
	return a > b;
}