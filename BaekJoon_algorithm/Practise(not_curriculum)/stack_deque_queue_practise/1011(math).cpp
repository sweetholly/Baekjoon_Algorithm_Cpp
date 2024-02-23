/*
#include<iostream>
#include<cmath>
#define endl '\n'
using namespace std;

int main()
{
	int T;
	int x;
	int y;
	cin >> T;
	for(int i = 0; i< T; i++)
	{
		cin >>x;
		cin >>y;
		long long range = y-x;
		long long sq = sqrt(range);
		//cout<<"value : "<<sq<<", range : "<<range<<endl;
		if(sq*sq < range && range <= sq*sq+sq)
			cout<<sq+sq<<'\n';
		else if(sq*sq+sq+1 <= range && range < (sq+1) * (sq+1))
			cout<<sq+sq+1<<'\n';
		else if(sq*sq == range)
			cout<<sq+sq-1<<'\n';
	}
	return 0;
}
*/