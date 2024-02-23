/*
#include<iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sizeA, sizeB;
	int i = 0;
	int pointA = 0, pointB = 0, pointS = 0;
	cin >> sizeA >> sizeB;
	int *ArrA = new int[sizeA]; 
	int *ArrB = new int[sizeB]; 
	int *ArrS = new int[sizeA + sizeB];
	for(i = 0; i < sizeA; i++)
	{
		cin >> ArrA[i]; 
	}
	
	for(i = 0; i < sizeB; i++)
	{
		cin >> ArrB[i]; 
	}
	while(pointS < sizeA + sizeB)
	{
		if( pointA >= sizeA || pointB >= sizeB)
		{
			if(pointA >= sizeA)
			{	
				ArrS[pointS] = ArrB[pointB];
				if(pointB < sizeB)
					pointB ++;
			}
			else if(pointB >= sizeB)
			{	
				ArrS[pointS] = ArrA[pointA];
				if(pointA < sizeA)
					pointA ++;
			}
		}
		
		
		else{
			if(ArrA[pointA] < ArrB[pointB])
			{
				ArrS[pointS] = ArrA[pointA];
				if(pointA < sizeA)
					pointA ++;
			}
			else
			{
				ArrS[pointS] = ArrB[pointB];
				if(pointB < sizeB)
					pointB ++;
			}
		}
		pointS ++;
	}
	for(i = 0; i < pointS; i++)
	{
		cout << ArrS[i]<<" ";
	}
	
	delete[] ArrA;
	delete[] ArrB;
	delete[] ArrS;
}
*/