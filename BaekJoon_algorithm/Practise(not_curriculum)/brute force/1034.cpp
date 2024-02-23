#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<string, int>p;
int main(){
	vector<string> check;
	vector<p> cal;
	int N, M,K;
	string temp;
	int temp_count = 0;
	int result = 0;
	cin >> N >> M;
    /*
        입력받은 값을 모두 string 으로 벡터에 저장
    */
	for(int i = 0; i < N; i++){ 
		string input ="";
		cin >> input;
		check.push_back(input);
	}
    /*
        같은 값끼리 모이도록 정렬
    */
	sort(check.begin(), check.end());
	temp = check[0];
    /*
        벡터를 순회하며 (string, 등장횟수)를 확인하여 pair벡터에 저장
    */
	for(int i = 0; i < check.size(); i++){
		if(temp == check[i]){
			temp_count++;
		}
		
		else if(temp != check[i]) {
			cal.push_back(make_pair(temp, temp_count));
			temp = check[i];
			temp_count = 1;
		}
	}
	cal.push_back(make_pair(temp,temp_count));;
	cin >> K;	
    /*
        pair 벡터에서 각 원소의 0의 개수를 확인...
        0이 존재하는 경우...
        - 스위치를 누를 횟수 / 0의 개수 ==> 모든 0 스위치를 똑같은 횟수 눌러줄 수 있어야함
        - 각 열당 스위치를 누를 횟수 ==> 0인 칸은 홀수번 눌러야 1이 될 수 있음
        - 기존 최댓값보다 카운팅이 많은지
        를 고려하여 pair 벡터를 순회한다.
    */
	for(int i = 0; i < cal.size(); i++){
		int zeroCount = 0;		//0의 개수
		string findzero = cal[i].first;
		for(int j = 0; j < findzero.length(); j++){
			if(findzero[j] == '0'){
				zeroCount ++;
			}
		}
		if(zeroCount == 0){			//모든 값이 1일떄..
			if(K % 2 == 0 &&(cal[i].second > result)){
				result = cal[i].second;
			}
		}
		else{						//0이 있을 때,
			if(K < zeroCount)
				continue;
			if((K-zeroCount) % 2 == 0 && (result < cal[i].second)){
			//틀린 비교 if((K % zeroCount == 0) && (accept % 2 != 0) && (result < cal[i].second))
				result = cal[i].second;
			}
		}
	}
	cout<<result;
	return 0;
}


/* 위의 코드는 메모리를 너무 먹는다,,,,,*/
//ver2 -> 벡터 사용 최소화, 카운팅을 한 배열을 따로 정리하는것이 아닌 바로 바로 처리해봄
//거의 절반이 되었다,,,,ㅋㅋ
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<string>check;
	int N, M,K;
	string temp;
	int result = 0;
	cin >> N >> M;

	for(int i = 0; i < N; i++){ 
		string input ="";
		cin >> input;
		check.push_back(input);
	}
	cin >> K;
	for(int i = 0; i < N; i++){
		int zeroCount = 0;
		int sum = 0;
		//0의 횟수 체킹
		for(int col = 0; col < M; col ++){
			if(check[i][col] == '0'){
				zeroCount++;
			}
		}
		
		//바꿔야하는 0의 개수보다 스위칭 할 수 있는 횟수가 더 많으며 / 0이 아닌 부분을 바꿀 경우 
		if(zeroCount <= K && K%2 == zeroCount % 2){
			for(int row = 0; row < N; row ++){
				if(check[i] == check[row]){
					sum ++;
				}
			}
			if(result < sum)
				result = sum;
		}
	}
	cout << result;
}