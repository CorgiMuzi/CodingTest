#include <iostream>
using namespace std;

int Fibonacci(int N) {
	if (N == 0) {
		return 0;
	}
	else if (N == 1) {
		return 1;
	}
	else {
		return Fibonacci(N - 1) + Fibonacci(N - 2);
	}

}

int main() {
	int N;
	cin >> N;
	cout << Fibonacci(N);

	return 0;
}

