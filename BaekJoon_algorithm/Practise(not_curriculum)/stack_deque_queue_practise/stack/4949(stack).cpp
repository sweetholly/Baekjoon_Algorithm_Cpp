/*
#include<iostream>
#include<stack>
#include<string>
#define endl '\n'
using namespace std;

int main()
{
	string input = " ";
	while(input != ".")
	{
		stack<char>st;
		getline(cin, input,'\n');
		if(input == ".")
			continue;
		//cout<<"\n\n\n";
		for(int i = 0;  i < input.length(); i++)
		{
			char now = input[i];
			if(now == '[' || now == ']' || now == '(' || now == ')')
			{
				if(!st.empty()) //stack에 위의 문자들 중 하나가 포함된 경우
				{
					if(st.top() == '[' && now == ']')
						st.pop();
					else if(st.top() == '(' && now == ')')
						st.pop();
					else
						st.push(now);
				}
				else
					st.push(now);
			}
			else
				continue;
		}
		if(st.empty())
		{
			//cout <<input<<endl;
			cout<<"yes"<<endl;
		}
		else
		{
			//cout <<input<<endl;
			cout<<"no"<<endl;
		}
	}
}
*/