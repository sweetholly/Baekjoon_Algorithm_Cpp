#include<iostream>

using namespace std;

int main()
{
	int N, d, k, c; //점시 수, 초밥의 가짓수, 연속 접시수, 쿠폰
	int sushi[6001] = {0,};   //초밥 번호당 등장 횟수
	
	int front = 0;
	int back = 0;
	int c_used = 0;
	
	int cur_value = 0;	
	int max_value =0;
	
	cin >> N >> d>>k >> c;
	int *arr = new int[N];
	front = 0;
	back = k-1;
	for(int i = 0; i<N; i++)
	{
		int temp;
		cin>> temp;
		arr[i] = temp;
		if(i < k)
		{
			sushi[temp]++;
			if(sushi[temp] <= 1)
				max_value++;
		}
	}
	cur_value = max_value;
	if(sushi[c] == 0)
		c_used = 1;
	
	while(front < N)
	{
		sushi[arr[front]]--;
		if(sushi[arr[front]] < 1)
			cur_value --;
		
		front++;
		back++;
		
		if(back >= N)
			back = 0;
		else if(front >= N)
			break;
		
		sushi[arr[back]]++;
		if(sushi[arr[back]] == 1)
			cur_value++;
		if(max_value <= cur_value)
		{
			if(max_value == cur_value)
			{
				if(sushi[c] < 1)
					c_used = 1;
			}
			else
			{
				if(sushi[c] < 1)
					c_used = 1;
				else
					c_used = 0;
				max_value = cur_value;
			}
		}
	}

	delete []arr;
	cout<<max_value+c_used;
    return 0;
}

