#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int left = 1;
    int sum = 0;

    for (int right = 1; right <= n; right++) {
        sum += right;

        while (sum > n) {
            sum -= left;
            left++;
        }

        if (sum == n) {
            answer++;
        }
    }

    return answer;
}