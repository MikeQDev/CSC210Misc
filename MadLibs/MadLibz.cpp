//MadLibs file IO
//last modified: 3/28/14
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void keyboard_to_file(ofstream &fout);
// precondition: user is prompted to enter text at keyboard
// postcondition: all text typed by the user, up until the 
// return key, is output to the fout filestream

void startReading(ifstream& in);
//pre: input file has successfully opened
//post: input file is read, input file's content and user
//input has been output to the output file

int main(){
	ifstream in;
	in.open("mad.txt");
	if(in.fail()){
		cout << "Error reading file. Exiting program.\n";
		exit(-1);
	}
	startReading(in);
	in.close();
	int x;
	cout << "Story written to 'story.txt'. Press any key followed by ENTER to end the program.";
	cin >> x;
	return 0;
}
void startReading(ifstream& in){
	ofstream out;
	out.open("story.txt");
	if(out.fail()){
		cout << "Error opening out file. Exiting program.\n";
		exit(-1);
	}
	char p;
	in.get(p);
	while(!in.eof()){
		if(p=='#'){
			in.get(p);
			if(p=='D'){
				cout << "Enter a day of the week: ";
				keyboard_to_file(out);
			}else if(p=='A'){
				cout << "Enter an animal (include a/an): ";
				keyboard_to_file(out);
			}else if(p=='V'){
				cout << "Enter a verb (ending with 'ing'): ";
				keyboard_to_file(out);
			}else if(p=='F'){
				cout << "Enter the name of a friend: ";
				keyboard_to_file(out);
			}
		}else{
			out << p;
		}
		in.get(p);
	}
	out.close();
	
}
void keyboard_to_file(ofstream &fout) {
   char c;
   do {
	cin.get(c);
        if (c!= '\n') fout << c;
   } while (c != '\n');	
} 
