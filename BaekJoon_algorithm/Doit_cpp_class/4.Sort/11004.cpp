/*
quicksort 의 핵심은 각 구간을 pivot(기준점)을 중심으로 하여
NlongN의 시행 횟수로(2의 제곱번씩 실행횟수 작아짐) 구간을 나눠 연산한다는 것이다
pivot 이 중간에 오든,,, 처음값이든 끝값이든  마무리할 수 있는 코드를 작성해보자

*/
/*
#include<iostream>
#include<vector>

using namespace std;

	
void quicksort(vector<int>&arr, int start, int end, int K)
{
	//cout<< "active\n";
	int pivot = start;
	int front = pivot +1;
	int back = end;
	int temp;
	if(pivot >= end)
	{
		return;
	}
	if(pivot == K)
	{
		return;
	}
	//cout << arr[pivot] << "  " << arr[front] << "  " << arr[end]<<'\n'; 
	while(front <= back)
	{
		while(front <= end && arr[front] <= arr[pivot])
		{
			front ++;
			//cout<<"front ++, arr[front] == "<<arr[front] <<"  arr[pivot] == "<<arr[pivot]<< "\n";
		}
		while(back > start && arr[back] >= arr[pivot])
		{
			back --;
			//cout<<"end ++, arr[end] == "<<arr[end] <<"  arr[pivot] == "<<arr[pivot]<< "\n";
		}
		
		if(front > back) //front 와 back 이 엇갈림
		{
			temp = arr[back];
			arr[back] = arr[pivot];
			arr[pivot] = temp;
		}
		else // front  값이 pivot보다 크고,  back 값이 pivot보다 작을 때 스왑
		{
			temp = arr[front];
			arr[front] = arr[back];
			arr[back] = arr[front];
		}
	}
	quicksort(arr, start, back -1,K);
	quicksort(arr, back+1, end,K);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int>arr;
	int N;
	int K;
	cin >> N;
	cin >> K;
	for(int i = 0; i < N; i ++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	quicksort(arr,0,arr.size()-1,K);
	cout<<arr[K-1];
}
*/
//이거 아니면,,,,그냥,,,sort 함수 써라,,,nlong이 있는데 뭘 만들어서 쓰노 백준에 올리면 그냥 시간초과 과광 떠버리고 안된다 ㅇㅇ...



/*
#include <iostream>
#include <algorithm>

using namespace std;
long long int arr[5000000];

int main() {
	// 입출력 속도를 놓여주기 위함
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N은 입력받을 수의 갯수, K는 정렬했을때 몇 번째 수인지
	int N, K;	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	
	cout << arr[K - 1];

	return 0;
}
*/
