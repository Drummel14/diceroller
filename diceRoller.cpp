#include <iostream>
#include <random>
#include <sstream>
#include "time.h"
using namespace std;

void diceRoll (string input, string delim) {
	//variables
	int randomDice = 0;
	int total = 0;
	
	//Generate the amount of dice and the dice type with substr
	string numOfDice = input.substr(0, input.find(delim));
	string typeOfDice = input.substr((input.find(delim) + 1), input.length());
	cout << "\nNumber of dice: " << numOfDice << "\nType of dice: " << typeOfDice << endl;
	cout << "-----------------------------------------------------" << endl;
	
	//  Using data achieved previously, generate the proper numbers for the dice,
	//and iterate the correct number of times.
	for (int i = 0; i < stoi(numOfDice); i++) {
		randomDice = rand() % stoi(typeOfDice) + 1;
		cout << i+1 << ":   " << randomDice << "\n";
		total += randomDice;
	}
	
	//Printing
	cout << "You rolled a " << total << endl;
}

int main(int argc, char* argv[]) {
	//Variables and declarations
	string input = "";
	string delim = "d";
	int total = 0;
	int randomDice = 0;

	//Setting up srand() with the current time, to truly make this random
	srand(time(NULL));
	
	//If the user passes no arguments
	if(argc == 1) {
		//User prompting
		cout << "What kind of dice do you wish to roll, dude?" << endl;
		cin >> input;
		diceRoll(input, delim);
	}
	
	//If the user passes us a die type from the command line
	else if (argc == 2) {
		string input = argv[1];
		stringstream ss = stringstream(input);
		ss >> input;
		diceRoll(input, delim);
	}
	
	return 0;
}
