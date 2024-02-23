#include<iostream>
#include<utility>
#include<vector>
using namespace std;
typedef pair<char, bool> p;
//- 97
int main(){
	string input;
	vector<bool>check;
	check.assign(26, false);
	int count = 0, N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int curr, temp;
		cin >> input;
		
		curr = input[0] - 97;
		check[curr] = true;
		
		for(int j = 1; j < input.length(); j++){
			temp = input[j] - 97;
			if(curr == temp){
				continue;
			}
			else if(curr != temp){
				if(check[temp] == false){
					curr = temp;
					check[temp] = true;
				}
				else if(check[temp] == true){
					//cout<<"fail\n";
					count --;
					break;
				}
			}
		}
		check.assign(26, false);
		count ++;
	}
	cout<<count;
	return 0;
}