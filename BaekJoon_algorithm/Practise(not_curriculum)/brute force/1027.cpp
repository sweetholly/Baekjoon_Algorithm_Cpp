#include<iostream>
#include <iomanip>

using namespace std;

int main(){
	int N;
	int most = 0;
	double*arr;
	cin >> N;
	cout << std ::setprecision(17);
	arr = new double[N];
	for(int i = 0; i < N; i++){
		double temp;
		cin >> temp;
		arr[i] = temp;
	}
	
	//앞, 뒤와 현재 값의 기울기가 더 작은 경우, count ++
	for(int i = 0; i < N; i++){
		int front = i;
		int back = i;
		int count = 0;
		double CurSlope = 0.1;
		double FrontSlope = 1000000000.0;
		double BackSlope = -1000000000.0;
		
		//cout<<"==========front start=========="<<"\n";
		while(front > 0){ //기울기가 작으면 시야에 잡힌다.
			front --;
			if((i - front == 0) || (arr[i] - arr[front] == 0))
				CurSlope = 0;
			else
				CurSlope = (arr[i] - arr[front]) / (i - front);
			if(CurSlope < FrontSlope){
				count ++;
				//cout<<"(i,front) : "<<i<<", "<<front<<" / "<<"최저 기울기 : "<<CurSlope<<"/ 현재 기울기 : "<<FrontSlope<<" / count: "<<count<<"\n";
				FrontSlope = CurSlope;
			}
		}
		
		//cout<<"==========back start=========="<<"\n";
		while(back < N-1){ //기울기가 크면 시야에 잡힌다.
			back ++;
			if((i - back == 0) || (arr[i] - arr[back] == 0))
				CurSlope = 0;
			else
				CurSlope =  (arr[i] - arr[back]) / (i - back);
			if(CurSlope > BackSlope){
				count ++;
				//cout<<"(i,back) : "<<i<<", "<<back<<" / "<<"최고 기울기 : "<<CurSlope<<"/ 현재 기울기 : "<<BackSlope<<" / count: "<<count<<"\n";
				BackSlope = CurSlope;
			}
		}
		if(count > most)
			most = count;
		//cout<<"\n\n\n";

		count = 0;	
	}
	cout <<most;
	delete []arr;
	return 0;
}
	