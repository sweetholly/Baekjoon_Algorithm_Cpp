/*
#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	int sum[100001] = {};
	cin >> N >> M;
	for(int i = 1; i<=N; i++)
	{
		int temp;
		cin >> temp;
		sum[i] = temp+sum[i-1];
	}
	for(int i = 0; i< M; i++)
	{
		int a, b;
		cin >> a>>b;
		cout <<sum[b] - sum[a-1]<<'\n';
	}
}*/