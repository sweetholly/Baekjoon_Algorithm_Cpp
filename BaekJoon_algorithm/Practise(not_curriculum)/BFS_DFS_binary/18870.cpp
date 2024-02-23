#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int mid;
	int temp;
	vector<int>arr;
	vector<int>comp;
	vector<int>result;
	cin >> N;
	mid = N/2;
	for(int i = 0; i< N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	comp.assign(arr.begin(), arr.end());
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 0; i<N; i++)
	{
		int val = lower_bound(comp.begin(), comp.end(), arr[i])-comp.begin();
		arr[i] = val;
	}
	for(int i= 0; i< N; i++)
		cout<<arr[i]<<" ";
	
	
	return 0;
}

