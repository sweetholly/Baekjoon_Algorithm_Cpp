#include<iostream>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int b;
	int first;
	int second;
	int temp;
	int total = 0;
	priority_queue<int, vector<int>, greater<int>>pq;
	cin>>b;
	for(int i = 0; i < b; i++)
	{
		cin >> temp;
		pq.push(temp);
	}
	while(pq.size()>1)
	{
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		total += (first+second);
		pq.push(first+second);
	}
	cout<<total;
	return 0;
}