/*
#include<iostream>
#include<cmath>
using namespace std;

void hanoi(int N, int start, int to, int pass);
int main()
{
	int N;
	int count = 0;
	cin >> N;
	cout<<(int)pow(2,N)-1<<'\n';
	hanoi(N, 1, 2, 3);
	return 0;
}

void hanoi(int N, int start, int pass, int end)
{
	if(N == 1)
	{
		cout<<start<<" "<<end<<'\n';
	}
	else
	{
		hanoi(N-1, start, end, pass);
		cout<<start<<" "<<end<<'\n';   		
		hanoi(N-1, pass, start, end);
	}
}

*/