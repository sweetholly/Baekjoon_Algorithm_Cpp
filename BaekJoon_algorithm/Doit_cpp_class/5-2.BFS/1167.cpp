//깊이 우선 탐색 방식으로 해결(DFS)
#include<iostream>
#include<vector>
#include<utility>
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::make_pair;
typedef pair<int, int> p;

int times = 1;
void DFS(vector<vector<p>>&arr,  vector<bool>&check, int &maxidx, int &maxvalue, int idx, int value);
int  main()
{
	 std::ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
     vector<vector<p>>arr;
     vector<bool>check;
     int V;
	 int maxidx  = 0;
	 int maxvalue = 0;
     cin >> V;
     arr.resize(V+1);
     check.assign(V+1, false);
     for(int i = 1; i<=V; i++)
     {
          int start;
          int point = 0;
          int range = 0;
          cin >> start;
          while(1)
          {    
               cin>>point;
               if(point != -1)
               { 
                    cin>>range;
                    arr[start].push_back(make_pair(point, range));
               }
               else
                    break;
          }
     }
	DFS(arr, check, maxidx, maxvalue, 1, 0);
	maxvalue =0;
	check.assign(V+1, false);
	DFS(arr, check, maxidx , maxvalue, maxidx, 0);
    cout<<maxvalue;
}

//current 값 메커니즘 수정 필요 ---> 이전 단계 dfs 실행시 더해진 result 값이 돌아오지 않음
void DFS(vector<vector<p>>&arr,  vector<bool>&check, int &maxidx, int &maxvalue, int idx, int value)
{
    check[idx] = true;
    if(maxvalue < value)
	{
		maxvalue = value;
		maxidx = idx;
	}
	
	for(int i = 0; i<int(arr[idx].size()); i++)
     {
        if(check[arr[idx][i].first] == false)
        {
			int  newidx= arr[idx][i].first;
			int  newvalue= arr[idx][i].second;
			DFS(arr, check, maxidx, maxvalue, newidx, newvalue+value);
        }
     }
     return;
}