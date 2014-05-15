//Last modified: 3/14/2014
//Converts 24-hour time notation to 12-hour notation
#include <iostream>
using namespace std;


void getTime(int& hours, int& mins);
//Pre: User knows & inputs time in 24-hr. notation
//Post: Set value of hours and minutes in main function

void conversion(int& hour, char& AP);
//Pre: User has entered the time in 24-hour notation
//Post: Converts 24-hour notation to 12-hour notation

void output(int hour, int min, char AP);
//Pre: Time has been converted to 12-hour notation
//Post: 12-hour notation has been outputted


int main(){
	char again;
	do{
		int hours, mins;
		char AP = 'A';
		getTime(hours, mins);
		conversion(hours, AP);
		output(hours, mins, AP);

		cout << "\nRun again? (Y/N): ";
		cin >> again;
		cout << endl;
	}while(toupper(again) == 'Y');
	return 0;
}
void getTime(int& hours, int& mins){
	do{
		cout << "Enter hours and minutes: ";
		cin >> hours >> mins;
	}while(mins>=60 || mins < 0 || hours >=24 || hours < 0);
}
void conversion(int& hour, char& AP){
	if(hour>12){ //convert to PM.
		AP = 'P';
		hour -= 12;
	}
	if(hour == 12){
		AP = 'P';
	}
	if(hour == 0){
		hour = 12;
	}
}
void output(int hour, int min, char AP){
	if(min == 0)
		cout << "The time in 12-hour notation is: "
		<< hour << ":" << min << "0 " << AP << endl;
	else
		cout << "The time in 12-hour notation is: "
		<< hour << ":" << min << " " << AP << endl;
}