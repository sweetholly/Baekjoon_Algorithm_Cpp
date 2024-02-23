/*
stringstram 공부하기
*/

/*
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
#define endl '\n'

using namespace std;

int main()
{
	vector<queue<string>>queue_arr;
	queue<string>compare_string;
	
	int N;
	string input_compare;
	cin >> N;
	cin.ignore();
	
	//앵무새의 string vetor<queue<string>>에 입력
	//sstream을 이용해 단어 단위로 연결, vector의 큐 요소에
	//단어를 저장
	for(int i = 0; i < N; i++)
	{
		queue<string>save;
		string line;
		string input;
		getline(cin, line);
		istringstream ss(line);
		while(getline(ss, input, ' '))
		{
			//cout<<"input"<<endl;
			save.push(input);
		}
		queue_arr.push_back(save);
	}
	
	//검사할 문장 입력
	//sstream을 이용해 큐에 단어 단위로 저장
	getline(cin, input_compare);
	istringstream comparess(input_compare);
	while(getline(comparess, input_compare, ' '))
	{
		compare_string.push(input_compare);
	}
	int temp_size = compare_string.size();
	
	// cseteram이 작성한 문장의 오류 확인
	// cseteram의 문장의 각 단어가 queue_arr 큐 사이에 기록되어있는지 확인,
	// 만약 기록되어있지 않은 단어가 포함되어있으면 루프문 중단, 프로그램 종료
	while(!compare_string.empty())
	{
		bool success = 1;
		string top = compare_string.front();
		for(int i = 0; i<N; i++)
		{
			if(!queue_arr[i].empty() &&queue_arr[i].front() == top)
			{
				compare_string.pop();
				queue_arr[i].pop();
				success = 0;
				break;
			}
		}
		//없는 단어를 입력한 경우
		if(success == 1)
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	
	
	//모든 단어가 큐에 포함되어있었더라도, 사용하지 않은 단어가 있으면 틀림
	for(int i = 0; i< N; i++)
	{
		if(!queue_arr[i].empty())
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	
	//모든 조건 만족하였음
	cout<<"Possible"<<endl;
	return 0;
}
*/