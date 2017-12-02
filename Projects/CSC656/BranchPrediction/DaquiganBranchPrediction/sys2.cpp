/*
 *	sys2.cpp
 *	Dynamic Branch Prediction
 *	Author: Darrel Daquigan
 *	March 27, 2017
 *
 *	To compile this program using g++, first compile 
 *	the cpp file into the object code file "sys1.o":
 *			g++ -c sys2.cpp

 *	Next link to the object code creating the executable
 *  file "sys1":
 *			g++ -o sys2 sys2.o
 *
 *	Now the executable file, "sys2.exe", can be called 
 *	to run the program:
 *			./sys2 <filename> <#prediction entries> <#buffer entries> <verbose mode(optional with [-v])>
 *	where filename is the name of the trace file to be analyzed,
 *	#prection entries is the size (power of 2) of the prediction buffer,
 *	and #buffer entries is the size (power of 2) of the branch target buffer 
 *
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int main (int argc, char* argv[]){
	if (argc == 4 || argc == 5){	//collecting arguments
		ifstream trace(argv[1]);	//trace file
		int n = atoi(argv[2]);		//prediction buffer size
		int m = atoi(argv[3]);		//branch target buffer size
		bool verbose = false;
		if (argc == 5){
			if(strcmp(argv[4], "[-v]") == 0 || strcmp(argv[4], "-v") == 0){
				verbose = true;
			}
		}

		vector<int> branchAddress;
		vector<int> branchType;
		vector<int> branchTarget;
		vector<int> taken;



		string parts[4];
		string line;

		//parsing the file
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
			mispredictions = 0,
			btbMiss = 0,
			btbAccess = 0;



		vector<int> predictor(n,1);
		vector< vector<int> > btb(m, vector<int>(3)); // branch target buffer
		
		/*
			btb[i][0] = tag
			btb[i][1] = valid
			btb[i][2] = bta
		*/
		for (int i = 0; i < m; i++){
			btb[i][0] = -1;
			btb[i][1] = 0;
			btb[i][2] = -1;
		}

		stringstream verboseStream;
		int totalBranches = taken.size();

		
		for (int i = 0; i < totalBranches; i++){
			if (branchType[i] == 1){

				/*
				/	splitting up the current branch address to find the correct
				/	index for the prediction buffer, index for the branch target
				/	buffer, and the tag
				*/
				int predictionIndex = (branchAddress[i] >> 2) & (n-1);
				int btbIndex = (branchAddress[i] >> 2) & (m-1);
				int btbTag = branchAddress[i] >> (2 + (int)log2((double)m));

				//	fill the stream if using verbose mode
				if (verbose){
					verboseStream.str(string());
					verboseStream << '\n' << numBranches << ' ';
				}

				//	collect branch statistics
				numBranches++;
				if (branchAddress[i] < branchTarget[i]){
					forward++;
					if (taken[i] == 1){
						forwardTaken++;
					}
				} else {
					backward++;
					if (taken[i] == 1){
						backwardTaken++;
					}
				}


				//fill verbose stream
				if (verbose){
					verboseStream << hex << predictionIndex << ' ' 
						<< predictor[predictionIndex] << ' ';
				}


				if (predictor[predictionIndex] > 1){ //predicted taken
					btbAccess++;
					if (btb[btbIndex][1] == 1){ //if valid bit is on

						//	tags don't match, btb miss
						if (btb[btbIndex][0] != btbTag){
							btbMiss++;
						}
					}

					if (taken[i] == 0){
						mispredictions++;
					}
				}
				else{
					if (taken[i] == 1){
						mispredictions++;
					}
				}

				//	update prediction (2-bit saturation counter)
				if (taken[i] == 1){

					if (predictor[predictionIndex] < 3){
						predictor[predictionIndex]++;
					}

					btb[btbIndex][0] = btbTag;			//tag
					btb[btbIndex][1] = 1;				//valid bit
					btb[btbIndex][2] = branchTarget[i];	//branch target address
				}
				else{
					if (predictor[predictionIndex] > 0){
						predictor[predictionIndex]--;
					}
				}


				if (verbose){
					verboseStream << predictor[predictionIndex] << ' '
						<< hex << btbIndex << ' ' 
						<< hex << btb[btbIndex][0] << ' '
						<< btbAccess << ' ' << btbMiss;
					cout << verboseStream.str();
				}

			}
		}

		cout << "\n\nNumber of branches = " << numBranches
				<< "\nNumber of forward branches = " << forward
				<< "\nNumber of forward taken branches = " << forwardTaken
				<< "\nNumber of backward branches = " << backward
				<< "\nNumber of backward taken branches = " << backwardTaken
				<< "\nNumber of mispredictions = " << mispredictions
				<< "\nMisprediction rate = " << ((float)mispredictions/(float)numBranches)
				<< "\nNumber of BTB misses = " << btbMiss
				<< "\nBTB miss rate = " << (float)btbMiss/(float)btbAccess;

	}
	else{
		cout << "Wrong number of arguments. Try\n./sys2 <filename> <#prediction entries> <#buffer entries> <verbose mode(optional with [-v])>\n";
	}
}

