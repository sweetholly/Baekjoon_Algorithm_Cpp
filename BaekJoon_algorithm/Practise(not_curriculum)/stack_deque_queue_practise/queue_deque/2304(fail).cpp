/*
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

typedef pair<int, int> column;

bool compare(column front, column back)
{
	return front.first < back.first;
}

column set_compare(deque<column>& myq, int start_point);

int main()
{
	deque<column> myq;
	int N;
	int size = 0;
	int result = 0;
	column compare_col;
	column heighest = make_pair(0,0);
	int L, H;
	cin >> N;
	size = N;
	while(N--)
	{
		column col;
		cin >> L >> H;
		col.first = L;
		col.second = H;
		if(heighest.second <= H)
		{
			if(heighest.second == H)
			{
				heighest.first++;
			}
			else if(heighest.first < H)
			{
				heighest.first = 1;
				heighest.second = H;
			}
		}
		myq.push_back(col);
	}
	sort(myq.begin(), myq.end(), compare);

	
	compare_col = set_compare(myq, 1);
	while(!myq.empty() && heighest.first > 0)
	{
		//cout<<"compare_col = "<<compare_col.first<<" , "<<compare_col.second<<'\n';
		if(myq.front().second >= compare_col.second)
		{
			//넓이 합
			result += compare_col.second * (myq.front().first - compare_col.first);
			//cout<<'('<<myq.front().first<<" - "<<compare_col.first<<')'<<" * "<<compare_col.second<<" == "<<compare_col.second * (myq.front().first - compare_col.first)<<" , result == "<< result <<"\n\n";
			compare_col = set_compare(myq,1);
	
			if(compare_col.second == heighest.second)
			{
				heighest.first --;	
			}
			continue;
		}
		myq.pop_front();
	}
	myq.push_front(compare_col);
	compare_col = set_compare(myq, 0);
	while(!myq.empty())
	{
		//cout<<"compare_col = "<<compare_col.first<<" , "<<compare_col.second<<'\n';
		//cout<<"back = "<<myq.back().second<<'\n';
		if(myq.back().second >= compare_col.second)
		{
			result += (compare_col.first-myq.back().first) * (compare_col.second);
			//cout<<'('<<myq.front().first<<" - "<<compare_col.first<<')'<<" * "<<compare_col.second<<" == "<<compare_col.second * (myq.front().first - compare_col.first)<<" , result == "<< result <<"\n\n";
			compare_col = set_compare(myq,0);
			//cout<<result <<'\n';
			continue;
		}
		if(myq.back().second == heighest.second)
		{
			result += compare_col.second*(compare_col.first - myq.back().first);
			//cout<<'('<<compare_col.first<<" - "<<myq.back().first<<')'<<" * "<<compare_col.second<<" == "<<compare_col.second*(compare_col.first - myq.back().first)<<" , result == "<< result <<"\n\n";
			compare_col = set_compare(myq,0);
			continue;
		}
		myq.pop_back();
	}
	result+=heighest.second;
	cout <<result;
	return 0;
}



column set_compare(deque<column>& myq, int start_point)
{
	column comp;
	if(start_point == 1)
	{
		comp = make_pair(myq.front().first, myq.front().second);
		myq.pop_front();
	}
	else if(start_point == 0)
	{
		comp = make_pair(myq.back().first, myq.back().second);
		myq.pop_back();
	}
	return comp;
}*/