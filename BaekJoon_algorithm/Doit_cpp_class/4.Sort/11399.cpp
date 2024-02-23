
/*
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	vector<int>person;
	int N;
	int total = 0;
	int result = 0;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int temp;
		cin>>temp;
		person.push_back(temp);
	}
	for(int i = 1; i < N; i ++)
	{
		int compare = person[i];
		for(int j = 0; j<i; j++)
		{
			if(compare < person[j])
			{
				person.erase(person.begin()+i);
				person.insert(person.begin()+j, compare);
				break;
			}
			else
				continue;
		}
		
	}
	for(int i= 0; i < N; i ++)
	{
		total = total + person[i];
		result += total;
	}
	cout<<result;
	return 0;
}


*/