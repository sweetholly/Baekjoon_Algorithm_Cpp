#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    vector<int> answer;

    int left = 0;
    long long sum = 0;
    
    int start = 0;
    int end = n-1;
    int len = 1000001;
    
    for(int right = 0; right < n; right ++){
        sum += sequence[right];
        //k 보다 크면, 왼쪽을 빼주고, 한 칸씩 슬라이드
        while(sum > k && left <= right){
            sum -= sequence[left];
            left ++;
        }
        
        if(sum == k){
            int curlen = right - left;
            
            //최단길이 기준으로 시작점, 끝점, 길이 업데이트 , 앞쪽부터 순차탐색하므로 시작인덱스가 작은 순서대로 찾는건 자동으로 처리됨
            if(curlen < len){
                len = curlen;
                start = left;
                end = right;
            }
        }
    }
    answer.push_back(start);
    answer.push_back(end);
    return answer;
}