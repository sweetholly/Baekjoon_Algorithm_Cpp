/*
#include<iostream>


using namespace std;

int main()
{
	int N;
	int start_ptr = 1;
	int end_ptr = 1;
	int count = 1;
	int sum = 1;
	cin >> N;
	
	while(end_ptr != N)
	{
		if(sum > N)
		{
			sum -= start_ptr;
			start_ptr ++;
		}
		
		if(sum < N)
		{
			end_ptr ++;
			sum += end_ptr;
		}
		if(sum == N)
		{
			count ++;
			end_ptr++;
			sum += end_ptr;
		}
	}
	cout <<count;
	return 0;
}
*/