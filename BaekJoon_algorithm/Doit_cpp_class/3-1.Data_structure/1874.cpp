/*
#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int main()
{
    stack<int>result;
    vector<char>cal;

    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    int number;
    int cur_num;
    bool valid = true;
    
    
    result.push(cur_num);
    cur_num ++;
    cin >> n;
    

    for(int i = 0; i < n; i ++)
    {
        cin >> number;
        while(result.top() < number)
        {
            result.push(cur_num);
            cur_num ++;
            cal.push_back('+');
        }
        if(result.top() == number)
        {
            result.pop();
            cal.push_back('-');
        }
        else
        {
            valid = false;
            break;
        }
    }
    if(!valid)
    {
        cout<< "NO" <<endl;
        return 0;
    }
    else
    {
        for(int i = 0; i < cal.size(); i ++)
        {
            cout << cal[i] <<'\n';
        }
        return 0;
    }
}
*/