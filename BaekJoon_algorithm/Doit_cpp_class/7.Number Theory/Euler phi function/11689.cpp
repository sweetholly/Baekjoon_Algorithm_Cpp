#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long N;
	long long temp;
	cin>>N;
	temp = N;
	for(long long i = 2; i*i <= N; i++) { //2 부터 N의 제곱근 까지 반복
		if(temp % i == 0) { //temp값이 i로 나뉘어 떨어지는 경우
			//cout<<"temp("<<temp<<") -=" <<temp<<'/'<<i<<"  N : ";
			temp -= temp/i;
			while(N % i == 0){
				N /= i;
			}		
			//cout<<N<<",  temp : "<<temp<<"\n";
		}
	}
	if(N > 1){ //제곱근까지 계산하므로 N이 남는경우 처리
		temp -= temp/N;
	}
	
	cout << temp;
	return 0;
}