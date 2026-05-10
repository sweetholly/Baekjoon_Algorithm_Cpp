#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> window;

    // 첫 10일 윈도우 구성
    for (int i = 0; i < 10; i++) {
        window[discount[i]]++;
    }

    // 첫 번째 윈도우 검사
    bool valid = true;
    for (int i = 0; i < want.size(); i++) {
        if (window[want[i]] != number[i]) {
            valid = false;
            break;
        }
    }

    if (valid) {
        answer++;
    }

    // 윈도우를 하루씩 오른쪽으로 이동
    for (int start = 1; start + 9 < discount.size(); start++) {
        string outItem = discount[start - 1];
        string inItem = discount[start + 9];

        window[outItem]--;
        window[inItem]++;

        bool isValid = true;

        for (int i = 0; i < want.size(); i++) {
            if (window[want[i]] != number[i]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            answer++;
        }
    }

    return answer;
}