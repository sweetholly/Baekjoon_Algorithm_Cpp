
/*
#include <iostream>
#include <queue>

using namespace std;
int main()
{
	queue<int>circle;
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		circle.push(i+1);
	}

	cout<<"<";
	while(!circle.empty())
	{
		for(int i = 0; i < K-1; i++)
		{
			circle.push(circle.front());
			circle.pop();
		}
		cout<<circle.front();
		circle.pop();
		if(!circle.empty())
			cout<<", ";
	}
	cout<<">";
}*/