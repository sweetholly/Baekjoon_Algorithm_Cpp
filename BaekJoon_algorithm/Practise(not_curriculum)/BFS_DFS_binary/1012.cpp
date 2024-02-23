#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int, int> p;
p way[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
vector<vector<int>>map;
vector<vector<bool>>check;

void DFS(int front, int back, int M, int N);

int main(){
	int T, M, N, K;
	int count = 0;
	cin>>T;
	while(T--)
	{
		cin>>M>>N>>K;		//M :가로길이  || N : 새로길이
		check.assign(N, vector<bool>(M,false));
		map.assign(N, vector<int>(M,0));
		for(int i = 0; i <K; i++)
		{
			int X, Y;
			cin>>X>>Y;
			map[Y][X] = 1;
		}
		/*
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				cout<<map[i][j]<<' ';
			}
			cout<<'\n';
		}*/
		
		//cout<<"\nstart"<<'\n';
		for(int i = 0; i <N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				//cout<<"checked : "<<i<<", "<<j<<'\n';
				if(check[i][j] == false && map[i][j] == 1)
				{
					DFS(i, j, M, N);
					count ++;
				}
			}
		}
		cout<<count<<'\n';
		count = 0;
	}
	
}

void DFS(int front, int back, int M, int N)
{

	if(check[front][back] == true)
	{
		return;
	}
	//cout<<"inside"<<'\n';
	check[front][back] = true;
	for(int i = 0; i<4; i++)
	{
		int nFront = front + way[i].first;
		int nBack = back + way[i].second;
		if(nFront >= 0 && nBack >= 0 && nFront < N && nBack < M)
		{
			if(check[nFront][nBack] == false && map[nFront][nBack] == 1)
				DFS(nFront, nBack, M, N);
		}
	}
}

