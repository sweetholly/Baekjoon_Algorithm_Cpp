/*
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> node;
void push_oper(int from, int got, int value, stack<int>&send, stack<int>&recieve, queue<node>&record);
int main()
{
	queue<node>record;			//이동 로그
	vector<int>sq;				//하노이탑 순서
	stack<int>first;			//첫 번째 기둥
	stack<int>second;			//두 번째 기둥
	stack<int>third;			//세 번째 기둥
	
	int N;
	int select_top = 1;
	int K = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin>>temp;
		sq.push_back(temp);
		first.push(temp);
	}
	sort(sq.begin(), sq.end());
	while(!sq.empty())
	{
		if(select_top== 1)
		{
			while(!first.empty())
			{	if(first.top() == sq.back()) //남아있는 가장 큰 수를 선택한 경우
				{
					//cout<<"move "<<first.top()<< ",  1 to 3"<<'\n';
					push_oper(1,3,first.top(),first,third, record);
					sq.pop_back();
					K++;
				}
				else
				{
					//cout<<"move "<<first.top()<< ",  1 to 2"<<'\n';
					push_oper(1, 2, first.top(), first, second, record);
					K++;
				}
			}
			select_top = 2;
		}	
		else
		{
			while(!second.empty())
			{
				if(second.top() == sq.back()) //남아있는 가장 큰 수를 선택한 경우
				{
					//cout<<"move "<<second.top()<< ",  1 to 3"<<'\n';
					push_oper(2,3,second.top(),second,third, record);
					sq.pop_back();
					K++;
				}
				else
				{
					//cout<<"move "<<second.top()<< ",  2 to 1"<<'\n';
					push_oper(2, 1, second.top(), second, first, record);
					K++;
				}
			}
			select_top = 1;
		}
	}
	cout<<K<<'\n';
	while(!record.empty())
	{
		cout<<record.front().first<<" "<<record.front().second<<'\n';
		record.pop();
	}
	return 0;
}
void push_oper(int from,int got, int value, stack<int>&send, stack<int>&recieve, queue<node>&record)
{
	node move;
	recieve.push(value);
	send.pop();
	move.first = from;
	move.second = got;
	record.push(move);
}

*/