
/*
#include<iostream>
#include<deque>
#define endl '\n'

using namespace std;

int main()
{
	int N = 0, K = 0, M = 0;
	cin >> N >> K >> M;
	int reverse = M;
	deque<int>yoh;
	for(int i = 1; i <= N; i++)
	{
		yoh.push_back(i);
	}
	while(!yoh.empty())
	{
		if(reverse > 0)
		{
			for(int i = 1; i < K; i++)
			{
				yoh.push_back(yoh.front());
			    yoh.pop_front();	
			}
			reverse --;
			cout << yoh.front()<<endl;
			yoh.pop_front();
		}
		
		else if(reverse <= 0)
		{
			if(reverse <= M*(-1))
			{	
				reverse = M;
				continue;
			}
				for(int i = 1; i < K; i++)
			{
				yoh.push_front(yoh.back());
			    yoh.pop_back();	
			}
			reverse --;
			cout << yoh.back()<<endl;
			yoh.pop_back();	
		}	
	}
	return 0;
}
*/