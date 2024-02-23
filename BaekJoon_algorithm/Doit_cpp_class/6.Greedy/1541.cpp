#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int length;

int check = 1; // 1== + , 0 == -
string str;

int temp = 0;
int result = 0;

int main()
{
	getline(cin, str);
	length = str.length();
	for(int i = 0; i < length; i++)
	{
		if(str[i] == '+' || str[i] =='-')
		{
			if(check == 1)
			{
				result += temp;
				temp = 0;
			}
			else if(check == 0)
			{
				result -= temp;
				temp = 0;
			}
			
			if(str[i] == '-')
				check = 0;
		}
		else
		{
			temp *= 10;
			temp += str[i] - '0';
		}
	}
	if(!(temp == 0))
	{
		if(check == 1)
			result += temp;
		else
			result -= temp;
	}
	cout<<result;
	return 0;
}