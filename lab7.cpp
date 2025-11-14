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
#include <chrono>

//prototypes
void initArray(std::string dictionary[], const int WORDS);
int popArray(std::string dictionary[], const int WORDS, std::ifstream& inFile);
int counter(std::string dictionary[], const int WORDS);
void print(std::string dictionary[], const int WORDS);

//constant variables
const bool DEBUG = true;

int main() {
	//initialize constant, array, and open text file to be used
	const int WORDS = 24500;
	std::string dictionary[WORDS];
	std::ifstream inFile("dictionary.txt");

	std::cout << "Welcome to the spell checker, little one!" << std::endl << std::endl;

	
	auto start = std::chrono::high_resolution_clock::now();
	initArray(dictionary, WORDS);
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = end - start;

	if (DEBUG) {
		std::cout << "DEBUG: Initialization took " << elapsed.count() << " microseconds." << std::endl;
	}

	start = std::chrono::high_resolution_clock::now();
	popArray(dictionary, WORDS, inFile);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;

	if (DEBUG) {
		std::cout << "DEBUG: Loading took " << elapsed.count() << " microseconds." << std::endl;
	}

	if (DEBUG) {
		start = std::chrono::high_resolution_clock::now();
		print(dictionary, WORDS);
		end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;

		std::cout << "DEBUGGING: Printing took " << elapsed.count() << " microseconds." << std::endl;
	}
		
	std::cout << "Loaded " << counter(dictionary, WORDS) << " words from the dictionary.";


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