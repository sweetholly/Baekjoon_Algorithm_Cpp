/*#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int>show;
	int N;
	int temp;
	cin >> N;
	cin >> temp;
	show.push(temp);
	for(int i = 1; i < N; i++)
	{
		cin >> temp;
		while(!show.empty() && show.top() <= temp)
		{
			show.pop();
		}
		show.push(temp);
	}
	cout<<show.size();
	return 0;
}*/