/*
#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
*/


/*
int main()
{
    int N;
	cin>>N;
    vector <int> v;
    for(int i=0; i<N; i++)
	{
        int x; 
		cin>>x;
        v.push_back(x);
    }
	reverse(v.begin(), v.end());
    deque<int> dq;
    for(int i=0; i < N; i++)
	{
        if(v[i]==1)
		{
            dq.push_front(i+1);
        }
        else if(v[i]==2)
		{ 
            int tmp=dq.front(); dq.pop_front();
            dq.push_front(i+1);
            dq.push_front(tmp);
        }
        else
		{ 
            dq.push_back(i+1);
        }
    }
    while(N--)
	{
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}
*/