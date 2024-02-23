/*
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	stack<string>print;
	int N;
	int size;
	string input;
	string temp;
	cin >> N;
	cin.ignore();
	for(int i = 0; i < N; i++)
	{
		getline(cin, input);
		for(int j = 0; j<input.length(); j++)
		{
			if(input[j] == ' ')
			{
				print.push(temp);
				print.push(" ");
				temp.clear();
			}
			else
				temp += input[j];
		}
		print.push(temp);
		temp.clear();
		cout<<"Case #"<<i+1<<": ";
		size = print.size();
		while(size--)
		{
			cout<<print.top();
			print.pop();
		}
		cout<<'\n';
	}
}
*/