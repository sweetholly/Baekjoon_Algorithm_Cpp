/*
#include<iostream>
#include<deque>
#define endl '\n'

using namespace std;

int main()
{
	deque<int>cirq;
	int min = 0;
	int left =0;
	int right = 0;
	int N = 0;
	int M = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cirq.push_back(i+1);
	}
	
	for(int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		for(int j = 0; j< cirq.size(); j++)
		{
			if(cirq[j] == num)
			{
				left = j;
				right = cirq.size()-j;
			}
		}
		
		//cout << left<<"  "<<right<<'\n';
		
		if(left > right)
		{
			//cout<<"right == "<<right<<",  + "<<right<<'\n';
			min += right;
			for(int j = left+1; j <= cirq.size(); j++)
			{
				cirq.push_front(cirq.back());
				cirq.pop_back();
			}
			cirq.pop_front();
		}
		
		else
		{
			//cout<<"left == "<<left<<",  + "<<left<<'\n';
			min += left;
			for(int j = 0; j< left; j++)
			{
				cirq.push_back(cirq.front());
				cirq.pop_front();
			}
			cirq.pop_front();
		}
	}
	cout<<min;
	return 0;
}
*/