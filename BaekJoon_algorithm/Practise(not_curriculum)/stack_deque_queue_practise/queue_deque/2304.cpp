/*
emplace_back == 이거 개사기다, 벡터 요소에 따라 temple값으로 알아서 정리해주기 때문에
자료형 헷갈릴떄 그냥 이거 써버리면 다 넣을 수 있음 ㄷㄷㄴ
*/

/*
#include<iostream>
#include<deque>
#include<algorithm>



using namespace std;
typedef pair<int, int> col;

bool compare(col front, col back)
{
	if(front.first < back.first)
		return true;
	else
		return false;
}

int main()
{
	deque<col>dq;
	int result =0;
	int N, L, H;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		col insert;
		cin >> L >> H;
		insert = make_pair(L, H);
		dq.push_back(insert);
	}
	sort(dq.begin(), dq.end(), compare);
	
	int max_location = dq.front().first;
	int max_len= dq.front().second;
	for(auto& p : dq)
	{
		if(max_len <= p.second)
		{
			result += max_len * (p.first - max_location);
			max_location = p.first;
			max_len = p.second;
		}
	}
	
	max_location = dq.back().first;
	max_len = dq.back().second; 
	for(int i = dq.size()-1; i >= 0; i--)
	{
		if(max_len < dq[i].second)
		{
			result += max_len * (max_location - dq[i].first);
			max_location = dq[i].first;
			max_len = dq[i].second;
		}
	}
	result += max_len;
	cout<<result;
	return 0;
}
*/