/*
#include<iostream>
#include<deque>

using namespace std;

int main()
{
	deque<int>st;
	int N;
	cin >> N;
	for(int i =  N; i >0; i--)
	{
		st.push_front(i);
	}
	
	while(st.size() > 1)
	{
		int front = 0;
		front = st.front();
		cout << front<<" ";
		st.pop_front();
		
		front = st.front();
		//cout << front <<'\n';
		st.push_back(front);
		st.pop_front();
	}
	cout<<st.front();
}
*/