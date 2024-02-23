#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

// SIZE 상수
constexpr auto SIZE = 1001;

// ( 1 ~ 1000 ) / ( 1 ~ 1000 ) 까지의 소숫점 아래 3자리를 저장할 dp
// 단, 분자 <= 분모이다.
int dp[SIZE][SIZE];

int main()
{
	// basic setting
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 문제의 개수 n
	int n;
	cin >> n;

	// 문제의 평균의 소수점 3자리를 저장할 vec
	vector<int> vec;

	// 문제의 평균을 입력받고 저장
	for (auto i = 0; i < n; i++)
	{
		// 소수상태로 입력받음
		double tmp;
		cin >> tmp;

		// 정수로 변환
		int temp = trunc(tmp * 1000.);

		// 소수 3자리만 저장
		vec.push_back(temp % 1000);
	}

	// 시간을 줄이기 위한 sort 작업
	sort(vec.begin(), vec.end());

	// 정답을 저장할 변수 ans
	int ans = 0;

	// dp 초기화
	memset(dp, 0, sizeof(dp));

	// 주어진 소숫점 아래 3자리가 위에서 구한 소숫점 아래 3자리와 동일한 것들이 나올 때까지 무지성 반복
	// i는 분모의 역할을 함
	for (auto i = 1; i < SIZE; i++)
	{
		// n개의 수 중 맞은 수를 체크하기 위한 count
		int count = 0;

		// j는 분자의 역할을 함 
		for (auto j = 1; j <= i; j++)
		{
			// 소숫점 3자리를 구함
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = trunc((j * 1000) / i);

			// k는 i / j의 결과와 주어진 n개의 수가 겹치는지 확인하기 위함
			for (auto k = n - 1; k >= 0; k--)
			{
				//  만약 i / j의 결과와 vec[k]와 같다면
				if (vec[k] == dp[i][j])
					// count를 찾았다고 표시
					count++;

				// vec[k]보다 dp[i][j]가 크다면 더 이상 탐색은 무의미하므로 빠져나옴
				else if (vec[k] < dp[i][j])
					break;
			}
		}

		// 만약 다 찾았다면
		if (count == n)
		{
			// 조건을 만족하는 수 중 최소수는 분모가 되므로 분모를 정답에 대입하고 빠져나감
			ans = i;
			break;
		}
	}

	// 정답 출력
	cout << ans;

	return 0;
}