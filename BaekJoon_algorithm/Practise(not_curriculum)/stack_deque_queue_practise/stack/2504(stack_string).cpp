/*
#include<iostream>
#include<queue>
#include<string>
#include<stack>
using namespace std;

int CalResult(queue<int>&myq, stack<int>sheck);

int main()
{
	stack<int>check;
	string iscorrect;
	char top;
	int temp = 1;
	int result = 0;
	cin >> iscorrect;
	
	for(int i = 0; i < iscorrect.length(); i++)
	{
		char now;
		now = iscorrect[i];
		if(now == '(')
		{
			temp *= 2;
			check.push(now);
		}
		
		else if(now == '[')
		{
			temp *= 3;
			check.push(now);			
		}
		
		else if(now == ')')
		{
			if(check.empty() || check.top() != '(')
			{
				result = 0;
				break;
			}
			
			else if(iscorrect[i-1] == '(')
			{
				result += temp;
			}
			temp /= 2;
			check.pop();
		}
		
		else if(now == ']')
		{
			if(check.empty() || check.top() != '[')
			{
				result = 0;
				break;
			}
			
			else if(iscorrect[i-1] == '[')
			{
				result += temp;
			}
			temp /= 3;
			check.pop();
		}
	}
	if(!check.empty())
	{
		cout<<0;
		return 0;
	}
	cout<<result;
	return 0;
}
*/