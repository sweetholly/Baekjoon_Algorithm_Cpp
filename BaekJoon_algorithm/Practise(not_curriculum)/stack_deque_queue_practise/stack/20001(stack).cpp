/*
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	stack<int>work;
	string input;
	getline(cin, input);
	if(input == "고무오리 디버깅 시작")
	{
		while(input != "고무오리 디버깅 끝")
		{
			getline(cin,  input);
			if(input == "문제")
				work.push(1);
			else if(input == "고무오리")
			{
				if(!work.empty())
					work.pop();
				else
				{
					work.push(1);
					work.push(1);
				}
			}
			else if(input == "고무오리 디버깅 끝")
				continue;
		}
	}
	if(work.empty())
		cout<<"고무오리야 사랑해";
	else
		cout<<"힝구";
	return 0;
}*/