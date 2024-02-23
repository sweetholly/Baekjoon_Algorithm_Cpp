/*
L = {A, 'B', C}  이고, iterator 위치가  B라면 L.insert(iterator, 'k'); 를 실행 했을 때
L = {A, K, 'B', C}  가 된다.  iterator  은 원래 가리키던 값을 가르키게 된다. 
만약 iterator = L.insert(iterator, 'k') 인 경우 L = {A, 'K', B, C} 즉 원래 이터레이터의
위치를 가리키게 된다(삽입한 원소를 가리킨다).

L = {A, 'B', C}  이고, iterator 위치가  B라면 L.erase(iterator); 를 실행 했을 때
L = {A, 'C'}  가 된다.  iterator  은 B가 없어지고 원래 B의 자리로 넘어온 C를 가리킨다. 
erase 함수는 삭제 수행 후 삭제한 값 다음을 가리키는 iterator 을 가리킨다

요약 :
- insert(iter, value)는 iter위치에 value를 삽입 후 원래 iter 위치에 있던 값을 가리킴
- erase(iter)는 iter위치 값을 삭제한 후, 새롭게 iter위치에 들어오는 값을 가리킴
*/
/*
#include<iostream>
#include<list>
#define endl '\n'
using namespace std;

int main()
{
	int N;
	string input;
	cin >>N;
	for(int i = 0; i < N; i++)
	{
		cin>>input;
		
		list<char>lt;
		list<char>::iterator iter; //= lt.begin();
		iter = lt.begin();
		
		for(int j = 0; j < input.size(); j++)
		{
			//cout<<input[j]<<"  ";
			if(input[j] == '<') 	
			{
				if(iter != lt.begin())
				{
					iter--;
				}
			}
			else if(input[j] == '>')
			{
				if(iter != lt.end())
				{
					iter++;
				}
			}
			else if(input[j] == '-')
			{
				if(iter != lt.begin())
				{
					iter = lt.erase(--iter);
				}
			}
			else
			{
				//cout<<input[j]<<" input   ";
				//cout<<*(iter)<<endl;
				iter = lt.insert(iter,input[j]);
				iter ++;
			}
		}
		
		while(!lt.empty())
		{
			cout<<lt.front();
			lt.pop_front();
		}
		cout<<endl;
	}
	return 0;
}
*/