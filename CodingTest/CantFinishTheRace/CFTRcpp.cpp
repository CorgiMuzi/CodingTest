#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	vector<string> res(1); 
	vector<string>::iterator iter; 
	sort(participant.begin(), participant.end()); sort(completion.begin(), completion.end());
	iter = set_difference(participant.begin(), participant.end(), 
		completion.begin(), completion.end(), res.begin()); 
	answer = res[0];
	cout << answer;
	return answer;
}

int main()
{
	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };

	solution(participant, completion);
}