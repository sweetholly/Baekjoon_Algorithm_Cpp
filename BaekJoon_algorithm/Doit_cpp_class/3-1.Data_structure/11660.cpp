/*
#include<iostream>
#include<vector>


using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	int qna;
	int sum[1025][1025] = {0,};
	int total = 0;
	
	int x1 , y1 , x2, y2;
	
	cin >> size >> qna;
	
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j<= size; j++)
		{
			int temp;
			cin >> temp;
			sum[i][j] = sum[i][j-1] + temp;
			//cout << sum[i][j]<< ' ';
		}
	}
	//cout << "-----------------------"<<"\n-----------------------\n";
	for(int i = 0; i < qna; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j = x1; j <= x2; j++)
		{
			total += sum[j][y2] - sum[j][y1-1];
			//cout << sum[j][y2] << " - " << sum[j][y1-1] <<"result == "<< total <<'\n';
		}
		cout << total<<'\n';
		total = 0;
	}
}*/