/*
	어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다. 
	예를 들어 79,197과 324,423 등이 팰린드롬 수이다.
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	long long *arr;
	string result;
	long long N;
	cin >> N;
	arr = new long long[2000001];
	for(long long i = 2; i <= 2000000; i++)
	{
		arr[i] = i;
	}
	for(long long i = 2; i <= sqrt(2000000); i++)
	{
		if(arr[i] == 0)
			continue;
		for(long long j = i+i; j <= 2000000; j+=i)
		{
			arr[j] = 0;
		}
	}
	
	do
	{
		if(arr[N] == 0)
		{
			N++;
			continue;
		}
		string temp;
		string convert;
		temp = to_string(arr[N]);
		convert = to_string(arr[N]);
		reverse(convert.begin(), convert.end());
		if(temp == convert){
			result = temp;
			break;
		}
		N++;
	}
	while(N <= 2000000);
	cout << result;
	delete []arr;
	return 0;
}