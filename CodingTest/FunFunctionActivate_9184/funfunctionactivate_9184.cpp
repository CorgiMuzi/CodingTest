#include <iostream>
using namespace std;

int dataFrame[22][22][22];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		a = b = c = 0;
		if (dataFrame[a][b][c] == NULL) {
			dataFrame[0][0][0] = 1;
		}
	}
	else if (a > 20 || b > 20 || c > 20) {
		a = b = c = 21;
		if (dataFrame[a][b][c] == NULL) {
			dataFrame[a][b][c] = w(20, 20, 20);
		}
	}
	else if (a < b && b < c) {
		if (dataFrame[a][b][c] == NULL) {
			dataFrame[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		}
	}
	else {
		if (dataFrame[a][b][c] == NULL) {
			dataFrame[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		}
	}

	return dataFrame[a][b][c];
}

int main() {
	while (true) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}

	return 0;
}