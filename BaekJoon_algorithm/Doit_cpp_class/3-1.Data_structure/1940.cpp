/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int>value;
	int M , N;
	cin >> M;
	cin >> N;
	int front = 0, back = 1 , count = 0;
	for(int i = 0; i < M; i ++)
	{
		int temp;
		cin >> temp;
		value.push_back(temp);
	}
	while(front != M-1)
	{
		if(back == M)
		{
			front ++;
			back = front + 1;
		}
		if(value[front] + value[back] != N)
		{
			back ++;
		}
		if(value[front] + value[back] == N && back != M)
		{
			//cout <<value[front] <<'+'<<value[back]<<'='<<count+1<<'\n';
			back++;
			count++;
		}
	}
	cout << count;
}*/