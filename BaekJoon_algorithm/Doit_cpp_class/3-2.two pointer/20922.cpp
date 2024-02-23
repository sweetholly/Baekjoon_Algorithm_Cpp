/*
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int check[100001] = {0,}; //동일 원소 갯수
	int array[200001];		  //입력한 배열
	
	int N, K;
	int max_length = 1;
	int temp_length = 0;
	int temp_number;
	int front = 1;
	int back = 1;
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
	{
		cin >> temp_number;
		array[i] = temp_number;
	}
	while(back <= N && front <= N)
	{
		while(check[array[back]] <= K)
		{
			check[array[back]] ++;
			temp_length++;
			cout<<"back pointer: "<<back<<",  value : "<<array[back]<<",  frequency : "<<check[array[back]]<<"\n";
			if(check[array[back]] > K)
			{
				if(max_length < temp_length-1)
					max_length = temp_length-1;
				break;
			}
			back++;
			
			if(back > N)
			{
				back --;
				break;
			}
		}
		cout<<temp_length-1<<endl;
		while(check[array[back]] > K)
		{
			check[array[front]] --;
			cout<<"front pointer: "<<front<<",  value : "<<array[front]<<",  frequency : "<<check[array[front]]<<"\n";
			front ++;
			temp_length--;
			if(front > N)
			{
				break;
			}
		}
		if(max_length < temp_length)
			max_length = temp_length;
		back++;
		cout<<temp_length<<endl;
	}
	cout<<max_length;
}
*/