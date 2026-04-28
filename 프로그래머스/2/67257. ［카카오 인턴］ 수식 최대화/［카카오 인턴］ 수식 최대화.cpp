#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<char> express;              // 모든 연산자 배열
vector<long long> num;
const vector<vector<char>> ALL_CASES = {
    {'+', '-', '*'},
    {'+', '*', '-'},
    {'-', '+', '*'},
    {'-', '*', '+'},
    {'*', '+', '-'},
    {'*', '-', '+'},
    
    {'+', '-'}, {'-', '+'}, 
    {'+', '*'}, {'*', '+'},
    {'-', '*'}, {'*', '-'},
    
    {'+'}, {'-'}, {'*'}
};


long long solution(string expression) {
    long long answer = 0;
    string push_num = "";
    for(int i = 0; i < expression.length(); i ++){
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            express.push_back(expression[i]);
            num.push_back(stoll(push_num));
            push_num = "";
        }
        else {
            push_num += expression[i];
        }
    } 
    num.push_back(stoll(push_num));
    
    for(auto & order : ALL_CASES){
    
        vector<long long> work_num = num;
        vector<char> work_exp = express;

        for(auto op : order){
            vector<long long> cur_num;
            vector<char> cur_exp;

            cur_num.push_back(work_num[0]);

            for(int i = 0; i < work_exp.size(); i++){
                if(work_exp[i] == op){
                    long long res;
                    if(op == '+') res = cur_num.back() + work_num[i+1];
                    else if(op == '-') res = cur_num.back() - work_num[i+1];
                    else res = cur_num.back() * work_num[i+1];
                    cur_num.back() = res;
                } else {
                    cur_num.push_back(work_num[i+1]);
                    cur_exp.push_back(work_exp[i]);
                }
            }
            // 다음 패스에 결과 전달
            work_num = cur_num;
            work_exp = cur_exp;
        }
    answer = max(answer, abs(work_num[0]));
}
    return answer;
}