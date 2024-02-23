#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int, int> p;
p dir[4] = {make_pair(0,1) , make_pair(0,-1) , make_pair(1,0) , make_pair(-1,0)};
int BFS(int i, int j, int N, vector<vector<bool>>&check);
bool compare(int a, int b){
	if(a < b)
		return true;
	else
		return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<bool>>check;
	vector<bool>arr;
	vector<int>count;
	int N;
	string input;
	int total = 0;;
	cin >> N;
	check.assign(N,arr);
	for(int i = 0; i < N; i++){
		cin >> input;
		for(int j = 0; j < input.length(); j++){
			if(input[j] == '0'){
				check[i].push_back(false);
			}
			else
				check[i].push_back(true);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(check[i][j] == true){
				check[i][j] = false;
				//cout<<"!!\n";
				count.push_back(BFS(i,j,N,check));
			}
		}
	}
	cout<<count.size()<<"\n";
	sort(count.begin(), count.end());
	for(const auto& i : count)
		cout<<i<<"\n";
	return 0;
}

int BFS(int i, int j, int N ,vector<vector<bool>>&check){
	int count = 1;
	queue<p>myq;
	myq.push(make_pair(i,j));
	while(!myq.empty()){
		int front = myq.front().first;
		int back = myq.front().second;
		myq.pop();
		for(int a = 0; a < 4; a++){
			if(
				(front + dir[a].first >= 0 && front + dir[a].first < N)
			  	&&
				(back + dir[a].second >= 0 && back + dir[a].second < N)
			  ){
				if(check[front + dir[a].first][back + dir[a].second] == true){
					check[front + dir[a].first][back + dir[a].second] = false;
					count++;
					myq.push(make_pair(front + dir[a].first ,back + dir[a].second));
				}
			}
		}
	}	
	return count;
}