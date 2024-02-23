/*
#include<iostream>
#include<string>
#include<stack>
#include<queue>

int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	std::stack<double>result;     //최종 연산을 위한 stack
	std::vector<double>numbers;	  //각 알파벳에 값을 대입할 큐
	std::queue<double>convert;	  //input 문자열을 실수로 변환한 큐 --> result와의 연산을 통해 최종 연산
	std::string input ="";
	std::cin>> N;
	std::cin>>input;
	
	//각 알파벳에 해당하는 값 입력
	for(int i = 0; i< N; i++)
	{
		double temp;
		std::cin>>temp;
		numbers.push_back(temp);
	}
	
	//입력한 값을 input문자열 비교를 통해 알파벳 에 대응
	//연산자는 연산자의 아스키코드값에 100을 더한값으로  convert 큐에 저장
	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] >= 65 && input[i] <= 90)
		{
			double num = input[i] - 65;
			convert.push(numbers[num]);
		}
		else if(input[i] == 42) // *
			convert.push(142);
		
		else if(input[i] == 43) // +
			convert.push(143);
		
		else if(input[i] == 45) // -
			convert.push(145);
		
		else if(input[i] == 47) // /
			convert.push(147);
		//std::cout<<convert.back()<<"  ";
	}
	//std::cout<<'\n';
	
	for(int i = 0; i < input.length(); i++)
	{
		if(convert.front() >=  0 && convert.front() <= 100)
		{
			//std::cout<<" number ";
			result.push(convert.front());	
		}
		else
		{
			double oper1 = result.top();
			result.pop();
			double oper2 = result.top();
			result.pop();
			if(convert.front() == 145)
				result.push(oper2-oper1);
			else if(convert.front() == 143)
				result.push(oper2+oper1);
			else if(convert.front() == 147)
				result.push(oper2/oper1);
			else if(convert.front() == 142)
				result.push(oper2*oper1);
		}
		convert.pop();
		//std::cout<<result.top()<<'\n';
	}
	double fianl = result.top();
									 //기본적으로 cout은 6자리 숫자를 출력한다.
	std::cout.setf(std::ios::fixed); //float 출력값 조정, setf 와 반대 == unsetf이다(설정해제)
	std::cout.precision(2);			 //출력을 소수점 2번쨰 자리까지, setf없이 사용할 경우 출력할 문자 자리수로 사용
	std::cout<<fianl;
	return 0;
}

*/