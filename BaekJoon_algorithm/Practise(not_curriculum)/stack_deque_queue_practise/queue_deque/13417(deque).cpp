/*
#include<iostream>
#include<deque>
#define endl '\n'

using namespace std;

int main()
{
	int T =0;
	int L = 0;
	char temp;
	cin >> T;
	for(int i = 0; i< T; i++)
	{
		cin >> L;
		deque<char>dq;
		for(int j = 0; j< L; j++)
		{
			cin >> temp;
			if(dq.empty())
			{
				dq.push_back(temp);
			}
			else
			{
				if(dq.back() <= temp || dq.front() < temp)
				{
					dq.push_back(temp);
				}
				else if(dq.front() >= temp)
				{
					dq.push_front(temp);
				}
			}
		}
		
		while(!dq.empty())
		{
			cout<<dq.front();
			dq.pop_front();
		}
		cout<<endl;
	}
}
*/