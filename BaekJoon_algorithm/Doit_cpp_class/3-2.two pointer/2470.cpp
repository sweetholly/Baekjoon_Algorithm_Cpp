/*
#include<iostream>
#include<cmath>

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
    int back = 1;
    int sum_result = 2000000000;
    int most_front = 1000000000;
    int most_back = 1000000000;
    for(int i = 0; i< N; i++)
    {
        cin>>arr[i];
    }
	cout<<'\n';
    sort_arr(0, N, arr);
    while(front <N-1 && back < N)
    {
        int cal = abs(arr[front]+arr[back]);
        if(sum_result == 0)
            break;
        if (cal < sum_result)
        {
            most_front = arr[front];
            most_back = arr[back];
            sum_result = cal;
        }
    }
}

void sort_arr(int start, int end, int *arr)
{
    divide(start, end-1, arr);
    for(int i = 0; i < end; i++)
    {
        cout<< arr[i] <<" "; 
    }
    cout<<'\n';
}

void divide(int s, int e, int *arr){   
    if(e - s < 1)
    {
		cout<<e<<" "<<s<<'\n';
       return;
    }
    
    int mid = (s+e) / 2;
    
    divide(s, mid, arr);
    divide(mid+1, e, arr);
	cout<<"start : "<<s<<", end : "<<e<<'\n';
    merge(s, e, arr);
}

void merge(int start, int end, int* arr){
    int *arr_temp = new int;
    int start_cursor = start;    
    int mid = 1+(end + start)/2;
    int mid_cursor = mid;
    int temp_c = 0;
    
    while(start_cursor < mid && mid_cursor <= end)
    {
		cout<<"merge => start_cursor : "<<start_cursor<<",  mid_cursor: "<<mid_cursor<<",  temp_cursor: "<<temp_c+start<<"\n";
        if(arr[start_cursor] > arr[mid_cursor])
        {
			cout<<"test 1\n";
            arr_temp[temp_c] = arr[mid_cursor];
			cout<<"arr["<<temp_c+start <<"] : "<<arr[mid_cursor]<<'\n';
            temp_c++;
            mid_cursor ++;
        }
        
        else
        {
			cout<<"test 2\n";
            arr_temp[temp_c] = arr[start_cursor];
			cout<<"arr["<<temp_c+start <<"] : "<<arr[start_cursor]<<'\n';
            temp_c++;
            start_cursor ++;
        }
    }
	
	cout<<"test1, test2 result => start_cursor : "<<start_cursor<<",  mid_cursor: "<<mid_cursor<<",  temp_cursor: "<<temp_c+start<<"\n";
    if(start_cursor >= mid && mid_cursor <= end)
    {
        while(mid_cursor <= end)
        {
			cout<<"test 3\n";
            arr_temp[temp_c] = arr[mid_cursor];
			cout<<"arr["<<temp_c+start <<"] : "<<arr[mid_cursor]<<'\n';
            temp_c++;
            mid_cursor++;
        }
    }
    
    else if(start_cursor < mid && mid_cursor > end)
    {
        while(start_cursor <= end)
        {
			cout<<"test 4\n";
            arr_temp[temp_c] = arr[start_cursor];
			cout<<"arr["<<temp_c+start <<"] : "<<arr[start_cursor]<<'\n';
            temp_c++;
            start_cursor++;
        }
    }
    
    for(int i = 0; i<= end-start; i++)
    {
        arr[start+i] = arr_temp[i];
		cout<<arr[start+i]<<" ";
    }
	cout<<"\n\n\n";
	delete []arr_temp;
}
*/