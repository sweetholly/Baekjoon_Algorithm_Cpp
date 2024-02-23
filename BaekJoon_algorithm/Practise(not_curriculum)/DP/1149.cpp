/*
	DP 문제 Dynamic Programming(동적 계획법)
		- 하나의 큰 문제를 여러 작은 문제로 나누어 큰 문제를 해결함
		-> 큰 문제를 작은 문제로 쪼개서 그 답을 저장해두고 재활용
		----> 각각 개별로 나눠서 푸는 그리디와 정 반대이다.
		
		
	DP 의 사용 조건
	1. Overlapping Subproblmes(겹치는 부분 문제)]
	2. Optimal Substructure(최적 부분 구조) --> 그리디와 마찬가지이다.
	
	Overlapping Subproblems:
	- 문제를 나누고 그 문제의 결과 값을 재활용해서 전체 답을 구한다. 
	- 동일한 작은 문제들이 반복해서 나타는 경우 사용 가능.
	****
		부분 문제가 반복적으로 나타나지 않는다면 재사용이 불가능하니 
		부분 문제가 중복되지 않는 경우에는 사용할 수 없다.
	*****
*/


#include<iostream>
#include<vector>
#include<algorithm>
#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;
int main(){
	vector<int>house;
	vector<vector<int>>arr;
	int N; 
	int sum = 0;
	cin >> N;
	arr.assign(N, house);
	for(int i = 0; i < N; i++){
		int r,g,b;
		cin >> r >> g >> b;
		arr[i].push_back(r); 
		arr[i].push_back(g); 
		arr[i].push_back(b);
	}

	for(int i = 1; i < N; i++){
		arr[i][RED] += min(arr[i-1][GREEN],arr[i-1][BLUE]);	
		arr[i][BLUE] += min(arr[i-1][GREEN],arr[i-1][RED]);	
		arr[i][GREEN] += min(arr[i-1][RED],arr[i-1][BLUE]);	
	}
	sum = min (arr[N-1][RED], min(arr[N-1][BLUE], arr[N-1][GREEN]));
	cout<<sum;
	return 0;
}