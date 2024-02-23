/*
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[10001] = {0,};
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] ++;
    }
    for(int i = 0; i < 10001; i++)
    {
        if(arr[i] != 0)
        {
            for(int j = 0; j < arr[i]; j++)
            {
                cout<< i<<'\n';
            }
        }
    }
    return 0;
}
*/