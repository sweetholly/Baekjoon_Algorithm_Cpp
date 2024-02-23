#include<iostream>
#include<utility>
#include<deque>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;
int main()
{
	int N;
	int count = 1;
	int index = 0;
	p current;
	deque<p>meeting;
	cin>>N;
	for(int i = 0; i< N; i++)
	{
		int start, end;
		cin >> start >>end;
		meeting.push_back(make_pair(end, start));
	}
	
	sort(meeting.begin(), meeting.end());
	/*cout<<"\n\n";
	for(int i = 0; i < N; i++)
	{
		cout<<meeting[i].first<<"  "<<meeting[i].second<<"\n";
	}*/
	current.first = meeting.front().first;
	current.second = meeting.front().second;
	meeting.pop_front();
	
	while(!meeting.empty())
	{
		if(current.first <= meeting.front().second)
		{
			current.first = meeting.front().first;
			current.second = meeting.front().second;
			count++;
		}
		meeting.pop_front();
	}
	cout << count;
}
