#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> specialChar = { "-","_",".","~","!","@","#","$","%","^","&","*",
						"(",")","=","+","[","{","]","}",":","?",",","<",">","/" };
const vector<string> allowChar = { "-", "_", "." };

int maint(void) 
{
	string answer = "";
	string new_id = "...!@BaT# * ..y.abcdefghijklm";



	cout << answer;
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
	
}