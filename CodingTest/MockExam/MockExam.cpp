#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int AnswerSheet(vector<int> person, vector<int> answers);

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<int> Person1 = { 1, 2, 3, 4, 5 };
	vector<int> Person2 = { 2, 1, 2, 3, 2, 4,2, 5 };
	vector<int> Person3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	vector<int> answerSheet;
	answerSheet.push_back(AnswerSheet(Person1, answers));
	answerSheet.push_back(AnswerSheet(Person2, answers));
	answerSheet.push_back(AnswerSheet(Person3, answers));
	
	int max = *max_element(answerSheet.begin(), answerSheet.end());

	for (int i = 0; i < answerSheet.size(); i++) {
		if (answerSheet.at(i) == max) {
			answer.push_back(i+1);
		}
	}

	return answer;
}

int AnswerSheet(vector<int> person, vector<int> answers) {
	int correctRate = 0;
	int index = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (person.at(i%person.size()) == answers.at(i)) {
			correctRate++;
		}
	}
	return correctRate;
}

int main() {
	vector<int> answers = {1,2,3,4,5};
	solution(answers);
}