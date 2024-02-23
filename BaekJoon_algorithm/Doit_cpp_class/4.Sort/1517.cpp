//변수 범위를 항상 생각하자..!
//https://kukuta.tistory.com/434 --> statick 정의

/*
#include <iostream>
#include<vector>

using namespace std;


void divide(vector<int>&arr, int start_index, int end_index, unsigned long& swap_count);
unsigned long merge(vector<int>&arr, int start_index,int half_index, int end_index);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr;
	int N = 0;
	unsigned long swap_count = 0;
	cin >> N;
	for(int i = 0; i<N; i ++)
	{
		int temp =0;
		cin >> temp;
		arr.push_back(temp);
	}
	divide(arr, 0, arr.size()-1, swap_count);
	cout<< swap_count;
}



void divide(vector<int>&arr, int start_index, int end_index, unsigned long& swap_count)
{
	unsigned long harf_index = (start_index+end_index)/2;
	if(start_index < end_index)
	{
		divide(arr, start_index, harf_index, swap_count);
		divide(arr, harf_index+1, end_index, swap_count);
	}
	swap_count += merge(arr, start_index, harf_index, end_index);
}

	
unsigned long merge(vector<int>&arr, int start_index,int half_index, int end_index)
{
	vector<int>sorted_arr;
	
	unsigned long swap_count = 0;										//swap 횟수
	int sorted_arr_index = 0;								//정렬 값 복사를 위한 인덱스
	
	
	int front_index_length = half_index - start_index + 1;	//swap횟수를 계산할 변수 ==> 왼쪽 배열의 길이
															//sorted 과정에서 오른쪽이 왼쪽보다 작아 먼저 앞으로 오게되면 정렬되지 않은 왼쪽 배열의 요소 개수만큼
															//앞으로 swap된 것과 같음
	
	int front_arr = start_index;							//왼쪽 배열의 시작점
	int front_arr_end = half_index;							//왼쪽 배열의 끝점
	
	int back_arr = half_index+1;							//오른쪽 배열의 시작점
	int back_arr_end = end_index;							//오른쪽 배열의 끝점
	
	
	while(front_arr <= front_arr_end && back_arr <= back_arr_end && front_index_length > 0)
	{
		if(arr[front_arr] <= arr[back_arr])
		{
			sorted_arr.push_back(arr[front_arr]);
			front_arr++;
			front_index_length--;
		}
		else if(arr[front_arr] > arr[back_arr])
		{
			sorted_arr.push_back(arr[back_arr]);
			back_arr++; 
			swap_count += front_index_length;
		}
		
	}
	//front 혹은 back 배열이 다 push 된 후,,,,
	while(front_arr <= front_arr_end)
	{
		sorted_arr.push_back(arr[front_arr]);
		front_arr++;
	}
	
	while(back_arr <= back_arr_end)
	{
		sorted_arr.push_back(arr[back_arr]);
		back_arr++;
	}	

	for(int i = start_index; i <= end_index; i++)
	{
		arr[i] = sorted_arr[sorted_arr_index];
		sorted_arr_index++;
	}
	//cout<<swap_count<<" is added to swap, total : ";
	return swap_count;
}

*/