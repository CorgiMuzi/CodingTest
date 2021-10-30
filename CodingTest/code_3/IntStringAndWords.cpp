#include <iostream>
#include <string>
#include <map>

using namespace std;

int solution(string);

int main() {
	string example = "one4seveneight";
	solution(example);
	return 0;
}

int solution(string s) {
	int answer = 0;
	string answer_str = "";
	map<string, char> dict = { {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'},
		{"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'} };
	
	string::iterator iter;
	int idx;

	for (iter = s.begin(); iter != s.end(); iter++) {
		if (isdigit(*iter)) {
			answer_str += *iter;
			continue;
		}

		idx = 3;
		do {
			if (isdigit(dict[string(iter,iter+idx)])) {
				answer_str += dict[string(iter, iter + idx)];
				iter = std::next(iter, idx-1);
				idx = 0;
			}
			else {
				idx++;
			}
		} while (idx != 0);
	}

	answer = stoi(answer_str);

	return answer;
}