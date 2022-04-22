#include <iostream>

using namespace std;

int Factorial(int);

int main() {
	int N;

	cin >> N;
	cout << Factorial(N);

	return 0;
}

int Factorial(int input) {
	if (input == 0) {
		return 1;
	}
	else {
		return input * Factorial(input - 1);
	}
	
}