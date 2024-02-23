/*
#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;


void divide(vector<int>&v , int front, int back);
void merge(vector<int>&v, int front, int half,int back);

int main()
{
	vector<int>v;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
		divide(v, 0, i);
		cout<<v[i/2]<<endl;
	}
	
	
	for(int i = 0; i < N; i++)
	{
		cout <<v[i]<<"  ";
	}
	
}

void divide(vector<int>&v , int front, int back)
{
	int half = (front+back)/2;
	if(front < back)
	{
		divide(v, front, half);
		divide(v, half+1, back);
	}
	merge(v, front, half, back);
}

void merge(vector<int>&v, int front, int half, int back)
{
	vector<int>temp;
	int TempIndex = 0;
	int FrontStart = front;
	int FrontEnd = half;
	int BackStart = half+1;
	int BackEnd = back;
	while(FrontStart <= FrontEnd && BackStart <= BackEnd)
	{
		if(v[FrontStart] <= v[BackStart])
		{
			temp.push_back(v[FrontStart]);
			FrontStart++;
		}
		
		if(v[FrontStart] > v[BackStart])
		{
			temp.push_back(v[BackStart]);
			BackStart++;
		}
	}
	
	while(FrontStart <= FrontEnd)
	{
		temp.push_back(v[FrontStart]);
		FrontStart++;
	}
	
	while(BackStart <= BackEnd)
	{
		temp.push_back(v[BackStart]);
		BackStart++;
	}
	
	for(int i = front; i<= back; i++)
	{
		v[i] = temp[TempIndex];
		TempIndex++;
	}
}

*/

//최대 힙 문제
//--> 우선순위 큐를 이용해, 최소힙과 최대힙 두개를 만들어 중앙값을 구해야한다.
//--> 자료구조 두 개 쓸 수도 있음 ...ㅋㅋ
/*
#include<iostream>
#include<queue>
#define endl '\n'
using namespace std;


int main()
{
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int N = 0;
	cin >> N;
	for(int i = 0; i< N; i++)
	{
		int temp;
		cin >>temp;
		if(i%2 == 0)
			maxheap.push(temp);
		else
			minheap.push(temp);
		
		if(!maxheap.empty() && !minheap.empty() && (maxheap.top() > minheap.top()))
		{
			int mx = maxheap.top();
			int mn = minheap.top();
			maxheap.pop();
			minheap.pop();
			maxheap.push(mn);
			minheap.push(mx);
		}
		cout << maxheap.top() << endl;
	}
	return 0;
}
*/