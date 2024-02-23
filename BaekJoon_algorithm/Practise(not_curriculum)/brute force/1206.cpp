#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	vector<int>aver;
	vector<int>comp;
	int N;
	int answer = 1;
	cin >> N;
	for(int i = 0; i < N; i++){
		int front, end;
		scanf("%d.%d",&front,&end);
		aver.push_back(end);
	}
	sort(aver.begin(), aver.end());

	for(double i =0; i<= 1001; i++){
		int count = 0;
		for(double j = 1; j <= i; j++){
			if(i == j){
				comp.push_back(0);
			}	
			else{
				comp.push_back(int((j*1000) / i));
			}
			for(const auto& K : aver){
				if(K == comp.back()){
					count++;
				}
				else if(K > comp.back())
					break;
			}	
		}
		
		if(count == N){
			answer = i;
			break;
		}
	}
	cout<<answer;
	return 0;
}