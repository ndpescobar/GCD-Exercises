/*	Examples of using GCD algorithms. This program will ask for two integers from the user,
	and will find the Greatest Common Denominator between the user input.
	@version v1.4, 06/10/2019.
	@author Nicolas Plata-Escobar.
*/
#include <iostream>
#include <string>
using namespace std;

void BruteForceGCD(int a, int b);
int RecursionGCD(int a, int b, int countComparisons);

int main() {
	unsigned int a = 0;
	unsigned int b = 0;
	string stringA = "";
	string stringB = "";

	cout << "Welcome!" << endl;
	while (true) {
		cout << "Please enter a positive number (Enter 0 to quit): ";
		getline(cin, stringA);
		a = stoi(stringA);
		cout << "a = " << a << endl;
		cout << "Please enter an even larger positive number (Enter 0 to quit): ";
		getline(cin, stringB);
		b = stoi(stringB);
		cout << "b = " << b << endl;

		if (a == 0 && b == 0) {//if user enters 0 twice, then break while loop.
			break;
		}
		else if (b < a) {
			cout << "Invalid input: \"a\" must be smaller than \"b\"." << endl;
		}
		else if (a < 0 || b < 0) {
			cout << "Invalid input: numbers must be greater than zero." << endl;
		}
		else if (a >= 65535 || b >= 65535) {
			cout << "Invalid input: numbers cannot be bigger than \"65,535\"." << endl;
		}
		else {
			cout << "" << endl;
			cout << "Now we'll find the Greatest Common Denominator using two different methods:" << endl;

			// Brute Force Method
			cout << "Brute Force Mehtod:" << endl;
			BruteForceGCD(a, b);
			cout << "" << endl;

			// Recursion Method
			cout << "Recursion Mehtod:" << endl;
			cout << "GCD = " << RecursionGCD(a, b, 0) << endl;
			cout << "" << endl;
		}
		cout << "" << endl;
	}
	cout << "Double ENTER to end program." << endl;
	string exit;
	getline(cin, exit);
	getline(cin, exit);
	cout << "Goodbye!";
	return 0;
}

/* This function will find and output the GCD, using the "Brute Force" Mehtod, between the two aguments,
	and does not return anything.
*/
void BruteForceGCD(int a, int b) {
	int counter = 0;
	for (int i = a; i > 0; i--) {
		counter++;
		if ((b / i) == ((float)b / (float)i) && (a / i) == ((float)a / (float)i)) {
			counter++;
			cout << "Number of comparisons = " << counter << endl;
			cout << "GCD = " << i << endl;
			break; //finds GCD then breaks, or else other common denominators will be printed.
		}
	}
}

/* This function will find the GCD, using Euclid's Recursive Mehtod, between the two aguments,
	and does return an int, or calls itself. Third argument helps keep track of number of omparisons.
*/
int RecursionGCD(int a, int b, int countComparisons) {
	int counter = countComparisons;
	if (a == 0) {
		counter++;
		cout << "Number of comparisons = " << counter << endl;
		return b;
	}
	if (b == 0) {
		counter++;
		cout << "Number of comparisons = " << counter << endl;
		return a;
	}
	counter++;
	return RecursionGCD(b, a % b, counter);
}