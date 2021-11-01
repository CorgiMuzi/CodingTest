#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>>, vector<int>);

int main(void) {

	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = {1,5,3,5,1,2,1,4};
	solution(board, moves);

	return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> bucket;
	int lastDoll = 0;
	int destroied =0;

	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i]-1] != 0) {
				if (lastDoll == board[j][moves[i]-1]) { 
					bucket.pop_back(); 
					lastDoll = bucket[bucket.size()-1];
					destroied += 2;
					board[j][moves[i]-1] = 0;
					break;
				}
				bucket.push_back(board[j][moves[i]-1]);
				lastDoll = board[j][moves[i]-1];
				board[j][moves[i]-1] = 0;
				break;
			}
		}
	}

	answer = destroied;
	cout << answer;

	return answer;
}