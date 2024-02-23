/*

-> 현재수 / 행 번호 --> 현재수보다 작은 수의 개수
라는 수학적 아이디어를 뽑아내어 이분탐색 실행, 실행 횟수를 획기적으로 줄이는것이
문제의 핵심이었음

이분 탐색 연습 더 필요,,,
기본적으로
-> start end 를 두고 
1 혹은 절반씩 더하고 뺸다...


DFS, BFS, 이분탐색 연습하자

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	long long N, K;
	long long start, end, mid;
	long long cnt;
	cin >> N >> K;
	start = 1;
	end = N * N;

	while (start <= end)
	{
		cnt = 0;
		mid = (start + end) / 2;
		//cout<<start<<" "<<mid<<" "<<end<<'\n'; 
		for(int i = 1; i<=N; i++)
		{
			if(mid/i > N)
				cnt += N;
			else
				cnt += mid/i;
		}
		//cout<<cnt<<"\n\n";
		if (cnt >= K)
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << start;
}*/