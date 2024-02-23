#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define A 0									// 0 = A / 1 = B / 2 = C
#define B 1
#define C 2
using namespace std;

typedef pair<int, int> p;
vector<bool>checker;
vector<vector<bool>>check;					// 방문 벡터 -> C는 A,B의 조합을 통해 자동으로 정해지므로 생략
vector<int>result;							// 결과값
int Max[3] = {0,};							// A,B,C 의 최대 용량 저장
p process[6] = {
	make_pair(C,A), make_pair(C,B) , 
	make_pair(B,C) , make_pair(B,A) , 
	make_pair(A,C) , make_pair(A,B)
};											//각 경우의 수를 지정 -> 반복문을 통해 어떤 작업을 처리할지 미리 결정	
											//경우의 수는.....C -> A, C -> B, B -> C, B -> A, A -> B, A -> C

void BFS(int Av, int Bv, int Cv);
int main(){
	cin >> Max[A] >> Max[B] >> Max[C];
	check.assign(Max[A]+1, checker);		//방문 벡터 초기화(false)
	for(int i = 0; i < Max[A]+1; i++){
		check[i].assign(Max[B] , false);
	}
	BFS(0,0,Max[C]);						//BFS탐색
	sort(result.begin(), result.end());		//오름차순 정렬
	for(const auto& i : result){
		cout<<i<<" ";
	}
	return 0;
}

void BFS(int Av, int Bv, int Cv){
	queue<p>myq;							//A,B값을 저장할 큐 선언(C는 생략 가능)
	myq.push(make_pair(Av, Bv));
	check[Av][Bv] = true; 
	result.push_back(Cv);
	int cal[3];
	while(!myq.empty()){
		p front = myq.front();
		cal[A] = front.first; cal[B] = front.second; cal[C] = Max[C] - cal[A] - cal[B];
		myq.pop();

		for(int i = 0; i < 6; i++) {
			cal[process[i].second] += cal[process[i].first];
			cal[process[i].first] = 0;
			if(Max[process[i].second] < cal[process[i].second]) //최대 용량보다 많이 받았을 때,
			{
				cal[process[i].first] += cal[process[i].second] - Max[process[i].second];
				cal[process[i].second]  = Max[process[i].second];
			}
			if(check[cal[A]][cal[B]] == false){					//이전에 방문한 적 없는 경우
				check[cal[A]][cal[B]] = true;
				myq.push(make_pair(cal[A], cal[B]));
				if(cal[A] == 0){								//A가 0 --> 결과값이 될 수 있는 경우
					result.push_back(cal[C]);
				}
			}
			cal[A] = front.first; cal[B] = front.second; cal[C] = Max[C] - cal[A] - cal[B];		//다음 반복을 위해 초기화
		}
	}
}

