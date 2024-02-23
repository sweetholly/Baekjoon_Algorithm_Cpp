/*
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string str[100];	
	int N = 0;
	int count = 0;
	cin >> N;
	for(int a = 0; a < N; a++)
	{
		cin >> str[a];
	}
	
	for(int i = 0; i < N; i++)
	{
		stack<char>st;
		for(int j = 0; j<str[i].length(); j++)
		{	
			if(!st.empty() && st.top() == str[i][j])
			{
				st.pop();
				continue;
			}
			else
				st.push(str[i][j]);
		}
		if(st.empty())
			count++;
	}
	cout<< count;
}
*/