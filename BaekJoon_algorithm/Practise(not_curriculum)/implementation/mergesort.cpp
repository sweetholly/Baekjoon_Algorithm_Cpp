//https://hsp1116.tistory.com/33

/*
#include<iostream>
#include<vector>

using namespace std;
void divide(vector<int>&arr, int start_index, int end_index);

void merge(vector<int>&arr, int start_index,int half_index, int end_index);
	
int main()
{
	vector<int>arr;
	int N = 0;
	int temp = 0;
	int size = 0;
	cin >> N;
	for(int i = 0; i< N; i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}
	size = arr.size()-1;
	divide(arr, 0, size);
	for(int i = 0; i < N; i++)
	{
		cout<<arr[i]<<"\n";
	}
	return 0;
}

void divide(vector<int>&arr, int start_index, int end_index)
{
	int harf_index = (start_index+end_index)/2;
	if(start_index < end_index)
	{
		divide(arr, start_index, harf_index);
		divide(arr, harf_index+1, end_index);
	}
		merge(arr, start_index, harf_index, end_index);
}

	
void merge(vector<int>&arr, int start_index,int half_index, int end_index)
{
	vector<int>sorted_arr;
	
	int sorted_arr_index = 0;
	int front_arr = start_index;
	int front_arr_end = half_index;
	
	int back_arr = half_index+1;
	int back_arr_end = end_index;
	
	while(front_arr <= front_arr_end && back_arr <= back_arr_end)
	{
		if(arr[front_arr] <= arr[back_arr])
		{
			sorted_arr.push_back(arr[front_arr]);
			front_arr++;
		}
		else if(arr[front_arr] > arr[back_arr])
		{
			sorted_arr.push_back(arr[back_arr]);
			back_arr++;
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
}
*/