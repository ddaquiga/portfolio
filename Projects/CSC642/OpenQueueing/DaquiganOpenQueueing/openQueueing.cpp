#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h>


using namespace std;

/*
	find:
		A,S,W,R,J,U
*/
void initialize();
void createJobs();
double getA(int);
double getS(int);
double arrivalMean(int);
double arrivalSD(int);
double serviceMean(int);
double serviceSD(int);
double waitMean(int);
double waitSD(int);
double responseMean(int);
double responseSD(int);
double queueMean();
double queueSD();


struct Job
{
	double arrival;
	double service;
	double wait;
};

double totalTime, currA, currS;
int jobsStarted, jobsDone, totalJobs, update,
	aDist, sDist;
vector<int> queue;	
vector<Job> jobs;
vector<double> numJobsTime;

int main(){
	initialize();

	while (jobsDone < totalJobs){
		if (queue.size() == 0){
			totalTime += currA;
			numJobsTime[0] += currA;
			if (jobsStarted < totalJobs){
				queue.push_back(jobsStarted);
				jobsStarted++;
				currA = jobs[queue[0]].arrival;
				currS = jobs[queue[0]].service;
			}
		}
		else if(currA < currS){
			totalTime += currA;
			currS -= currA;

			if (numJobsTime.size() < queue.size())
				numJobsTime.push_back(currA);
			else
				numJobsTime[queue.size()] += currA;

			for(int i=0; i<queue.size()-1; i++){
				jobs[queue[i+1]].wait += currA;
			}

			if (jobsStarted < totalJobs){
				queue.push_back(jobsStarted);
				jobsStarted++;
				currA = jobs[queue.back()].arrival;
			}
			else currA = 99;
		}

		else if(currS < currA){
			totalTime += currS;
			currA -= currS;
			if (numJobsTime.size() < queue.size())
				numJobsTime.push_back(currS);
			else
				numJobsTime[queue.size()] += currS;

			for (int i= 0; i < queue.size()-1; i++){
				jobs[queue[i+1]].wait += currS;
			}

			queue.erase(queue.begin());
			jobsDone++;
			currS = jobs[queue[0]].service;
		}
		else if(currS == currA){
			totalTime += currS;
			if (numJobsTime.size() < queue.size())
				numJobsTime.push_back(currS);
			else
				numJobsTime[queue.size()] += currS;

			for (int i= 0; i < queue.size()-1; i++){
				jobs[queue[i+1]].wait += currS;
			}

			if (jobsStarted < totalJobs){
				queue.push_back(jobsStarted);
				jobsStarted++;
				currA = jobs[queue.back()].arrival;
			}
			else currA = 99;
			queue.erase(queue.begin());
			jobsDone++;

			if(queue.size() > 0 )
				currS = jobs[queue[0]].service;
			else currS = 98;
		}

		/* ---for debugging
				
		cout << "----------------------------------\n" <<
			"jobsStarted: " << jobsStarted <<
			"\njobsDone: " << jobsDone <<
			"\ntotalTime: " << totalTime <<
			"\nnumJobsTime:\n";
		for ( int i = 0; i < numJobsTime.size(); i++){
			cout << numJobsTime[i] << ' ';
		}
		cout << "\ncurrA: " << currA <<
			"\ncurrS: " << currS <<
			"\nqueue:\n";

		cout << "queue size: " << queue.size();
		
		for (int i = 0; i < queue.size(); i++){
			cout << queue[i] << ' ';
		}

		cout << "\njobs:\n\tarrival:\n\t";
		for (int i =0; i <totalJobs; i++){
			cout << jobs[i].arrival << ' ';
		}
		cout << "\n\tservice:\n\t";
		for (int i =0; i <totalJobs; i++){
			cout << jobs[i].service << ' ';
		}
		cout << "\n\twait:\n\t";
		for (int i =0; i <totalJobs; i++){
			cout << jobs[i].wait << ' ';
		}

		
		cout << "\n----------------------------------\n";
		*/

		if ((jobsDone > 0 && jobsDone % update == 0) || jobsDone == totalJobs){
			cout << "---------------------------------\n" << 
				"jobs started: " << jobsStarted <<
				"\njobs finished: " << jobsDone <<
				"\nqueue size: " << queue.size() <<
				"\ninterarrival time mean: " << arrivalMean(jobsDone) <<
				"sec\ninterarrival standard deviation:" << arrivalSD(jobsDone) <<
				"sec\nservice time mean: " << serviceMean(jobsDone) <<
				"sec\nservice time standard deviation: " << serviceSD(jobsDone) <<
				"sec\nwait time mean: " << waitMean(jobsDone) <<
				"sec\nwait time standard deviation: " << waitSD(jobsDone) <<
				"sec\nresponse time mean: " << responseMean(jobsDone) <<
				"sec\nresponse time standard deviation: " << responseSD(jobsDone) <<
				"sec\nqueue length mean: " << queueMean() <<
				"\nqueue length standard deviation: " << queueSD() <<
				"\nutilization: " << (totalTime- numJobsTime[0])/totalTime <<
	
				"\n---------------------------------\n";
				
		}		
	}

	cout << "---------------------------------\n" <<
	 	"U = " << (totalTime - numJobsTime[0])/totalTime <<
	 	"\nQ = " << queueMean() <<
	 	"\nR = " << responseMean(totalJobs) <<
	 	"\n---------------------------------\n";

}

void initialize(){
	cout << "start initialize.....\n";
	totalTime = 0;
	numJobsTime.push_back(0);
	jobsStarted = 0;
	jobsDone = 0;

	cout << "\t1- Constant Value : 2sec\n" <<
		"\t2- Exponential with mean value of 2 sec\n" <<
		"\t3- Uniform from 1 to 3 sec\n" <<
		"Choose an interarrival time distribtion: ";
	cin >> aDist;

	cout << "\t1- Constant Value : 1sec\n" <<
		"\t2- Exponential with mean value of 1 sec\n" <<
		"\t3- Uniform from 1 to 2 sec\n" <<
		"Choose an service time distribtion: ";
	cin >> sDist;

	cout << "Enter total number of jobs: ";
	cin >> totalJobs;
	cout << "Enter update interval: ";
	cin >> update;
	
	srand(time(NULL));

	createJobs();
	currA = getA(aDist);
	cout << "end initialize......\n";

	/*
	cout << "----------------------------------\n" <<
			"jobsStart: " << jobsStart <<
			"\njobsDone: " << jobsDone <<
			"\ntotalTime: " << totalTime <<
			"\nnumJobsTime:\n";
	for ( int i = 0; i < numJobsTime.size(); i++){
		cout << numJobsTime[i] << ' ';
	}
	cout << "\ncurrA: " << currA <<
		"\n currS: " << currS <<
		"\n queue:\n";

	for (int i = 0; i < queue.size(); i++){
		cout << queue[i] << ' ';
	}
	cout << "\njobs:\n\tarrival:\n\t";
	for (int i =0; i <totalJobs; i++){
		cout << jobs[i].arrival << ' ';
	}
	cout << "\n\tservice:\n\t";
	for (int i =0; i <totalJobs; i++){
		cout << jobs[i].service << ' ';
	}
	cout << "\n\twait:\n\t";
	for (int i =0; i <totalJobs; i++){
		cout << jobs[i].wait << ' ';
	}
	cout << "\n----------------------------------\n";
	*/
}

void createJobs(){
	for (int i = 0; i < totalJobs; i++){
		Job j;
		j.arrival = getA(aDist);
		j.service = getS(sDist);
		j.wait = 0;
		jobs.push_back(j);
	}
}

double getA(int dist){
	if (dist == 1) return 2; 	//constant 2 sec
	if (dist == 2) return -log((double)rand()/RAND_MAX)*(2); //exp 2sec mean
	if (dist == 3) return ((double)rand()/RAND_MAX) * 2 + 1; // uniform 1 - 3 sec
}

double getS(int dist){
	if (dist == 1) return 1; 	//constant 1 sec
	if (dist == 2) return -log((double)rand()/RAND_MAX); //exp 1sec mean
	if (dist == 3) return ((double)rand()/RAND_MAX) + 1; // uniform 1-2 sec
}


double arrivalMean(int n){
	double sum = 0;
	for (int i = 0 ; i < n ; i++){
		sum += jobs[i].arrival;
	}
	return sum/n;
}
double arrivalSD(int n){
	double sd = 0, mean = arrivalMean(n);
	for (int i = 0; i < n; i++){
		sd += (jobs[i].arrival - mean) * (jobs[i].arrival - mean);
	}
	return sqrt(sd/n);
}
double serviceMean(int n){
	double sum = 0;
	for (int i = 0 ; i < n ; i++){
		sum += jobs[i].service;
	}
	return sum/n;
}
double serviceSD(int n){
	double sd = 0, mean = serviceMean(n);
	for (int i = 0; i < n; i++){
		sd += (jobs[i].service - mean) * (jobs[i].service - mean);
	}
	return sqrt(sd/n);
}
double waitMean(int n){
	double sum = 0;
	for (int i = 0 ; i < n ; i++){
		sum += jobs[i].wait;
	}
	return sum/n;
}
double waitSD(int n){
	double sd = 0, mean = waitMean(n);
	for (int i = 0; i < n; i++){
		sd += (jobs[i].wait - mean) * (jobs[i].wait - mean);
	}
	return sqrt(sd/n);
}
double responseMean(int n){
	double sum = 0;
	for (int i = 0 ; i < n ; i++){
		sum += jobs[i].wait + jobs[i].service;
	}
	return sum/n;
}
double responseSD(int n){
	double sd = 0, mean = arrivalMean(n);
	for (int i = 0; i < n; i++){
		sd += (jobs[i].wait + jobs[i].service - mean) * 
			(jobs[i].wait + jobs[i].service - mean);
	}
	return sqrt(sd/n);
}
double queueMean(){
	double mean = 0;
	for (int i = 0 ; i < numJobsTime.size(); i++){
		mean += numJobsTime[i] * i/totalTime;
	}
	return mean;
}
double queueSD(){
	int nonZero = 0;
	double xSum = 0, wSum = 0;
	for (int i = 0; i < numJobsTime.size(); i ++){
		if (numJobsTime[i] != 0){
			nonZero++;
		}
		
		xSum += (i - queueMean()) * (i - queueMean()) * numJobsTime[i]/ totalTime;
		wSum += numJobsTime[i]/totalTime;
	}

	return sqrt(nonZero * xSum / ((nonZero - 1) * wSum));
}