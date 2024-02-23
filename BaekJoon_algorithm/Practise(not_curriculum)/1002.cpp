#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x1, y1, x2,y2, r1, r2;
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//두 점의 직선거리
		int dis = pow(x1 - x2,2) + pow(y1 - y2,2);	
		int c1 = pow(r1-r2 ,2);
		int c2 = pow(r1 + r2,2);
		//1. 두 점이 같은 경우
		if(x1 == x2 && y1 == y2){
			if(r1 == r2)	//반지름의 길이가 같은 경우
				cout<<"-1\n";
			else			//길이가 다르면 만날 일이 없다.
				cout<<"0\n";
		}
		else if(dis == c1 || dis == c2){
			cout<<"1\n";
		}
		else if(dis > c1 && dis < c2){
			cout<<"2\n";
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}