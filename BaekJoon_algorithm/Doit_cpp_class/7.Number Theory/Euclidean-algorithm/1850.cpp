#include<iostream>

using namespace std;

int main() {
	long long N, M;
	long long temp = 1;
	cin >> N >> M;
	while(M % N != 0) {
		//cout <<"mod("<<M<<", "<<N<<") "<<M % N<<"\n";
		temp = M % N;
		M = N;
		N = temp;
	}
	for(int i = 0; i< temp; i++) {
		cout<<1;
	}
	return 0;
}