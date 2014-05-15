/ Description: Rock, Paper, Scissors Game (with functions)
// Last Changed: February 28, 2014
#include <iostream>
#include <time.h>
#include <cctype>
using namespace std;

char rps_computer();
char rps_player();
void output(char player, char computer);
bool play_again();

int main() {
	srand(time(NULL));
	char computer, player;
	do {
		computer = rps_computer();
		player = rps_player();
		output(player, computer);
	} while (play_again());
}
void output(char p, char c){
	if (p == c){
		cout << "Tie - nobody wins!" << endl;
	} else if (p == 'R'&&c == 'P'){
		cout << "Computer wins - paper covers rock!" << endl;
	} else if (p == 'R'&&c == 'S'){
		cout << "Player wins - rock crushes scissors!" << endl;
	} else if (p == 'P'&&c == 'R'){
		cout << "Player wins - paper covers rock!" << endl;
	} else if (p == 'P'&&c == 'S'){
		cout << "Computer wins - scissors cuts paper!" << endl;
	} else if (p == 'S'&&c == 'R'){
		cout << "Computer wins - rock crushes scissors!" << endl;
	} else if (p == 'S'&&c == 'P'){
		cout << "Player wins - scissors cuts paper!" << endl;
	}
}
char rps_player(){
	char played;
	do{
		cout << "Enter R, P, or S: ";
		cin >> played;
		played = toupper(played);
	} while (played != 'R'&&played != 'P'&&played != 'S');
	return played;
}
char rps_computer(){
	int num = rand() % 3;
	if (num == 0) return 'R';
	if (num == 1) return 'P';
	return 'S';
}
bool play_again() {
	char again;
	do {
		cout << "Do you want to play again (Y/N)? ";
		cin >> again;
		again = toupper(again);
	} while (again != 'Y' && again != 'N');

	if (again == 'Y') return true;
	return false;
}
