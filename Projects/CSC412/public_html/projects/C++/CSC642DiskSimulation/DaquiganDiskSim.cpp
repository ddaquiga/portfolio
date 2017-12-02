#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

void diskSeek(int Q);
double seekTime(int x);

//Quantum Atlas III parameters
int xmax = 8057; //cylinders
double C = 9.1; //GB
int N = 7200; //rpm
int xprime = 1686;
double t = 1.5455; //ms
double c = 0.3197; //ms
double r = 0.3868;
int numAccesses = 10000;

int main ()
{
	srand (time(NULL));
	for (int i = 0; i < 20; i++)
	{
		diskSeek(i + 1);
	}
}

void diskSeek(int Q)
{	
	bool nanFlag = false;
	//fill dq
	vector<int> dq;

	for (int i = 0; i < Q; i++)
	{
		dq.push_back(rand() % xmax + 1);
	}

	//start trial
	int currentCyl = rand() % xmax + 1;
	double totalDistance = 0;
	double totalTime = 0;
	for (int i = 0; i < numAccesses; i++)
	{
		int closestDistance = xmax;
		int closestIndex;
		//find closest
		for (int j = 0; j < Q; j++)
		{
			if ( abs(dq[j] - currentCyl) <= closestDistance)
			{
				closestDistance = abs(dq[j] - currentCyl);
				closestIndex = j;
			}
		}

		//add to totals
		totalDistance += closestDistance;
		if (closestDistance != 0)
			totalTime += seekTime(closestDistance);
		//update
		currentCyl = dq[closestIndex];
		dq[closestIndex] = rand() % xmax + 1;

		
	}
	//averages
	double avgDistance = totalDistance/double(numAccesses);
	double avgTime = totalTime/double(numAccesses);

	cout << "Q: " << Q << " avgDistance: " << avgDistance << " avgTime: " <<
		avgTime << "\n";
}

double seekTime(int x)
{
	double result;
	if ( x <= xprime )
		result =  t + (c * pow((x-1),r));
	else
		result =  ((c * r * (x - xprime))/pow(xprime - 1,1-r)) + t + (c * pow(xprime-1,r));

 	return result;
}

