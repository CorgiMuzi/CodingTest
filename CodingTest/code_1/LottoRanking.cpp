#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	vector<int> lottos = { 0,0,0,0,0,0 };
	vector<int> win_nums = { 7,8,9,10,11,12 };

	vector<int> missing;
	int rank = 6;
	int correct = 0;
	int erased = 0;
	int maxRank, minRank;
	
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) {
			missing.push_back(lottos[i]);
		}
	}

	if (missing.size() >= 6) { erased = 5; }
	else { erased = missing.size(); }

	for (int i = 0; i < lottos.size(); i++) {
		for (int j = 0; j < win_nums.size(); j++) {
			if (lottos[i] == 0) { break; }
			else if (lottos[i] == win_nums[j]) {
				correct++;
				break;
			}
		}
	}
	
	if (correct >= 2) {
		rank -= (correct-1);
	}

	maxRank = rank - erased;
	minRank = rank;

	vector<int> answer = { maxRank, minRank };

	for (int i =0; i<answer.size(); i++) {
		cout << answer[i] << endl;
	}

}