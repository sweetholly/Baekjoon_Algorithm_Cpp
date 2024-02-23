#include<iostream>
using namespace std;


int main(){
	long small = 0;
	long big = 0;
	string smstr;
	string bigstr;
	int count = 0;
	
	cin >> small >> big;
	smstr = to_string(small);
	bigstr = to_string(big);
	if(bigstr.length() == smstr.length()){
		for(int i = 0; i < bigstr.length(); i++){
			if(bigstr[i] == smstr[i]) {				//small 과 big의 해당 자리값이 같을 때
				if(bigstr[i] == '8'){				//두 숫자가 다 8일 경우 모든 1개가 추가된다.
					count ++;
				}
				else 
					continue;
			}
			else
				break;
		}
	}
	cout<<count;
	return 0;
}

/*
880 ~ 1098

*/