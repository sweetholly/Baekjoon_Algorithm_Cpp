#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a, string b);
void pop_front(vector<string> &v);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<string>arr;
	int N;
	string temp;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	
	/*for(auto i : arr){
		cout<<i<<" ";
	}cout<<"\n";*/
	string before = arr[0];
	for(int i = 1; i < arr.size(); i++){
		cout<<arr[i]<<"  "<<before<<"\n";
		if(arr[i].find(before) == 0){ 
			/*
				find == 문자열이 포함된 시작 위치를 반환
				같은 문자열에 포함되어도 반환된 위치가 0이 아닐 경우 
				접두가사 아니다.
			*/
			N--;
		}
		before = arr[i];
	}
	cout<< N;
	return 0;
}
