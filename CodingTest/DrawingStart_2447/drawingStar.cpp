#include <iostream>
using namespace std;

char** DrawingStar(int x, int y, int input, char** arr) {
	if (input == 3) {
		arr[x][y] = ' ';
	}
	else {
		for (int i = 0; i <= input / 6; i++) {
			for (int j = 0; j <= input / 6; j++) {
				arr[x - i][y - j] = ' ';
				arr[x - i][y + j] = ' ';
				arr[x + i][y + j] = ' ';
				arr[x + i][y - j] = ' ';
			}
		}

		input = input / 3;

		DrawingStar(x - input , y - input , input, arr);
		DrawingStar(x - input , y + input , input, arr);
		DrawingStar(x + input , y - input , input, arr);
		DrawingStar(x + input , y + input , input, arr);
		DrawingStar(x, y + input , input, arr);
		DrawingStar(x, y - input , input, arr);
		DrawingStar(x + input , y, input, arr);
		DrawingStar(x - input , y, input, arr);
	}
	return arr;
}

int main() {
	int N =3;
	cin >> N;
	char** starArr = new char* [N];
	for (int i = 0; i < N; i++) {
		starArr[i] = new char[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			starArr[i][j] = '*';
		}
	}

	starArr = DrawingStar(N/2, N/2, N, &*starArr);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << starArr[i][j];
		}
		cout << endl;
	}
	return 0;
}