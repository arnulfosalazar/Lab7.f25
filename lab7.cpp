/////////////////////////////////////////////////////////////////////
// Name: Arnulfo Salazar III
// Date: 11/12/2023
// Class: CSCI 1470.04
// Semester: Fall 2025
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: 
/////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <fstream>

void initArray(std::string dictionary[], const int WORDS);
int popArray(std::string dictionary[], const int WORDS, std::ifstream& inFile);
int counter(std::string dictionary[], const int WORDS);

const bool DEBUG = false;

int main() {

	char input;
	std::cout << "Debug? y/n";
	std::cin >> input;
	if (input == 'y') {
		std::cout << "Welcome to the spell checker, little one!" << std::endl << std::endl;
	}
	else if (input == 'n') {
		std::cout << "Welcome to the spell checker, little one!" << std::endl << std::endl;
		std::cout << "Loaded " << counter << " words from dictionary."
	}
	else {
		std::cerr << "Invalid input. Debug? y/n";
	}

	std::ifstream inFile("dictionary.txt");


	const int WORDS = 24500;
	std::string dictionary[WORDS];
	initArray(dictionary, WORDS);
	popArray(dictionary, WORDS, inFile);
	counter(dictionary, WORDS);
	print(dictionary, WORDS);
	inFile.close();



	return 0;
}

void initArray(std::string dictionary[], const int WORDS) {
	for (int i = 0; i < WORDS; i++) {
		dictionary[i] = "";
	}
}

int popArray(std::string dictionary[], const int WORDS, std::ifstream &inFile) {
	if (!inFile) {
		std::cerr << "Oops! Input file not detected!" << std::endl;
		return 1;
	}

	int i = 0;

	while (i < WORDS && getline(inFile, dictionary[i])) {
		i++;
	}
	return i;
}

int counter(std::string dictionary[], const int WORDS) {
	int total = 0;

	for (int i = 0; i < WORDS; i++) {
		if (dictionary[i] != "") {
			total++;
		}
	}

	return total;
}

void print(std::string dictionary[], const int WORDS) {
	for (int i = 0; i < WORDS; i++) {
		std::cout << dictionary[i] << std::endl;
	}
	
}

