#include<iostream>
#include<vector>
using namespace std;
int main(){
	cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    vector<long long>arr;
	long long N , M;
	long long result = 0;
	long long left = 1, right = 1, mid;
	cin >> N >> M;
	for(long long i = 0; i < N; i++){
		long long temp;
		cin >> temp;
		arr.push_back(temp);
		if(temp > right){
			right = temp;
		}
	}
	/*
		mid => 톱의 높이
			- 톱의 높이가 높아질수록, 가져갈 수 있는 나무의 길이는 줄어든다
		
		1. if(count >= M) -> 나무 길이가 목표치거나 더 긴 경우
			- left ++ : 톱의 높이를 늘리고(자를 나무의 길이를 줄인다)
			- 톱의 최고 높이를 갱신한다.
		
		2. else -> 나무 길이가 목표치보다 더 짧은 경우
			- 톱의 높이를 낮춘다(자를 나무의 길이를 늘린다)
	*/
	while(left<=right){
		mid = (left + right) / 2;
		long long count = 0;
		for(const auto& i : arr){
			if(i > mid) {
				count += (i - mid);
			}
		}
		
		//나무 길이가 목표치거나 더 긴 경우
		if(count >= M){
			left = mid+1;
			result = mid;
		}

		else{
			right = mid-1;
		}
		//cout<<"result : "<<result<<" mid : "<<mid<<"\n";
	}
	cout<< result;
	return 0;
}