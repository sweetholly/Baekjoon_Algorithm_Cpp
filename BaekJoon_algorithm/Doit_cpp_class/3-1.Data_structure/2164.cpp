/*
#include<iostream>
#include<queue>

int main()
{
	int N;
	std::cin >>N;
	std::queue<int>card;
	for(int i = 1; i <= N; i ++)
	{
		card.push(i);
	}
	
	//std::cout <<"queue size : "<<card.size()<<"  start"<<'\n';
	while(card.size() > 1)
	{
		//std::cout<<card.front() <<"  ";
		card.pop();
		//std::cout<<card.front() <<'\n';
		card.push(card.front());
		card.pop();
	}
	std::cout <<card.front();
}

*/