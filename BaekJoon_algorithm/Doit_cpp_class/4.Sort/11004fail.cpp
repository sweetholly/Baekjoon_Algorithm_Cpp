/*
#include<iostream>
#include<vector>


using namespace std;



void QuickSort(vector<int>&Vector, int pivot_point, int start_point, int end_point)
{
	if(pivot_point < 1)
	{
		return;
	}
	cout << Vector[pivot_point]<<"  "<<Vector[start_point]<<"  "<<Vector[end_point]<<'\n';
	Vector.erase(Vector.begin()+pivot_point);
	int start = start_point;
	int end = end_point;
	int pivot = Vector[pivot_point]; 
	
	while(start != end)
	{
		cout << "start : "<< start << "   end :  "<<end<<'\n';
		if(Vector[start] < pivot)
		{
			start ++;
		}
		if(Vector[end] > pivot)
		{
			end --;	
		}
		
		if((Vector[start] > pivot) && (Vector[end] < pivot))
		{
			int temp = Vector[start];
			Vector[start] = Vector[end];
			Vector[end] = temp;
		}
	}
	if(start == end)
	{
		if(Vector[start] < pivot)
		{
			int temp = pivot;
			Vector.insert(Vector.begin()+start, 1, temp);
		}
		else
		{
			int temp = pivot;
			Vector.insert(Vector.begin()+start-1, 1, temp);
		}
	}
	
	
	for(int i = 0;  i < Vector.size(); i ++)
	{
		cout << Vector[i] << "  ";
	}
	cout <<'\n';
	return;
	//QuickSort(Vector , (pivot-1 - start_point)/2 , start_point , pivot-1); // pivot 앞자리
	//QuickSort(Vector , (end_point - pivot+1)/2, pivot+1 , end_point); // pivot 뒷자리
}


int main()
{
	int N;
	int K;
	int result;
	int pivot_point;
	int start_point;
	int end_point;
	vector<int>V;
	cin >> N;
	cin >> K;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		V.push_back(temp);
	}
	
	start_point = 0;
	end_point = V.size()-1;
	pivot_point = V.size()/2;
	
	
	QuickSort(V, pivot_point, start_point, end_point);
	result = V.at(K);
	cout << result;
	return 0;
}

*/