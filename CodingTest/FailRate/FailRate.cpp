#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;

	vector<int> failRate(stages.size());
	vector<int> noClear(stages.size());
	vector<int> reach(stages.size());

	for (int player = 0; player < stages.size(); player++)
	{
		for (int stage = 1; stage < N + 1; stage++){
			if (stages.at(player) == stage)
			{
				noClear.at(player)++;
			}
			if (stages.at(player) >= stage)
			{
				reach.at(player)++;
			}
		}
	}

	return answer;
}

int main()
{
	int N = 4;
	vector<int> stages = { 4,4,4,4,4 };

	solution(N, stages);

	return 0;
}