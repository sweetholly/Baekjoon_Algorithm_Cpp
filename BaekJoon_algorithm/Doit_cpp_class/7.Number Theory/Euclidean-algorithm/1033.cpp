#include<iostream>
#include<tuple>
#include<vector>
#include<cmath>
using namespace std;

typedef tuple<int, int, int> tp;  // --> 다음 변수 , 현재 변수의 비율, 다음 변수의 비율

vector<vector<tp>> connection(10);  //--> 재료간의 연결 
long variable[10] = {0,};			//--> 재료 값
bool visited[10] = {false,};	    //--> 탐색 여부 확인
int N;								//재료의 개수
long least = 1;						//최소공배수

/*최대 공약수 구하기*/
long gcd(long a, long b){ 
	if(b == 0)
		return a;
	else{
		return gcd(b, a%b);
	}
}

/* DFS 탐색 */
void DFS(long node){
	if(visited[node] == true)
		return;
	
	visited[node] = true;
	for(tp i : connection[node]) {
		int next = get<0>(i);
		if(visited[next] == false) {
			variable[next] = variable[node] / get<1>(i) * get<2>(i);
			//cout<<"variable["<<next<<"] = "<<variable[node] <<" / "<<get<1>(i)<<" * "<< get<2>(i)<<"\n";
			DFS(next);
		}
	}
}


int main() {
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int a, b, p, q;
		cin >> a >> b>> p >> q;
		//cout<<"input ";
		connection[a].push_back(make_tuple(b,p,q));
		connection[b].push_back(make_tuple(a,q,p));
		least *= (p * q / gcd(p,q));  // (p*q / 최대공약수)
		//cout<<"least : "<<least<<"\n";
	}
	
	variable[0] = least; //시작 인덱스(0)을 최대 공약수로 초기화
	DFS(0);		//DFS 탐색을 통해 이전 인덱스값에 해당하는 재료와 현재 재료의 비를 계산해 값 입력
	for(int i = 2; i <= variable[0]; i++) {
		bool check = true;
		for(int j = 0; j < N; j++){
			if(variable[j] % i == 0)
				continue;
			else
				check = false; break;
		}
		if(check) {
			for(int j = 0; j < N; j++) {
					variable[j] /= i;
			}
			i--;
		}
	}
	
	
	for(int j = 0; j < N; j++){
		if(variable[j] == 0)
			cout <<1<<" ";
		else
			cout << variable[j]<<" ";		
	}
	return 0;
}



	/*for(int j = 0; j < N; j++){
		cout<<variable[j]<<" ";		
	}
	cout<<"\n";
	long div = variable[0];
	for(int i = 1; i < N; i++){
		div = gcd(div, variable[i]);
		//cout<<div<<" ";
	}
	//cout<<"\n";
	for(int j = 0; j < N; j++){
		if(variable[j] == 0)
			cout <<1<<" ";
		else
			cout << variable[j]/div <<" ";		
	}*/