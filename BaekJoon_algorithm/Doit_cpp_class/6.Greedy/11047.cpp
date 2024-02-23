#include<iostream>
using namespace std;
int main()
{
	int arr[10] = {0,};
	int N, K;
	int temp;
	int count = 0;
	cin >> N >>K;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}
	N--;
	while(K > 0 && N >= 0)
	{
		if(arr[N] <= K)
		{
			while(K >= arr[N])
			{	
				K -= arr[N];
				count ++;
			}
		}
		N--;
	}
	cout<<count;
}