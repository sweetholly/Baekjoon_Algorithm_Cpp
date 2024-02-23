#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> p;
p way[4] = {make_pair(0,1),make_pair(1,0),make_pair(-1,0),make_pair(0,-1)};
void DFS(p current, p end,vector<vector<bool>>check ,int sum ,int& count, const int K, int R, int C);
int main(){
	vector<bool>point;
	vector<vector<bool>>check;
	int R, C, K;
	int count = 0;
	cin >> R >> C >> K;
	p start = make_pair(R-1,0);
	p end = make_pair(0,C-1);
	check.assign(R, point);
	for(int i = 0; i < R; i++){
		string temp;
		cin >> temp;
		for(auto c : temp){
			if(c == 'T')
				check[i].push_back(true);
			else
				check[i].push_back(false);
		}
	}
	DFS(start, end, check ,1, count, K, R , C);
	cout<< count;
	return 0;
}

void DFS(p start, p end,vector<vector<bool>>check, int sum, int&count, const int K, int R, int C){
	check[start.first][start.second] = true;
	if((start.first == end.first) && (start.second == end.second)){
		//cout<<sum<<"!!!\n";
		if(sum == K){
			count ++;
		}
		return ;
	}
	for(int i = 0; i < 4; i++){
		int newfirst = start.first + way[i].first;
		int newsecond = start.second + way[i].second;
		//cout<<newfirst<<"  "<<newsecond<<"\n";
		if((newfirst < R && newfirst >= 0) && (newsecond < C && newsecond >= 0)){
			if(check[newfirst][newsecond] == false){
				//cout<<"inside\n\n";
				DFS(make_pair(newfirst, newsecond), end,check ,sum + 1, count, K, R, C);
			}
		}
	}
	return;
}