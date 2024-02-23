/*
#include<iostream>
#include<queue>
#include<stack>
#define endl '\n'

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int>q;
	stack<int>st;
	int N;
	int line = 1;
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	
	while(!q.empty() || line <= N)//
	{

		while(!st.empty() && st.top() == line)
		{
			line++;
			st.pop();
		}
		
		if(!q.empty()) //q에 값이 들어있는경우
		{
			if(q.front() == line)
			{
				q.pop();
				line ++;
			}
		
			else
			{
				st.push(q.front());
				q.pop();
			}
		}
				
		if((!st.empty() && q.empty() && st.top() != line) || (st.empty() && q.empty()))
		{
			break;
		}
		
	}

	if(st.empty())
		cout << "Nice\n";
	else
		cout << "Sad\n";
	return 0;
}*/