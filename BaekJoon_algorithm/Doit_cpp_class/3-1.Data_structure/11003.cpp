/*
#include<iostream>
#include<vector>
#include<deque>
#include<utility>
using namespace std;
typedef pair<int , int> node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	int count = 0;
	cin >> N >> L;
	vector<int>Aarr;
	deque<node>findD;
	for(int i = 0; i < N; i ++)
	{
		int temp;
		cin >> temp;
		Aarr.push_back(temp);
	}
	for(int i = -L+1; i < N; i++)
	{
		if(i < 0)
		{
			count ++;
			continue;
		}
		
		while(findD.empty() == 0 && findD.back().second > Aarr[i])
		{
			findD.pop_back();
		}
		findD.push_back(node(i,Aarr[i]));
		count++;
		
		if(count == L)
		{
			//cout << "index : "<<findD.front().first<<"     i : "<< i <<"     "<<findD.front().second<<'\n';
			cout <<findD.front().second<<" ";
			count --;
			if(findD.front().first == i-L+1)
			{
				//cout << "index : "<<findD.front().first<<"     i : "<< i <<'\n';
				findD.pop_front();
			}
				
		}
	}
}
*/