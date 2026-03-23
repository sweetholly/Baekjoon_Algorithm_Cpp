#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int plateNum, sushiTypes, numberOfPlates, couponNumber;
struct sushiInfo {
    int sushiType;
    int count;
    bool operator==(const sushiInfo& other) {
        return sushiType == other.sushiType;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int max_sushi = 0;
    int current_sushi = 0;
    cin >> plateNum >> sushiTypes >> numberOfPlates >> couponNumber;
    // 스시 벨트
    vector<int> belt(plateNum);
    // 스시가 현재 범위 안에 몇 개 있는지 저장하는 자료구조
    vector<sushiInfo> sushiLinear;
    deque<int> window;  // 윈도우 인덱스 저장

    for (int i = 0; i < plateNum; i++) {
        cin >> belt[i];
    }

    // 초기 윈도우 설정
    for (int i = 0; i < numberOfPlates; i++) {
        window.push_back(i);
        auto it = find(sushiLinear.begin(), sushiLinear.end(), sushiInfo{belt[i], 0});
        if (it == sushiLinear.end()) {
            sushiLinear.push_back({belt[i], 1});
            current_sushi++;
        } else {
            it->count++;
        }
    }

    // 쿠폰 고려하여 최대값 업데이트
    bool hasCoupon = find(sushiLinear.begin(), sushiLinear.end(), sushiInfo{couponNumber, 0}) != sushiLinear.end();
    max_sushi = max(max_sushi, current_sushi + (hasCoupon ? 0 : 1));

    // 슬라이딩 윈도우 N번 반복
    for (int i = 0; i < plateNum; i++) {
        // 맨 앞 제거
        int removeIdx = window.front();
        window.pop_front();
        auto it = find(sushiLinear.begin(), sushiLinear.end(), sushiInfo{belt[removeIdx], 0});
        it->count--;
        if (it->count == 0) {
            sushiLinear.erase(it);
            current_sushi--;
        }

        // 맨 뒤 추가 (원형 처리)
        int addIdx = (window.back() + 1) % plateNum;
        window.push_back(addIdx);
        auto it2 = find(sushiLinear.begin(), sushiLinear.end(), sushiInfo{belt[addIdx], 0});
        if (it2 == sushiLinear.end()) {
            sushiLinear.push_back({belt[addIdx], 1});
            current_sushi++;
        } else {
            it2->count++;
        }

        // 쿠폰 고려하여 최대값 업데이트
        hasCoupon = find(sushiLinear.begin(), sushiLinear.end(), sushiInfo{couponNumber, 0}) != sushiLinear.end();
        max_sushi = max(max_sushi, current_sushi + (hasCoupon ? 0 : 1));
    }

    cout << max_sushi << "\n";
    return 0;
}