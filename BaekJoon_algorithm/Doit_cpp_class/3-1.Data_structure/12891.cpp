
/*
#include<iostream>

using namespace std;

int length;
int PartLength;
int count =0;
int A = 0 , C = 0 , G = 0, T = 0;
int CheckA = 0, CheckC = 0, CheckG = 0, CheckT = 0;
int front, back;
string str = "";

void checkNowF(char Now);
void checkWhatChar(char whatchar);
void CheckTrue(int A, int C, int G, int T);

int main()
{
	cin >> length;
	cin >> PartLength;
	front = 0; back = PartLength - 1;
	cin >> str;
	cin >> CheckA >> CheckC >> CheckG >> CheckT;
	for(int i = 0; i < PartLength; i++)
	{
		checkWhatChar(str[i]);
	}
	CheckTrue(A,C,G,T);
	
	while(back < length-1)
	{
		checkNowF(str[front]);
		front ++;
		back ++;
		checkWhatChar(str[back]);
		//cout << front << "  " << back<<"  "<<str[back]<<'\n';
		CheckTrue(A ,C ,G ,T);
	}
	cout <<count <<'\n';
}



void checkNowF(char Now)
{
	switch(Now)
	{
		case 'A':
			A --;
			break;
		case 'C':
			C --;
			break;
		case 'G':
			G --;
			break;
		case 'T':
			T --;
			break;
	}
}

void checkWhatChar(char whatchar)
{
	switch(whatchar)
	{
		case 'A':
			A ++;
			break;
		case 'C':
			C ++;
			break;
		case 'G':
			G ++;
			break;
		case 'T':
			T ++;
			break;
		default:
			break;
				
		}
}

void CheckTrue(int A, int C, int G, int T)
{
	//cout <<"correct:  "<< CheckA <<" "<< CheckC<<" "<<CheckG <<" "<<CheckT<<'\n';
	//cout <<"current:  "<<A <<" " <<C<< " "<<G<<" "<<T<<" "<<"\n\n\n";
	if(CheckA <= A && CheckC <= C && CheckG <= G && CheckT <= T)
		count ++;
}
*/