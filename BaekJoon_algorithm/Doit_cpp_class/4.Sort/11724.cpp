#include<iostream>
#include<vector>

using namespace std;
using std::vector;
using std::cin;
using std::cout;
using std::stack;

static stack<vector<int>> graph;
static stack<bool> check;
void DFS(int x);

int main()
{
	int point, line;
	int dfs_count = 0;
	
	cin >> point >> line;
	graph.resize(point + 1);
    for(int i = 0; i < point; i++)
	{
		int s, e;
		cin >> s >> e;
		A[s].push_back(s);
		A[e].push_back(e);
	}
	
	for(int i = 1; i < N+1; i++)
	{
		if(visited[i] == false)
		{	
			DFS(i);
			dfs_count++;
		}
	}
	cout<<dfs_count;
}

void DFS(int x)
{
	if(visited[x] == true)
	{
		return;
	}

	visited[x] = true;
	for(int i = 0; i< graph[x].length(); i++)
	{
		if(visited[graph[x][i]] == false)
			DFS(graph[x][i]);
	}
}