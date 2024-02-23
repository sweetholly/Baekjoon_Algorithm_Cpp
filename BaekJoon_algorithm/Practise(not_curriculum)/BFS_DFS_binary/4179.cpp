#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
typedef pair<int,int> p;
const p way[4] = {make_pair(0,1),make_pair(0,-1),make_pair(-1,0),make_pair(1,0)};

vector<vector<char>>field;
vector<vector<int>>checkPath;
queue<p> myq;
int main()
{
	string input;		//입력받을 지형
	int R, C;			//행 열 크기
	int startx, starty;
	cin>> R >>C;		
	
	field.resize(R);	//지형 벡터 크기 재할당
	checkPath.assign(R, vector<int>(C, 0));
	
	//지형 입력
	for(int i = 0; i < R; i++)
	{
		cin>>input;
		for(int j = 0; j<C; j++)
		{
			char check = input[j];
			field[i].push_back(check);
			if(check == 'J')
			{
				checkPath[i][j] = 1;
				startx = i;
				starty = j;
				if (i == 0 || j == 0 || i == R - 1 || j == C - 1) 
				{
                	cout << "1";
                    return 0;
                }
			}
			else if(check =='F')
				myq.push(make_pair(i, j));
		}
	}
	myq.push(make_pair(startx, starty));
	while(!myq.empty())
	{
		int FrontNode = myq.front().first; 
		int BackNode = myq.front().second;
		myq.pop();
		for(int i = 0; i < 4; i++)
		{
			int nextX = FrontNode + way[i].first;
			int nextY = BackNode + way[i].second;
			if(nextX >=0 && nextY >=0 && nextX < R && nextY < C && field[nextX][nextY] == '.')  //이동한 노드의 위치가 지형 범위에 들어온다면
			{
				if(field[FrontNode][BackNode] == 'F') //이전 큐의 값이 불길인 경우
				{
					field[nextX][nextY] = 'F';
					myq.push(make_pair(nextX, nextY));
				}
				
				else if(field[FrontNode][BackNode] == 'J')//이전 값이 이동경로인 경우
				{
					field[nextX][nextY] = 'J';
					checkPath[nextX][nextY] = checkPath[FrontNode][BackNode] + 1;
					//cout<<"nextX, nextY : "<<nextX<<"|"<<nextY<<",  current : "<<checkPath[FrontNode][BackNode]<<",  "<<"next : "<<checkPath[nextX][nextY]<<'\n';
					myq.push(make_pair(nextX, nextY));
					if(nextX == 0 || nextY == 0 || nextX == R - 1 || nextY == C - 1)
					{
						cout << checkPath[nextX][nextY];
						return 0;
					}
				}
				/*
				cout<<"map && path /// nextX, nextY :"<<nextX<<", "<<nextY<<'\n';
				for(int i = 0; i<R; i++)
				{
					for(int j = 0; j<C; j++)
					{
						cout<<field[i][j];
					}
					cout<<"      ";
					for(int j = 0; j<C; j++)
					{
						cout<<checkPath[i][j];
					}
					cout<<'\n';
				}
				cout<<"\n\n";*/
			}
		}		
	}
	cout<<"IMPOSSIBLE";
	return 0;
}