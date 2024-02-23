/*
#include<iostream>
#include<vector>

using namespace std;
int main()
{
	
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<long long>S;
	vector<long long>R(1001,0);
	
	//cout << S[0] << R[0] <<'\n';
	long long count = 0;
	S.push_back(0);
	//합 배열 구하기
	for(int i = 1; i <= N; i ++)
	{
		int temp;
		cin >> temp;
		S.push_back(temp + S[i-1]);
	}

	//합 배열의 각 값 나머지 구하기
	for(int i = 1; i <= N; i++)
	{
		int cal_result = S[i] % M;
		if(cal_result == 0)
			count ++;
		R[cal_result] ++;
		//cout <<"S[i]%3 == "<<cal_result<<"  R["<<cal_result<<"] == "<<R[cal_result]<<'\n';
	}
	//cout << '\n';
	
	for(int i = 0; i < M; i++)
	{
		count += (R[i] * (R[i]-1)) / 2;
		//cout << "count == "<<"count + "<<(R[i] * (R[i]-1)) / 2<<" = "<<count<<'\n';
	}
	cout << count <<'\n';
	return 0;
}
*/