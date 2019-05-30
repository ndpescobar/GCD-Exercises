/*	Examples of using GCD algorithms
	@version v1.3, 05/28/2019.
	@author Nicolas Plata-Escobar.
*/
#include <iostream>
#include <string>
using namespace std;

void BruteForceGCD(int a, int b);
int RecursionGCD(int a, int b);

int main() {
	int a = 0;
	int b = 0;
	string stringA = "";
	string stringB = "";

	cout << "Welcome!" << endl;
	while (true) {
		cout << "Please enter a positive number (Enter -99 to quit): ";
		getline(cin, stringA);
		a = stoi(stringA);
		cout << "a = " << a << endl;
		cout << "Please enter an even larger positive number (Enter -99 to quit): ";
		getline(cin, stringB);
		b = stoi(stringB);
		cout << "b = " << b << endl;
		if (a == -99 && b == -99) {
			break;
		}
		else if (a <= 0 || b <= 0) {
			cout << "Invalid input: numbers must be greater than zero." << endl;
		}
		/*else if (a >= b) {
			cout << "Invalid Input: first number is larger than second." << endl;
			cout << "SWITCHING NUMBERS..." << endl;
			int temp = a;
			a = b;
			b = temp;
			cout << "Now we'll find the Greatest Common Denominator using two different methods." << endl;
			// Brute Force Method
			cout << "Brute Force finding GCD" << endl;
			BruteForceGCD(a, b);
			// Recursion Method
			cout << "Recursion finding GCD" << endl;
			cout << "good = " << RecursionGCD(a, b) << endl;
		}*/
		else /*if (a < b)*/ {
		    cout << "Now we'll find the Greatest Common Denominator using two different methods." << endl;
			// Brute Force Method
			cout << "Brute Force Mehtod" << endl;
			BruteForceGCD(a, b);
			// Recursion Method
			cout << "Recursion Mehtod" << endl;
			cout << "good = " << RecursionGCD(a, b) << endl;
		}
	}
    cout << "Double ENTER to end program." << endl;
	string exit;
	getline(cin, exit);
	getline(cin, exit);
	return 0;
}

void BruteForceGCD(int a, int b) {
	for (int i = a; i > 0; i--) {
		if ((b / i) == ((float)b / (float)i) && (a / i) == ((float)a / (float)i)) {
			cout << "good = " << i << endl;
		}
		//cout << "i = " << i << endl;
	}
}

int RecursionGCD(int a, int b) {
	//cout << "a = " << a << " b = " << b << endl;
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return RecursionGCD(b, a % b);
}