#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct member{
    int age;
    string name;
};

int cmp(member a, member b)
{
	return a.age < b.age;
}

int main()
{
    int N;
	int age;
	string name;
    cin >> N;
    member* group = new member[N];
    for(int i = 0; i< N; i++)
	{
		cin>> age;
		cin.clear();
		getline(cin, name);
		group[i].age = age;
		group[i].name = name;
	}
	stable_sort(group, group+N, cmp);
	
	for(int i = 0; i< N; i++)
	{
		cout<<group[i].age<<group[i].name<<'\n';
	}
	delete[] group;
}