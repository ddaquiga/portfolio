#include <iostream>

using namespace std;

void mva();
void initialize();

int main(){
	mva();
}

void mva(){
	int mode;
	int max; 	//max number of terminals for interactive system,
				//max degree of multiprogramming for batch system

	double thinkTime;
	int totalResources;


	//gather inputs
	do{
		cout << "Enter system type:\n\t1 - interactive\n\t2 - batch\n";
		cin >> mode;
	}while(mode != 1 && mode != 2 );

	if (mode == 1){ //interactive
		cout << "Enter average think time [sec]: ";
		cin >> thinkTime;

		cout << "Enter maximum number of terminals: ";
	}
	else
		cout << "Enter maximum degree of multiprogramming: ";
	cin >> max;

	cout << "Enter total number of resources: ";
	cin >> totalResources;

	string type[totalResources];
	int numResources[totalResources];
	double demand[totalResources];
	double residence[max][totalResources];
	double response[max];
	for (int i = 0; i < max; i++){
		response[i] = 0;
	}
	double throughput[max];
	double queueLength[max][totalResources];

	cout << "Enter resource types:\n";
	for (int i = 0; i < totalResources; i++){
		cout << "\t" << (i+1) << ": ";
		cin >> type[i];
	}
	
	cout << "Enter number of resources:\n";
	for (int i = 0; i < totalResources; i++){
		cout << '\t'<< (i+1) << ' ' << type[i] << ": ";
		cin >> numResources[i];
	}

	cout << "Enter demand per transaction [sec]:\n";
	for (int i = 0; i < totalResources; i++){
		cout << '\t'<< (i+1) << ' ' << type[i] << ": ";
		cin >> demand[i];
		cout << "\n\n";
	}

	//start MVA algorithm

	for (int i = 0; i < max; i++){

		//Find Rj(i) = Dj(i)[1+Q(i-1)]
		if (i == 0){
			for (int j = 0; j < totalResources; j++){
				residence[i][j] = demand[j];
			}
		}
		else{
			for (int j = 0; j < totalResources; j++){
				residence[i][j] = demand[j] * (1 + queueLength[i-1][j]);
			}	
		}

		//Find R(i)
		for (int j = 0; j < totalResources; j++){
			response[i] += residence[i][j] * numResources[j];
		}

		//Find X(i)
		if (mode == 1) throughput[i] = (i+1)/(thinkTime + response[i]);
		else throughput[i] = (i + 1)/response[i];

		//Find Queue Lengths
		for (int j = 0; j < totalResources; j++){
			queueLength[i][j] = throughput[i] * residence[i][j];
		}
	}

	//display results
	if (mode == 1)
		cout << "Maximum number of terminals is " << max << 
			"\nAverage think time is " << thinkTime << "sec\n";
	else cout << "Maximum degree of multiprogramming is " << max << '\n';
	
	cout << "Resource identifier - Resource type, Number of resources, Total demand per transaction[sec]\n";
	for (int j = 0; j < totalResources; j++){
		cout << (j+1) << " - " << type[j] << ", " << 
				numResources[j] << ", " << demand[j] << '\n';
	}

	cout << "\nSystem Response Times:\n";
	for(int i = 0; i < max; i++){
		cout << '\t' << (i+1) << " - " << response[i] << '\n';
	}
		
	cout << "\nSystem throughput:\n";
	for (int i = 0; i < max; i++){
		cout << '\t' << (i+1) << " - " << throughput[i] << '\n';
	}
	
	cout << "\nQueue lengths:\n";
	for (int j = 0; j < totalResources; j++){
		cout << '\t' << (j+1) << " - " << type[j] << ":\n";
		for (int i = 0; i < max; i++){
			cout << "\t\t" << (i+1) << " - " << queueLength[i][j] << '\n';
		}
	}

	if (mode == 2) thinkTime = 0;

	cout << "\nIndividual Throughputs -\n";
	for (int j = 0; j < totalResources; j++){
		cout << '\t' << (j+1) << " - " << type[j] << ":\n";
		for (int i = 0; i < max; i++){
			cout << "\t\t" << (i+1) << " - " << ((i+1)/(thinkTime + residence[i][j])) << '\n';
		}
	}

	cout << "\nUtilitizations -\n";
	for (int j = 0; j < totalResources; j++){
		cout << '\t' << (j+1) << " - " << type[j] << " :\n";
		for (int i = 0; i < max; i++){
			cout << "\t\t" << (i+1) << " - " << throughput[i] * demand[j] << '\n';
		}
	}

}

