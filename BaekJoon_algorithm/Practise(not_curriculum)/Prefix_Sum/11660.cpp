/*
#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>>D;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin>>N>>M;
	D.assign(N+1, vector<int>(N+1, 0));
	
	for(int i = 1; i<=N; i++)
	{
		for(int j = 1; j <=N; j++)
		{
			int temp;
			cin >> temp;
			D[i][j] = D[i][j-1] +D[i-1][j] + temp - D[i-1][j-1];
		}
	}
	//cout<<"\n\n";
	for(int i = 0; i< M; i++)
	{
		int x1, x2, y1,y2,result;
		cin>>x1 >>y1 >>x2 >>y2;
		result = D[x2][y2] - D[x1-1][y2]-D[x2][y1-1] + D[x1-1][y1-1];
		cout<<result<<'\n';
	}
	return 0;
}
*/