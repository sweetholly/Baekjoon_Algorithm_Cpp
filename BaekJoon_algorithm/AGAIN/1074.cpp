/*
	분활탐색이래,,,그렇다네,,,허허
*/


#include <iostream>
#include <cmath>
using namespace std;
int n, row, col;
int ans = 0;
void rec(int x, int y, int size){
	//cout<<"x: "<<x<<"  , y: "<<y<<"  , size: "<<size<<"\n";
    if(col==x && row==y){ // 찾으려는 열과 행이 일치하면 
        cout << ans;
        return;
    }
    else if ((col < x + size) && (row < y + size) && (col >= x) && (row >= y)){
        //찾으려는 열과 행이 4분면안에 있을 경우 --> 1 2 3 4 순서로 탐색한다.
        rec(x, y, size / 2);							//1사분면
        rec(x + size / 2, y, size / 2);					//2사분면
        rec(x, y + size / 2, size / 2);					//3사분면
        rec(x + size / 2, y + size / 2, size / 2);		//4사분면
    }
	else{ // 없다면 숫자 카운트 -> 정사각형 넓이
       // cout<<"cur ans : "<<ans<<"   ";
		ans += size * size;
		//cout<<"now ans :"<<ans<<"\n\n";
    }
}
int main(){
    cin >> n >> row >> col;
    rec(0, 0, pow(2, n));
    return 0;
}