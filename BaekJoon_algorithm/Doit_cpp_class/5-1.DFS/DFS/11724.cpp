
#include<iostream>
#include<vector>
using namespace std;


static vector<vector<int>> graph;
static vector<bool> check;
void DFS(int x);

int main()
{
	int point, line;
	int dfs_count = 0;
	
	cin >> point >> line;
	graph.resize(point + 1);
	check.resize(point +1);
	check.push_back(false);
    for(int i = 0; i < line; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
		check.push_back(false);
	}
	
	for(int i = 1; i < point+1; i++)
	{
		if(check[i] == false)
		{	
			DFS(i);
			dfs_count++;
		}
	}
	cout<<dfs_count;
}

void DFS(int x)
{
	if(check[x] == true)
	{
		return;
	}

	check[x] = true;
	for(int i : graph[x])
    {
        if(check[i] == false)
            DFS(i);
    }
    /*for(int i = 0; i< graph[x].size(); i++)
	{
		if(check[graph[x][i]] == false)
			DFS(graph[x][i]);
	}*/
}