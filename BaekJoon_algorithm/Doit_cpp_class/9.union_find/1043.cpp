#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>member; 	//파티에 참가하는 인원
vector<vector<int>>party;	//각 파티
void unionf(int a, int b);
int find(int a);
int main(){
	int N , M;			//사람 수, 파티
	int count = 0;
	int known;			//진실을 아는 사람 수
	cin >> N >> M;
	cin >> known;
	party.assign(M, member);
	for(int i = 0; i <= N; i++){
		member.push_back(i);
	}	
	
	while(known --){
		int temp;
		cin >> temp;
		member[temp] = 0;
	}
	for(int i = 0; i < M; i++){
		int fisrtmem;
		int pmembers;
		cin >> pmembers;
		cin >> fisrtmem;
		party[i].push_back(fisrtmem);
		for(int m = 1; m < pmembers; m++){
			int temp;
			cin >> temp;
			party[i].push_back(temp);
			unionf(fisrtmem, temp);
		}
		/*for(const auto& i : member){
			cout<<i<<" ";
		}cout<<"\n";*/
	}
	
	for(int i = 0; i < M; i++){
		bool check = false;
		for(const auto& i : party[i]){
			if(find(member[i]) == 0){
				check = true;
				break;
			}
		}
		if(check == false)
			count ++;
	}
	cout<<count;
	return 0;
}

int find(int a){
	//cout<<"a :"<<a<<" , member[a] :"<<member[a]<<"\n";
	if(a == member[a])
		return a;
	else
		return a = find(member[a]);
}

void unionf(int a, int b){
	a = find(a);
	b = find(b);
	if(a < b){
		member[b] = a;
	}
	else if(a > b){
		member[a] = b;
	}
}
