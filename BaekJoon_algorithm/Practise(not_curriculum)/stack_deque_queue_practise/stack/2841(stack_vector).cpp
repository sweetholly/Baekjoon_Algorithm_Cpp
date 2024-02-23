/*
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	stack<int>st;
	vector<stack<int>>pushing_line(7, st);
	int N, P; //음의 수 , 플렛의 수
	int line;
	int selected_p;
	int movement =0;
	cin >> N >>P;
	while(N--)
	{
		cin>> line >> selected_p;
		if(pushing_line[line].empty())
		{
			pushing_line[line].push(selected_p);
			movement++;
			//cout<<"movement = "<<movement<<" , stack.top == "<<pushing_line[line].top()<<'\n';
			continue;
		}
		else
		{
			if(pushing_line[line].top() == selected_p)
				continue;
			else if(pushing_line[line].top() > selected_p)
			{
				while(!pushing_line[line].empty() && pushing_line[line].top() > selected_p)
				{
					//cout<<pushing_line[line].top()<<" is poped!"<<'\n';
					pushing_line[line].pop();
					movement++;
				}
				if(pushing_line[line].empty() || pushing_line[line].top() < selected_p)
				{
					pushing_line[line].push(selected_p);
					movement++;
				}
			}
				
				else if(pushing_line[line].top() < selected_p)
				{
					pushing_line[line].push(selected_p);
					movement++;
				}
		}
		//cout<<"movement = "<<movement<<" , stack.top == "<<pushing_line[line].top()<<'\n';
	}
	cout<<movement;
	return 0;
}*/