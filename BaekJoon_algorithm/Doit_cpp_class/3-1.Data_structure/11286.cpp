//https://jordano-jackson.tistory.com/55
/*첫 번째 인자가 더 작을 때 true가 되는 쪽으로 
//bool 함수값을 리턴하면 오름차순의 결과를 얻을 수 있다.
비교함수의 return 의미 
	==> true 이면 sort함수는 왼쪽이 오른쪽보다 먼저 나오게 한다. 

오름차순 --> return a < b
내림차순 --> return a > b

//https://kbj96.tistory.com/15
<우선순위 큐>
C++에서 자주 쓰이는 vector와 같은 container adaptor의 한 종류이며 
C++에서 int와 같은 기본자료형으로 우선순위 큐를 사용한다면 큐에 있는 모든 원소 중에서 
가장 큰 값이 Top을 유지하도록, 우선순위가 가장 크도록 설계되어 있다. 
우선순위 큐는  내부적으로 Heap이라는 자료구조를 사용하고 있다. 

Method
 - push() : 우선순위 큐에 원소 추가
 - pop()  : 우선순위 큐에서 top 원소를 제거
 - top()  : 우선순위 큐에서 top에 있는 원소를 반환한다
 - empty(): 우선순위 큐가 비어있으면 true, 값이 햘당되어있다면 false
 - size (): 우선순위 큐에 포함되어 있는 원소의 수를 반환한다.
*/
/*
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>


using namespace std;
typedef pair<int, int> node;
bool compare(const node &A, const node &B);
class AbsHeap
{
	private:
		vector<node>q;
		int min = 0;
	public:
		AbsHeap();
		~AbsHeap();
		void push(int ori, int now);
		int GetMin();
		void PopMin();
		bool IsEmpty();
};

AbsHeap:: AbsHeap()
{

}

AbsHeap:: ~AbsHeap()
{
	this->q.clear();
	vector<node>().swap(this->q);
}



void AbsHeap:: push(int ori, int now)
{
	this->q.push_back(node(ori , now));
	sort(this->q.begin(), this->q.end(), compare);
	this->min = this->q.front().first;
}

int AbsHeap:: GetMin()
{
	return this->min;
}

bool AbsHeap:: IsEmpty()
{
	if(this->q.empty() == 1)
		return 1;
	else
		return 0;
}

void AbsHeap:: PopMin()
{
	this->q.erase(this->q.begin());
	this->min = this->q.front().first;
}


bool compare(const node &A, const node &B)
{
	if(A.second == B.second)
		return A.first < B.first;
	else
		return A.second < B.second;
}


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int N;
	int min = 0;
	int temp = 0;
	AbsHeap MyAbs;
	cin >> N;
	//cout << N;
	
	for(int i = 0; i < N; i ++)
	{
		cin >> temp;
		//cout << temp;
		if(temp == 0)
		{
			if(MyAbs.IsEmpty() == 1)
				cout << 0 <<'\n';
			else
			{
				min = MyAbs.GetMin();
				cout<<min <<'\n';
				MyAbs.PopMin();
			}
		}
		else
		{
			MyAbs.push(temp, abs(temp));
		}
	}	
}
*/
//--------> 실패한 코드





//--------> priority_queue를 사용한 정답 코드
/*
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


typedef pair<int, int> node;
struct compare
{
	bool operator()(node a, node b)
	{
		if(a.second == b.second)
		{
			return a.first > b.first;
		}
		else
			return a.second > b.second;
	}
};

priority_queue<node, vector<node>, compare>MyPQ;

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int N;
	int min = 0;
	int temp = 0;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> temp;
		if(temp == 0)
		{
			if(MyPQ.empty() == true)
			{
				cout <<0<<'\n';
				continue;
			}
			else
			{
				min = MyPQ.top().first;
				cout << min <<'\n';
				MyPQ.pop();
			}
		}
		else
		{
			MyPQ.push(node(temp, abs(temp)));
		}
		//cout << MyPQ.size() << " "<< MyPQ.top().first<<'\n';
	}
}
*/