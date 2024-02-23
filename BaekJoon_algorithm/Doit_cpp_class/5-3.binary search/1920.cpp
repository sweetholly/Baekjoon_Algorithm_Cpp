/*
#include<iostream>
#include<algorithm>

using namespace std;

int BinSearch(int temp, int *arr, int size);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int M;
	cin >> N;
	int *arr = new int[N];
	for(int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+N);
	cin >> M;

	for(int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cout<<BinSearch(temp, arr, N)<<'\n';
	}
	delete[] arr;
	return 0;
}

int BinSearch(int temp, int *arr, int size)
{
	int end = size -1;
	int start = 0;
	while(start <= end)
	{
		int mid = (start + end)/2;
		int midvalue = arr[mid];
		if(midvalue < temp)
		{
			start = mid + 1;
		}
		
		else if(midvalue > temp)
		{
			end = mid -1;
		}
		else
			return 1;
	}
	return 0;
}
*/