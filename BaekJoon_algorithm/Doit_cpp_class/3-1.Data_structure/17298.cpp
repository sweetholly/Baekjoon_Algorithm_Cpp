/*
#include<iostream>
#include<vector>
#include<stack>
#include<stack>

using namespace std;

typedef pair<int,int> node;
int main()
{
	int N;
	vector<int>Aarr;
	stack<node>NGE;
	
	cin >> N;
	Aarr.assign(N,-1);
	for(int i = 0; i < N; i ++)
	{
		int temp;
		cin >> temp;
		while(NGE.empty() == 0 && NGE.top().second < temp)
		{
			//cout<<"NGE is not empty ,top value : "<<NGE.top().first <<" "<<NGE.top().second<<'\n';
			Aarr[NGE.top().first] = temp;
			//cout << NGE.top().second<<"'s NGE is "<<temp<<'\n';
			NGE.pop();
		}	
		NGE.push(node(i,temp)); //순서(index) , value
		//cout << NGE.top().first<<"  "<<NGE.top().second<<'\n';
		//cout<<"input"<<'\n';
	}
	
	for(int i = 0; i < N; i++)
	{
		cout << Aarr[i] << " ";
	}
}

*/