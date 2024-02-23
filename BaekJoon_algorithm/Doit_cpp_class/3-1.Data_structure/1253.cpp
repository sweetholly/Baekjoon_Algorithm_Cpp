/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int N;
	int front; 
	int back;
	int count = 0;
	
	cin >> N;
	front =0;
	back = 1;
	vector<long long>value(N,0);
	for(int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		value[i] = temp;
	}
	
	sort(value.begin(), value.end());
	
	for(int i = 0; i < N; i ++)
	{
		long long GoodNum = value[i]; // 비교할 값

		front = 0;
		back = N-1;
		while(front < back)
		{
			//cout << "value["<<front<<"] + value["<<back<<"] == "<<value[front] + value[back];
			if(value[front] + value[back] == GoodNum)
			{
				if(front != i && back!= i)
				{
					count ++;
					break;	
				}
				
				else if(front == i)
					front++;
				else if(back == i)
					back--;
			}
			
			else if(value[front] + value[back] > GoodNum)
			{
				back --;
			}
			
			else if(value[front] + value[back] < GoodNum)
			{
				front ++;
			}
		}
	}
	cout <<count<<'\n';
	return 0;
}*/