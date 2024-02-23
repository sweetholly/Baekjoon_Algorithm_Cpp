/*
#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;
int main()
{
	stack<int>st;
	int K =0;
	int count = 0;
	cin >> K;
	for(int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		if(temp == 0 && st.empty() != 1)
			st.pop();
		else if(temp != 0)
			st.push(temp);	
	}
	while(!st.empty())
	{
		count += st.top();
		st.pop();
	}
	cout << count;
}
*/