/*
#include<iostream>
#include<deque>
#include<utility>
#define endl '\n'
using namespace std;
typedef pair<int , int> node;


int main()
{
	deque<node>cirq;
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		cirq.push_back(node(i, temp));
	}
	
	while(!cirq.empty())
	{
		int move = 0;
		cout<<cirq.front().first<<" ";
		move = cirq.front().second;
		cirq.pop_front();
		
		if(move >= 0)
		{
			for(int i = 0; i < move-1; i++)
			{
				cirq.push_back(cirq.front());
				cirq.pop_front();
			}
		}
		
		else
		{
			for(int i = 0; i < move*(-1); i++)
			{
				cirq.push_front(cirq.back());
				cirq.pop_back();
			}
		}
		
	}
	return 0;
}

*/