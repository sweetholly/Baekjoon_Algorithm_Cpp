#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
n편의 논문 중, h번 이상 인용된 논문이 h편 이상이고,
나머지 논문이 h번 이하 인용되었다면, h의 최대값이 H-index
*/
//1번 풀이, 정렬문제로 풀어버리기
/*
    만약 위 예시처럼 정렬하면, 0,1,3,5,6 이 된다.
    H번 이상 인용된 논문이 H번 이상이면 된다...즉
    인용횟수를 큰 순서대로 정렬하고 앞 인덱스가 총 몇 개인지 확인한다.
*/
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), less<int>());
    
    for(int i = 0; i < citations.size(); i ++){
        int h_candidate = citations[i];
        int count = 0;
        for(int j = 0; j < citations.size(); j++){
            if (citations[j] >= h_candidate) {
                count++;
            }
        }
        int h = min(count, h_candidate);
        answer = max(answer, h);
    }
    return answer;
}