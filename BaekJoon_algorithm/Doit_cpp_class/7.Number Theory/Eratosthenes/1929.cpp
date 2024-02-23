#include<iostream>

using namespace std;
int main()
{
	int N, M;
	std::cin>>N>>M;
	int *arr = new int[M+1];
	for(int i = 1; i < M+1; i++)
	{
		arr[i] = i+1;
	}
	
	for(int i = 2; i < M+1; i++)
	{
		if(arr[i] == 0)
			continue;
		for(int j = i+i; j < M+1; j = j+i)
		{
			arr[j] = 0;
			//cout<<"!"<<"  ";
		}
		if(i >= N)
			cout<<i<<"\n";
	}
	delete[] arr;
	return 0;
}