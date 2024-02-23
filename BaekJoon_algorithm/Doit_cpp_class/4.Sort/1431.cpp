#include<iostream>
#include<algorithm>
#include<string>
#include<deque>

using std::cin;
using std::cout;
using std::string;
using std::sort;

std::deque<string>dq;

int cmp(string a, string b)
{
	if(a.length() != b.length())
		return a.length() < b.length();

	int a_sum = 0;
	int b_sum = 0;
	for(int i = 0; i< a.length(); i++)
	{
		if(a[i] >= 48 && a[i] <= 57)
			a_sum += a[i]-48;
		if(b[i] >= 48 && b[i] <= 57)
			b_sum += b[i]-48;
	}
	if(a_sum != b_sum)
		return a_sum < b_sum;
	
	return a < b;
}


int main()
{

	std::deque<string>::iterator front_iter;
	std::deque<string>::iterator back_iter;

	string serial;
    int N;
	cin >> N;
	cin.ignore();
    for(int i = 0; i<N; i++)
	{
		getline(cin, serial);
		dq.push_back(serial);
	}
	front_iter = dq.begin();
	back_iter = dq.end();
    sort(front_iter, back_iter, cmp);
	for(int i = 0; i <N; i++)
	{
		cout<<*(front_iter+i)<<'\n';
	}
}