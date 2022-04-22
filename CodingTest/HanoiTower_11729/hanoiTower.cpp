#include <iostream>
#include <cmath>

using namespace std;

void HanoiTower(int input, int from, int sub, int to) {
	if (input == 1) {
		cout << from << " "<< to << '\n';
	}
	else {
		HanoiTower(input - 1, from, to, sub);
		cout << from << " " << to << '\n';
		HanoiTower(input - 1, sub, from, to);
	}
	
	return ;
}

int main() {
	int N;
	cin >> N;
	int tryCnt = pow(2, N) - 1;
	cout << tryCnt << '\n';
	HanoiTower(N,1, 2, 3);

	return 0;
}