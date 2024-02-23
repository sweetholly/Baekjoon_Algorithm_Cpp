#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>

using std::cin;
using std::cout;
using std::queue;
using std::vector;
using std::pair;
using std::make_pair;

typedef pair<int, int> p;

vector<vector<int>>arr;
vector<vector<bool>>check;
p direction[4] = {make_pair(1,0) , make_pair(-1,0) , make_pair(0,1), make_pair(0,-1)};
int picture = 0;
int maxwidth = 0;
int currentwidth = 1;
int N , M;
int temp;
int painted = 0;

void BFS(p index);
int main()
{
	cin >> N >>M;
	arr.resize(N);
	check.assign(N, vector<bool>(M, false));
	for(int i = 0; i< N; i++)
	{
		for(int j =0; j< M; j++)
		{
			int temp;
			cin >> temp;
			if(temp == 1)
				painted++;
			arr[i].push_back(temp);
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(painted <= 0)
				break;
		for(int j =0; j < M; j++)
		{
			if(painted <= 0)
				break;
			if(check[i][j] == false && arr[i][j] == 1)
			{
				BFS(make_pair(i,j));
				picture ++;
				if(currentwidth > maxwidth)
					maxwidth = currentwidth;
				currentwidth = 1;
			}
		}
	}
	cout<<picture<<'\n'<<maxwidth;
}

void BFS(p index)
{
	queue<p>myq;
	myq.push(index);
	while(!myq.empty())
	{
		if(painted <= 0)
			break;
		int front_n = myq.front().first;
		int back_n = myq.front().second;
		myq.pop();
		check[front_n][back_n] = true;
		for(int i = 0; i<4; i++)
		{
			int x = front_n + direction[i].first;
			int y = back_n + direction[i].second;
			if((x >= 0 && y>= 0) && (x< N && y < M))
			{
				if(arr[x][y] != 0 && check[x][y] == false)
				{
					check[x][y] = true;
					currentwidth ++;
					painted--;
					myq.push(p(x,y));
				}
			}
		}
	}
}