#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sequence = 0;
int combCount = 0;	// 중복 조합의 경우의 수
vector<int> arr;

long MaxCalculation(int result, int idx, int op, vector<int> ops) {
	if (ops[op] == 0) return LONG_MIN;

	vector<int> temp = ops;
	vector<long> tempResult(4);

	switch (op) {
	case 0:
		result = arr[idx] + arr[idx + 1];
		temp[0]--;
		break;
	case 1:
		result = arr[idx] - arr[idx + 1];
		temp[1]--;
		break;
	case 2:
		result = arr[idx] * arr[idx + 1];
		temp[2]--;
		break;
	case 3:
		result = arr[idx] / arr[idx + 1];
		temp[3]--;
		break;
	}

	for (int i = 0; i < 4; i++) {
		if (temp[i] == 0) {
			tempResult[i] = LONG_MIN;
		}
		else {
			tempResult[i] = MaxCalculation(result, idx + 1, temp[i], temp);
		}
	}

	return *(max_element(tempResult.begin(), tempResult.end()));
}

long MinCalculation(int result, int idx, int op, vector<int> ops) {
	if (ops[op] == 0) return LONG_MAX;

	vector<int> temp = ops;
	vector<long> tempResult(4);

	switch (op) {
	case 0:
		result = arr[idx] + arr[idx + 1];
		temp[0]--;
		break;
	case 1:
		result = arr[idx] - arr[idx + 1];
		temp[1]--;
		break;
	case 2:
		result = arr[idx] * arr[idx + 1];
		temp[2]--;
		break;
	case 3:
		result = arr[idx] / arr[idx + 1];
		temp[3]--;
		break;
	}

	for (int i = 0; i < 4; i++) {
		if (temp[i] == 0) {
			tempResult[i] = LONG_MAX;
		}
		else {
			tempResult[i] = MinCalculation(result, idx + 1, temp[i], temp);
		}
	}

	return *(min_element(tempResult.begin(), tempResult.end()));
}


int main() {

	cin >> sequence;
	arr.resize(sequence);	// 수열 벡터

	for (int i = 0; i < sequence; i++) {
		cin >> arr[i];
	}

	vector<int> operators(4, 0);	// 연산자 갯수 벡터
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	for (int i = 0; i < 4; i++) {
		int a = operators[i];
		while (a != 0) {
			combCount *= (4 - i);
			a--;
		}
	}

	vector<int> tempResult(4);
	for (int i = 0; i < 4; i++) {
		tempResult[i] = MaxCalculation(arr[0], 0, operators[i], operators);
	}

	cout << *max_element(tempResult.begin(), tempResult.end()) << '\n';

	for (int i = 0; i < 4; i++) {
		tempResult[i] = MinCalculation(arr[0], 0, operators[i], operators);
	}
	cout << *min_element(tempResult.begin(), tempResult.end());
}
