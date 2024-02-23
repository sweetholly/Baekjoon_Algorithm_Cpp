#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<utility>
using namespace std;
vector<vector<vector<int>>> map;
queue<tuple<int,int,int>>myq;
tuple<int,int,int> way[6] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,-1}, {0,0,1}};


int main()
{
	int N, M, H;
	int temp;
	int min = 0;
	cin >> M >> N >> H;
	map.assign(H, vector<vector<int>>(N, vector<int>(M)));
	for(int h = 0; h< H; h++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j<M; j++)
			{	
				cin >> temp;
				map[h][i][j] = temp;
				if(temp == 1)
					myq.push({i,j,h});
			}
		}
	}
	
	while(!myq.empty())
	{
		tuple<int,int,int> current = myq.front();
		myq.pop();
		for(int w = 0; w<6; w++)
		{
			//cout<<"=";
			int newX = get<0>(current) + get<0>(way[w]);
			int newY = get<1>(current) + get<1>(way[w]);
			int newZ = get<2>(current) + get<2>(way[w]);
			//cout<<"=\n";
			if(newX >=0 && newY >= 0 && newZ >= 0 && newX < N && newY < M && newZ < H)
			{
				//cout<<newX<<", "<<newY<<", "<<newZ<<"!\n";
				if(map[newZ][newX][newY] == 0)
				{
					myq.push({newX, newY, newZ});
					map[newZ][newX][newY] = map[get<2>(current)][get<0>(current)][get<1>(current)] + 1;
				}
			}
		}
	}
	
	for(int h = 0; h< H; h++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j<M; j++)
			{	
				if(map[h][i][j] == 0){
					cout<<-1;
					return 0;
				}
				else
				{
					if(map[h][i][j]>min)
						min = map[h][i][j];
				}
			}
		}
	}
	cout<<min-1;
	return 0;
}