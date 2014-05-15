//Michael something
//file IO, find min and max value from number list
//last modified: 3/28/14
//The smallest value was -500 and the largest value was 9999
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void findMinMax(ifstream& inFile);
//pre: input file has successfully opened
//post: after all numbers in list are read, the
//largest and smallest values are outputted to screen

int main(){
	ifstream in;
	in.open("numlist.txt");
	if(in.fail()){
		cout << "Error opening file. Exiting program.\n";
		exit(-1);
	}
	findMinMax(in);
	in.close();
	int x;
	cout << "Press any key followed by ENTER to end the program.";
	cin >> x;
	return 0;
}
void findMinMax(ifstream& inFile){
	int next, min=0, max=0;
	inFile >> next;
	min = next;
	max = next;
	while(inFile >> next){
		if(next<min)
			min = next;
		if(next>max)
			max = next;
	}
	cout << "Smallest number is " << min << endl;
	cout << "Largest number is " << max << endl;
}