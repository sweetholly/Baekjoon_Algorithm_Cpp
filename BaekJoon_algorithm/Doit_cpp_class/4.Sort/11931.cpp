#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
    int N;
	int *arr;
	cin >> N;
	arr = new int[N];
	for(int i = 0; i<N; i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+N, compare);
	for(int i = 0; i< N; i++)
	{
		cout<<arr[i]<<'\n';
	}
}