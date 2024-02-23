/*
stirng 메소드

https://hwan-shell.tistory.com/120



*/


/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string numbers;
	int arr[10];
	int result;
	cin >> numbers;
	for(int i = 0; i < numbers.length(); i++)
	{
		arr[i] = stoi(numbers.substr(i,1));
	}
	
	for(int i = 0; i < numbers.length(); i++)
	{
		int max = arr[i];
		int index = i;
		int swap = arr[i];
		for(int j= i; j < numbers.length(); j++)
		{
			if(max < arr[j])
			{
				max = arr[j];
				index = j;
			}
		}
		arr[i] = max;
		arr[index] = swap;
		cout<<arr[i];
	}
}
*/