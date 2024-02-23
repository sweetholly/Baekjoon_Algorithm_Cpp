#include<iostream>
#include<queue>

using namespace std;
int main()
{
	priority_queue<int, vector<int>, less<int>> plus;
	priority_queue<int, vector<int>, greater<int>> minus;
	int N;
	int temp;
	int result = 0;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> temp;
		if(temp > 0)
			plus.push(temp);
		else
			minus.push(temp);
	}
	while(plus.size() > 1) {
		int front = plus.top(); plus.pop(); 
		int back = plus.top(); plus.pop();
		if(front*back > front + back)
			result += (front*back);
		else
			result += (front + back);
	}
	while(minus.size() > 1) {
		int front = minus.top(); minus.pop(); 
		int back = minus.top(); minus.pop();
		if(front*back > front + back)
			result += (front*back);
		else
			result += (front + back);
	}
	
	if(!plus.empty()) {
		result += plus.top(); plus.pop();
	}
	if(!minus.empty()) {
		result += minus.top(); minus.pop();
	}
	cout<<result;
	return 0;
}