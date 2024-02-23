#include<iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int A,B;
		int calA;
		int calB;
		int result;
		cin >> A >> B;
		calA = A;
		calB = B;
		result = A;
		while(calB % calA != 0) {
			result = calB % calA;
			calB = calA;
			calA = result;
		}
		cout<<A*B/result<<"\n";
	}
	return 0;
}