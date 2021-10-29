#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool CheckIdRules(string);
string Level2(string);
string Level3(string);
string Level4(string);
string Level5(string);
string Level6(string);
string ToLower(string);

vector<char> specialChar = { '-','_','.','~','!','@','#','$','%','^' ,',','&','*',
						'(',')','=','+','[','{',']','}',':','?',',','<','>','/' };
vector<char> allowChar = { '-', '_', '.' };

int main() {
	string answer = "";
	string new_id = "abcdefghijklmn.p";
	if (CheckIdRules(new_id)) {
		answer = new_id;
		//return answer;
		cout << answer;
	}

	new_id = ToLower(new_id);
	new_id = Level2(new_id);
	new_id = Level3(new_id);
	new_id = Level4(new_id);
	new_id = Level5(new_id);
	new_id = Level6(new_id);

	answer = new_id;

	//return answer;
	cout << answer;
}

string ToLower(string id) {
	for (int i = 0; i < id.size(); i++) {
		if (isalpha(id[i]) && id[i] >= 'A' && id[i] <= 'Z') {
			id[i] = id[i] - 'A' + 'a';
		}
	}

	return id;
}

bool CheckIdRules(string id) {
	if (id.size() < 3 || id.size() > 15) {
		return false;
	}
	for (int i = 0; i < specialChar.size(); i++) {
		if (find(allowChar.begin(), allowChar.end(), specialChar[i]) == allowChar.end()) {
			return false;
		}
	}
	if (id[0] == allowChar[2] || id[id.size() - 1] == allowChar[2]) {
		return false;
	}
	return true;
}

string Level2(string id) {
	vector<int> eraseIndex;
	for (int i = 0; i < id.size(); i++) {
		if (!isalpha(id[i]) && !isdigit(id[i]) && find(allowChar.begin(), allowChar.end(), id[i]) == allowChar.end()) {
			eraseIndex.push_back(i);
		}
	}
	for (int i = 0; i < eraseIndex.size(); i++) {
		id.erase(find(id.begin(), id.end(), id.at(eraseIndex[i] - i)));
	}

	return id;
}

string Level3(string id) {
	char preChar = id[0];
	int eraseIndex = 0;
	for (int i = 0; i < id.size() - eraseIndex; i++) {
	
		if (preChar == id.at(i) && preChar == allowChar[2]) {
			id.erase(i, 1);
			eraseIndex++;
		}
		if (id.size() <= 0 || i >= id.size()) return id;
			preChar = id.at(i);

	}

	return id;
}

string Level4(string id) {
	if (id.size() <= 0) { return id; }
	if (id[0] == allowChar[2]) {
		id.erase(0, 1);
	}
	if (id[id.size() - 1] == allowChar[2]) {
		id.erase(id.size() - 1, 1);
	}

	return id;
}

string Level5(string id) {
	if (id.empty()) {
		id.append(1, 'a');
	}

	return id;
}

string Level6(string id) {
	if (id.size() >= 16) {
		id.erase(15);
	}
	else if (id.size() <= 2) {
		int repeat = 3 - id.size();
		id.append(repeat, id[id.size() - 1]);
	}

	id = Level4(id);

	return id;
}