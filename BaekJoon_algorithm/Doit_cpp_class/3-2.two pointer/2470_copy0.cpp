/*
#include<iostream>
#include<algorithm>

using namespace std;

void sort_arr(int start, int end, int *arr);
void divide(int s, int e, int *arr);
void merge(int start, int end, int* arr);

int main()
{
    int N = 0;
    cin >> N;
    int *arr = new int[N];
    int front = 0;
    int back = N-1;
    int min_result 	= 2000000000;
    int most_front 	= 1000000000;
    int most_back 	= 1000000000;
	int mode = 0;
    for(int i = 0; i< N; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+N);
    while(front < back)
    {
        int cal = arr[front] + arr[back];
		int result;
		result = abs(cal);
		if(min_result > result)
		{
			min_result = result;
			most_back = arr[back];
			most_front = arr[front];
		}
		
		if(cal < 0)
		{
			front ++;
		}
		else if(cal > 0)
		{
			back --;
		}
		else if(result == 0)
		{
			most_front = arr[front];
			most_back = arr[back];
			break;
		}

    }
	cout<<most_front<<" "<<most_back;
	delete[] arr;
}

*/