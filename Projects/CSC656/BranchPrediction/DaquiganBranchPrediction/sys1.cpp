/*
 *	sys1.cpp
 *	Static Branch Prediction
 *	Author: Darrel Daquigan
 *	March 27, 2017
 *
 *	To compile this program using g++, first compile 
 *	the cpp file into the object code file "sys1.o":
 *			g++ -c sys1.cpp

 *	Next link to the object code creating the executable
 *  file "sys1":
 *			g++ -o sys1 sys1.o
 *
 *	Now the executable file, "sys1.exe", can be called 
 *	to run the program:
 *			./sys1 <filename>
 *	where filename is the name of the trace file to be analyzed.
 *
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main (int argc, char* argv[]){
	if (argc == 2){

		ifstream trace(argv[1]);
		vector<int> branchAddress;
		vector<int> branchType;
		vector<int> branchTarget;
		vector<int> taken;

		string parts[4];
		string line;

		//parse the trace file
		while (getline(trace, line)){
			istringstream iss(line);
			if(!(iss >> parts[0] >> parts[1] >> parts[2] >> parts[3]))
				break;


			//extract branch address
			stringstream ssAddress;
			ssAddress << hex << parts[0];
			int address;
			ssAddress >> address;
			branchAddress.push_back(address);


			//extract branchType
			branchType.push_back(atoi(parts[1].c_str()));

			//extract branch target
			stringstream ssTarget;
			ssTarget << hex << parts[2];
			int target;
			ssTarget >> target;
			branchTarget.push_back(target);

			//extract branch taken
			taken.push_back(atoi(parts[3].c_str()));
		}


		int numBranches = 0,
			forward = 0,
			forwardTaken = 0,
			backward = 0,
			backwardTaken = 0,
			mispredictions = 0;

		// go through the trace
		for (int i = 0; i < taken.size(); i++){
			if (branchType[i] == 1){ 	//only count direct branches
				numBranches++;

				//forward branches predicted not taken
				if (branchAddress[i] < branchTarget[i]){
					forward++;
					if (taken[i] == 1){
						forwardTaken++;
						mispredictions++;
					}
				}

				//backward branches predicted taken
				else {
					backward++;
					if (taken[i] == 1){
						backwardTaken++;
					} else {
						mispredictions++;
					}
				}
			}
		}
		

		cout << "\nNumber of branches = " << numBranches
				<< "\nNumber of forward branches = " << forward
				<< "\nNumber of forward taken branches = " << forwardTaken
				<< "\nNumber of backward branches = " << backward
				<< "\nNumber of backward taken branches = " << backwardTaken
				<< "\nNumber of mispredictions = " << mispredictions
				<< "\nMisprediction rate = " << ((float)mispredictions/(float)numBranches)
				<< "\n\n";
	}
	else {
		cout << "Wrong number of arguments. Try\n ./sys1 <filename>\n";
	}
}