/*
#include<iostream>
#include<stack>
#define endl '\n'

using namespace std;

struct homework
{
	int score;
	int time;
};

int main()
{
	stack<homework>workspace;
	int K;
	int score = 0;
	cin>>K;
	cin.ignore();
	for(int i = 0; i< K; i++)
	{
		int is_work;
		cin>>is_work;
		if(is_work == 1)
		{
			//cout<<"new work!!   ";
			int score;
			int time;
			cin >> score;
			cin >>time;
			homework work = {score, time};
			workspace.push(work);
		}
		
		if(!workspace.empty())
		{
			workspace.top().time --;
			//cout<<workspace.top().time<<endl;
			if(!workspace.empty() && workspace.top().time == 0)
			{
				score += workspace.top().score;
				workspace.pop();
			}
		}
	}
	cout<<score;
	return 0;
}
*/