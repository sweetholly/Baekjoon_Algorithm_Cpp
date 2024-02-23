/*
#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int arr[27] = {0,};
		int temp;
		cin>>temp;
		for(int j = 0; j< temp; j++)
		{
			char alpa;
			cin >> alpa;
			arr[alpa - '@'] ++;
			//cout<<alpa<<"의 개수 : "<<arr[alpa - '@']<<'\n';
		}
		for(int j = 1; j < 27; j++)
    	{
        	if(arr[j] != 0)
        	{
				char print = j +'@';
				while(arr[j]--)
				{
					cout<<print;
				}
        	}
    	}
		cout<<'\n';
	}
}
*/