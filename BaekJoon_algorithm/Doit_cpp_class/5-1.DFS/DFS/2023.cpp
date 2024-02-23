/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//한자리 소수 = 2 3 5 7

bool isPrime(int x);
void DFS(int x, int N, int now);
static vector<int>arr;
int main()
{
	int N;
	cin >> N;
	for(int i = 2; i<=9; i++)
	{
		if(isPrime(i))
			DFS(i,N,1);
	}
	sort(arr.begin(), arr.end(), less<int>());
	for(int i = 0; i< arr.size(); i++)
	{
		cout<<arr[i]<<'\n';
	}
	return 0;
}


void DFS(int x, int N, int now)
{
	if(!isPrime(x))
		return;
	
	if(now == N)
	{
		arr.push_back(x);
		return;
	}
	
	for(int i = 1; i<=9; i++)
	{
		int n_x = x*10;
		DFS(n_x+i, N, now+1);
	}
}

bool isPrime(int num)
{
	for(int i = 2; i <= num/2; i++)
	{
		if(num % i == 0)
		{
			return false;
		}
	}
	return true;
}
*/