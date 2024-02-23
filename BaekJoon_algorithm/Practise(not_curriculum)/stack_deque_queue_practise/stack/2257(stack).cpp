/*
#include<iostream>
#include<stack>
#include<string>
#define endl '\n'

using namespace std;
int MakeChemic(string chemic, int& i);

int main()
{
	stack<int>weight;
	int result = 0;
	string chemic;
	cin >> chemic;
	for(int i = 0; i < chemic.length(); i++)
	{
		char ch = chemic[i];
		int sum = 0;
		if(ch == 'H')
			weight.push(1);
		
		else if(ch == 'C')
			weight.push(12);
		
		else if(ch == 'O')
			weight.push(16);
		
		else if(ch == '(')
		{
			//cout<<"inside"<<endl;
			weight.push(MakeChemic(chemic, ++i));
		}
		
		else
		{
			int top = weight.top();
			weight.pop();
			weight.push(top*(ch-'0'));
		}
		//cout<<weight.top()<<endl;
	}
	while(!weight.empty())
	{
		result += weight.top();
		weight.pop();
	}
	cout<<result;
	return 0;
}

int MakeChemic(string chemic, int& i)
{
	stack<int>cal;
	int result = 0;
	int ch = ' ';
	while(1)
	{
		//cout<<"( 연산 수행중   ";
		ch = chemic[i];
		if(ch == 'H')
			cal.push(1); 
		
		else if(ch == 'C')
			cal.push(12);
		
		else if(ch == 'O')
			cal.push(16);
		
		else if(ch == '(')
		{
			//cout<<"inside"<<endl;
			cal.push(MakeChemic(chemic, ++i));
		}
		else if(ch == ')')
		{
			//cout<<") 입력  ";
			break;
		}
		else
		{
			int top = cal.top();
			cal.pop();
			cal.push(top*(ch-'0'));
		}
		//cout<<cal.top()<<endl;
		i++;
	}
	
	while(!cal.empty())
	{
		result += cal.top();
		cal.pop();
	}
	return result;
}


*/