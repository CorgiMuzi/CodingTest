#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int> left, pair<int, int> right)
{
	return left.second < right.second;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;

	vector<int> failRate(stages.size());
	vector<int> reach(stages.size());
	vector<int> noClear(N);
	map<int, int> rate;

	for (int stage = 1; stage < N + 1; stage++)
	{
		for (int player = 0; player < stages.size(); player++)
		{
			if (stages.at(player) == stage)
			{
				noClear.at(stage-1)++;
			}
			if (stages.at(player) >= stage)
			{
				reach.at(stage - 1)++;
			}
		}
		if (reach.at(stage - 1) == 0)
		{
			failRate.at(stage - 1) = 0;
		}
		else
		{
			failRate.at(stage - 1) = noClear.at(stage - 1) / reach.at(stage - 1);
		}

		rate[stage] = failRate.at(stage-1);
	}

	vector<pair<int, int>> temp(rate.begin(), rate.end());

	sort(temp.begin(), temp.end(), cmp);

	for (int i = 1; i <= temp.size(); i++)
	{
		cout << temp.at(i).first;
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