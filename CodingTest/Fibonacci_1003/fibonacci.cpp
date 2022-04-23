#include <iostream>
using namespace std;

struct Data {
	int number;
	int zero;
	int one;

	Data() {
		number = -1;
		zero = 0;
		one = 0;
	}

	Data(int _number, int _zero, int _one) {
		number = _number;
		zero = _zero;
		one = _one;
	}
};

int dataFrame[2];
Data fiboData[41];

Data fibonacci(int n) {
	if (n == 0) {
		dataFrame[0] ++;
		if (fiboData[0].number == -1) {
			fiboData[0] = { 0, 1, 0 };
		}
	}
	else if (n==1){
		dataFrame[1] ++;
		if (fiboData[1].number == -1) {
			fiboData[1] = { 1, 0, 1 };
		}
	}
	else {
		if (fiboData[n].number == -1) {
			fiboData[n] = { n, fibonacci(n - 1).zero + fibonacci(n - 2).zero, fibonacci(n - 1).one + fibonacci(n - 2).one };
		}
	}

	return fiboData[n];
}

int main() {

	int count;
	cin >> count;


	for (int i = 0; i < count; i++) {
		int n =0;
		cin >> n;
		dataFrame[0] = 0;
		dataFrame[1] = 0;
		Data temp = fibonacci(n);

		cout << temp.zero << " " << temp.one << '\n';
	}
	
}