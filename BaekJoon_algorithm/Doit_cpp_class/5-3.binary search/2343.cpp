/*
#include<iostream>

using namespace std;


int main()
{
	int N, M;
	int temp;
	int start = 0;
	int end = 0;
	cin >> N >> M;
	int *video = new int[N];
	int *sum = new int[N];
	for(int i = 0; i< N; i++)
	{
		cin >> video[i];
		end += video[i];
		if(start < video[i])
			start = video[i] ;
	}
	sum[0] = video[0];
	for(int i = 1; i<N; i++)
	{
		sum[i] = video[i] + sum[i-1];
	}
	

	while(start <= end)
	{	int divPoint = 0;
		int divCount = 1;
		int middle  = (start+end)/2;
		for(int i = 0; i < N; i++)
		{
			if(sum[i]-divPoint > middle)
			{
				divCount++;
				divPoint = sum[i-1];
			}
		}
		if(divCount > M)
			start = middle+1;
		else
			end = middle-1;
	}
	cout<<start;
	delete[] video;
	delete[] sum;
}*/