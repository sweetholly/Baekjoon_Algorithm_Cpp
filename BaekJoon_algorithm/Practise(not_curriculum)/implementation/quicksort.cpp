//quicksort 구현은 맞지,,,만,,,~ 최악의 경우 nlongN의 경우 생각 못했으므로 별로이뮤ㅠ
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



//아래는 그냥 망한코드 ㅇㅇ
//template<typename T>
/*
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = a;
}
*/
/*
void quicksort(vector<int>&arr, int start_index, int end_index)
{
	int start = start_index;
	int end = end_index;
	int pivot_index = start_index-1;
	int pivot = arr[pivot_index];
	if(end_index - start_index <= 0)
	{
		//cout<<"final cal\n\n\n";
		if(pivot > arr[start])
		{
			int temp = arr[start];
			arr[start] = arr[pivot_index];
			arr[pivot_index] = temp;
		}
		return;
	}
	
	
	while(1)
	{
		if(arr[start] < pivot)
		{
			start ++;
		}
		if(arr[end] > pivot)
		{
			end --;
		}
		
		if(start >= end)
		{
			//cout <<"arr[start ]: "<<arr[start]<<"  arr[end] : "<<arr[end] <<"  pivot : "<<pivot<<'\n';
			if(pivot_index == end)
				return;
			if(arr[start] > pivot)
			{
				arr.insert(arr.begin()+start, 1, pivot);
				arr.erase(arr.begin()+pivot_index);
				pivot_index = start-1;
			}
			else
			{
				int temp = arr[start];
				arr[start] = pivot;
				arr[pivot_index] = temp;
				pivot_index = start;
			}
			break;
		}
		
		if(arr[start] > pivot  && arr[end] < pivot)
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}

	//cout << start_index<<" "<< pivot_index<<" "<<  end_index<<'\n';
	quicksort(arr, start_index, pivot_index-1);
	quicksort(arr, pivot_index+1, end_index);
}

*/
