#include<iostream>

using namespace std;

int main()
{
	int N;
	int front = 1;
	int back = 1;
	int max = 1;
	int count = 1;
	int mode = 1; //0 = back 감소 ---------- 1 = front 감소
	cin >> N;
	while(count < N) {
		for(int i = 1; i < max; i++) {
			if(count >= N)
				break;
			count ++;
			if(mode == 0){
				back --;
				front ++;
			}
			else if(mode == 1){
				front --;
				back ++;
			}
		}
		max ++;
		count ++;
		if(count > N)
			break;
		else if(mode == 0){
			front ++;
			mode = 1;
		}
		else if(mode == 1){
			back ++;
			mode = 0;
		}
	}
	cout<<front<<'/'<<back;
	return 0;
}