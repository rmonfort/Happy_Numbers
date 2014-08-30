#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::set;

// Determines if a number is happy number.
bool isHappyNumber(const int &number_to_test)
{
	int sum = 0;
	int number = number_to_test;

	// Set to test for unhappy number infinite cycle
	int unhappy_sequence[] = { 4, 16, 37, 58, 89, 145, 42, 20 };
	set<int> unhappy_numbers(unhappy_sequence, unhappy_sequence + 8);

	do
	{
		// Test if number is 1 or 0
		if (number == 1 || number == 0)
		{
			break;
		}
		// Test if number is part of unhappy number infinite cycle
		else if (unhappy_numbers.count(number) != 0)
		{
			number = 0;
			break;
		}
		sum = 0;
		// Seperate number into digits then square each digit and add them together
		while (number > 0) {
			int digit = number % 10;
			sum += pow(digit, 2);
			number /= 10;
		}
		number = sum;
	} while (true);

	return number;
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	int number = 0;
	// Get a number for input file
	while (ifs >> number)
	{
		cout << isHappyNumber(number) << endl;
	}

	return 0;
}