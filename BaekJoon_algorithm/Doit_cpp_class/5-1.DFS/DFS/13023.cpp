
#include<iostream>
	#include<vector>

	using namespace std;
	static vector<vector<int>>arr;
	static int result = 0;
	void DFS(int member,int curent, vector<bool>&check);
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		vector<bool>check;
		int member;
		int relation;
		
		cin >> member >> relation;
		arr.resize(member);
		check = vector<bool>(member, false);
		
		for(int i = 0; i< relation; i++)
		{
			int front, back;
			cin >> front >> back;
			arr[front].push_back(back);
			arr[back].push_back(front);
		}

		for(int i = 0; i<arr.size(); i++)
		{
			DFS(i, 1, check);
			if(result == 1)
				break;
		}
		cout<<result;
	}

	void DFS(int member, int current, vector<bool> &check)
	{
		check[member] = true;
		if(current > 4)
		{
			result = 1;
			return;
		}

		for(int i = 0; i< arr[member].size(); i++)
		{
			if(check[arr[member][i]] == false)
				DFS(arr[member][i], current+1, check);
			if(result == 1)
				return;
		}
		check[member] = false;
		return;
	}
