/*
#include <iostream>
#include <stack>
#define endl '\n'

using namespace std;

int main()
{
	string line;
	stack<char>st;
	int count = 0;
	cin >> line;
	cin.ignore();
	
	for(int i = 0; i < line.length(); i++)
	{
		if(!st.empty())
		{	
			if(st.top() == '(' && line[i] == ')')
			{		
				st.pop();
				continue;
			}
			else 
				st.push(line[i]);
		}
		 else
		{
			st.push(line[i]);
		}
	}
	cout<<st.size();
	return 0;
}
*/