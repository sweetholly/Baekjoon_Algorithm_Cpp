#include<iostream>
using namespace std;
int main(){
	int N, R1, C1, R2, C2;
	cin >> N >> R1 >> C1 >> R2 >> C2;
	for(int i = R1; i <= R2; i++){
		int r, c;
		for(int j = C1; j <= C2; j++){
			r = i % (2*N -1);			//가로 전체 길이
			c = j % (2*N -1);			//세로 전체 길이
			if(r > N -1)				//중앙값보다 큰 경우
				r = 2*(N-1) -r;			//중앙값 내부로 맞춰준다
			if(c > N -1)
				c = 2*(N -1) -c;
			if(r + c < N -1)
				cout<<".";
			else
				cout<<(char)('a'+(2*(N-1) - (r+c)%26));
		}
		cout<<"\n";
	}
	return 0;
}