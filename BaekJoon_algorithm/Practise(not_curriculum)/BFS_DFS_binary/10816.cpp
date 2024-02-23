/*
#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, M;
	std::vector<int>Narr;
	int comp;

	std::cin>> N;
	for(int i = 0; i < N; i++)
	{
		std::cin>>comp;
		Narr.push_back(comp);
	}
	std::sort(Narr.begin(), Narr.end());
	std::cin>>M;
	for(int i = 0; i < M; i++)
	{
		std::cin>>comp;
		std::cout<<std::upper_bound(Narr.begin(), Narr.end(), comp) 
						- std::lower_bound(Narr.begin(), Narr.end(), comp)<<" ";
	}
	return 0;
}*/