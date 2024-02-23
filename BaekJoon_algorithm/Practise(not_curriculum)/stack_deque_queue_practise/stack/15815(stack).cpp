/*
	반례 생각 없이 stack은 숫자, queue 는 연샂ㄴ자를 넣어 각 top , front 값을 단순 비교함
	==> 되도록 반복문 횟수는 최소화 하자 (반례 방지 및 시간복잡도 감소)
	==> for문을 통해 반복문에서 operator 입력시 바로 연산 수행하는 방식으로 변경, 자료구조단순, 연산bb
*/
/*
#include<iostream>
#include<stack>
#include<string>
#define endl '\n';

using namespace std;


int main()
{
	string numbers = "";	
	cin >> numbers;
	stack<int> s;
    for (int i = 0; i < numbers.length(); i++) 
	{
        char c = numbers[i];
 
        if (c >= '0' && c <= '9') 
		{
            s.push(c - '0');
        }
        else 
		{
            int a, b;
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
 
            if (c == '+') {
                s.push(b + a);
            }
            else if (c == '-') {
                s.push(b - a);
            }
            else if (c == '*') {
                s.push(b * a);
            }
            else if (c == '/') {
                s.push(b / a);
            }
        }
    }
    
    cout << s.top();
}*/