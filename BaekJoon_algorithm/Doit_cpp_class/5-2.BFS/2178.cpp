/*
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;
p way[4] = {make_pair(0,1),make_pair(0,-1),make_pair(-1,0),make_pair(1,0)};

void BFS(vector<vector<int>> &line,  vector<vector<bool>> &check, int N, int M);
int main()
{
	vector<vector<bool>>check;
	vector<vector<int>>line;
	int result = 0;
	int N, M;
	cin >> N >> M;
	line.resize(N);
	check.assign(N, vector<bool>(M,false));
	for(int i = 0; i < N; i++)
	{
		string temp;
		cin>>temp;
		//cout<<temp;
		for(int j = 0; j< M; j++)
			line[i].push_back(temp[j]-'0');
	}
	BFS(line, check, N, M);
	cout<<line[N-1][M-1];
}


void BFS(vector<vector<int>> &line, vector<vector<bool>> &check, int N, int M)
{
	queue<p> myq;
	myq.push(make_pair(0,0));
	while(!myq.empty())
	{
		int node_front = myq.front().first;
		int node_back = myq.front().second;
		myq.pop();
		check[node_front][node_back] = true;
		for(int i = 0; i<4; i++)
		{
			int x = node_front + way[i].first;
			int y = node_back + way[i].second;
			if((x >= 0 && y>= 0) && (x< N && y < M))
			{
				if(line[x][y] != 0 && check[x][y] == false)
				{
					check[x][y] = true;
					line[x][y] = line[node_front][node_back]+1;
					myq.push(p(x,y));
				}
			}
		}
	}
}
*/