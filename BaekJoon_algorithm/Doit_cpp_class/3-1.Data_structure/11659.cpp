/*
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int>sum;
	sum.push_back(0);
	int count = 0;
	int round = 0;
	
	int i = 0;
	int j = 0;
	
	cin >> count;
	cin >> round;
	for(int a = 1; a <= count; a++)
	{
		int temp;
		cin >> temp;
		sum.push_back(sum.back()+temp);
	}
	
	for(int a =0; a < round; a ++)
	{
		cin >> i;
		cin >> j;
		cout << sum[j] - sum[i-1]<< '\n';
	}
	return 0;
}

*/