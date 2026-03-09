/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int weight[2010][2010];
int output[2010][2010];
int MAXVALUE = 0;
int main()
{
    int M, N;
    cin >> M >> N;
    
    for(int i = 0; i <=N; i++){
        weight[0][i] = 0;  
        weight[M+1][i] = 0;
        output[0][i] = 0;  
        output[M+1][i] = 0;
    }
    for(int i = 1; i <=M; i ++){
        weight[i][0] = 0;
    }
    
    for(int i = 1; i <= M; i++){
        string input = "";
        cin >> input;
        for(int j =1; j <= N; j++){
            int w = input[j-1] - '0';
            weight[i][j] = w;
        }
    }
    
    
    for(int x = 0; x <= M; x++){
        for(int y =0; y < N; y++){
            output[x][y] = max({output[x][y-1], output[x-1][y-1], output[x+1][y-1]});
            output[x][y] += weight[x][y];
            MAXVALUE = max(MAXVALUE, output[x][y]);
            //cout<<x<<","<<y<<"weight : "<<weight[x][y]<<",, output : "<<output[x][y]<<endl;
        }
    }
    cout<<MAXVALUE;
    return 0;
}