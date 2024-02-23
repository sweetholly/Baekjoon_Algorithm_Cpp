/*
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void DFS(int V,vector<vector<int>> &arr, vector<bool> &check);
void BFS(int V,vector<vector<int>> &arr, vector<bool> &check);

int main()
{
	vector<vector<int>>arr;
	vector<bool>check;
	int N, M, V;
	cin>> N >> M >> V;
	arr.resize(N+1);
	check.assign(N+1, false);
	for(int i =0; i < M; i++)
	{
		int point1, point2;
		cin>>point1 >> point2;
		arr[point1].push_back(point2);
		arr[point2].push_back(point1);
	}
	
	for(int i = 1; i<= N; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}
	DFS(V,arr,check);
	cout<<'\n';
	check.assign(N+1, false);
	BFS(V, arr, check);
	return 0;
}

void DFS(int V,vector<vector<int>>&arr, vector<bool>&check)
{
	if(check[V] == true)
		return;
	check[V] = true;
	cout<<V<<' ';
	for(int i = 0; i < arr[V].size(); i++)
	{
		if(check[arr[V][i]] == false)
			DFS(arr[V][i], arr, check);
	}
}

void BFS(int V,vector<vector<int>>&arr, vector<bool>&check)
{
	queue<int>myq;
	myq.push(V);
	check[V] = true;
	while(!myq.empty())
	{
		int cur_node = myq.front();
		myq.pop();
		cout << cur_node<<' ';
		for(int i = 0; i < arr[cur_node].size(); i++)
		{
			if(check[arr[cur_node][i]] == false)
			{
				check[arr[cur_node][i]] = true;
				myq.push(arr[cur_node][i]);
			}
		}
	}
}*/