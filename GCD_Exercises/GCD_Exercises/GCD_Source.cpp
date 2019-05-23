/*	Examples of using GCD algorithms
	@date 05/23/2019.
	@author Nicolas Plata-Escobar.
*/
#include <iostream>
#include <string>
using namespace std;
int a = 618;
int b = 2530;
int GCD(int a, int b);
int main() {
	cout << "Brute Force finding GCD" << endl;
	for (int i = a; i > 0; i--) {
		if ((b/i) == ((float)b/(float)i) && (a/i) == ((float)a/(float)i)) {
			cout << "good = " << i << endl;
		}
	}

	cout << "Recursion finding GCD" << endl;
	cout << "good = " << GCD(a, b) << endl;

	string exit;
	getline(cin, exit);
	getline(cin, exit);
	return 0;
}

int GCD(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}