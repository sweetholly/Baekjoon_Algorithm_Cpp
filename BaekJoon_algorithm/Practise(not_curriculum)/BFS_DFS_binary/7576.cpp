#include<iostream>
#include<queue>
#include<utility>
#include<vector>


using namespace std;
typedef pair<int, int> p;
p way[4] = {make_pair(0,1),make_pair(0,-1),make_pair(-1,0),make_pair(1,0)};
vector<vector<int>>line;
vector<vector<bool>>check;
queue<p> myq;
void BFS(int N, int M, int&count, int&days);
	
int main()
{
	int N, M;
	int temp;
	int count = 0;
	int days = 1;
	cin >>M >> N;
	line.resize(N);
	check.assign(N, vector<bool>(M, false));
	for(int i =0; i < N; i++)
	{
		for(int j = 0; j< M; j++)
		{
			int temp;
			cin >> temp;
			line[i].push_back(temp);
			if(temp == 0)
				count ++;

			else if(temp == 1)
				myq.push(make_pair(i, j));
		}
	}
	BFS(N, M, count, days);
	if(count > 0 )
		cout<<-1;
    else
		cout<<days-1;
    return 0;
}

void BFS(int N, int M, int&count, int &days)
{
	while(!myq.empty())
	{
		int FrontNode = myq.front().first;
		int BackNode = myq.front().second;
		//cout<<FrontNode<<",  "<<BackNode<<'\n';
		myq.pop();
		check[FrontNode][BackNode] = true;
		for(int i = 0; i < 4; i++)
		{
			int nextX = FrontNode + way[i].first;
			int nextY = BackNode + way[i].second;
			if((nextX >= 0 && nextY >= 0) && (nextX < N && nextY < M))
			{
				if((line[nextX][nextY] == 0) && (check[nextX][nextY] == false))
				{
					count --;
					check[nextX][nextY] = true;
					line[nextX][nextY] = line[FrontNode][BackNode]+1;
					days = line[nextX][nextY];
					myq.push(make_pair(nextX, nextY));
				}
			}
		}
		/*
		cout<<'\n';
		cout<<count<<'\n';
		for(int i =0; i < N; i++)
		{
			for(int j = 0; j< M; j++)
			{
				cout<<line[i][j]<<" ";
			}
			cout<<'\n';
		}	
		cout<<'\n';
		*/
	}
}