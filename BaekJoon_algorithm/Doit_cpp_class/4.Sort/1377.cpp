

/*
#include<iostream>

using namespace std;
int A[5000000];


int main()
{
	int N;
	bool changed = false;
	cin >> N;
	for(int i = 1; i < N+1; i ++)
	{
		int temp = 0;
		cin >> temp;
		A[i] = temp;
	}
	for (int i=1; i<=N+1; i++) 
	{
		changed = false;
    	for (int j=1; j<=N-i; j++) 
		{
        	if (A[j] > A[j+1]) 
			{
            	changed = true;
            	swap(A[j], A[j+1]);
			}
    	}
		if (changed == false) 
		{
        	cout << i << '\n';
        	break;
    	}
	}
}
*/

//정답 코드-->> 근데 왜 밑은 틀리지..?

/*
#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int>node;

int main()
{
	ios::sync_with_stdio(false);
	int max = 0;
	int N;
	node Aarr[500000];
	
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int temp;
		cin >>temp;
		Aarr[i] = node(temp, i);
	}
	sort(Aarr,Aarr+N);
	
	for(int i = 0; i < N; i++)
	{
		//cout << Aarr[i].first <<" "<<Aarr[i].second<<"  ///";
		if(max < Aarr[i].second-i)
			max = Aarr[i].second - i ;
	}
	cout <<max+1;
}
*/

/*
#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int>node;

bool compare(node A, node B)
{
	return A.second < B.second;
}

int main()
{
	int max = 0;
	int N;
	node Aarr[500000];
	
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int temp;
		cin >>temp;
		Aarr[i] = node(i, temp);
	}
	sort(Aarr,Aarr+N, compare);
	
	for(int i = 0; i < N; i++)
	{
		cout << Aarr[i].first <<" "<<Aarr[i].second<<"  ///";
		if(max < Aarr[i].first-i)
			max = Aarr[i].first - i ;
	}
	cout <<max+1;
}

*/