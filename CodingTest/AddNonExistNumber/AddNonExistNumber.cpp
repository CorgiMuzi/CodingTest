#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers);

int main(void)
{
	vector<int> numbers = { 5,8,4,0,6,7,9 };

	solution(numbers);

	return 0;
}

int solution(vector<int> numbers)
{
	int answer = -1;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		if (find(numbers.begin(), numbers.end(), i) == numbers.end())
		{
			sum += i;
		}
	}

	answer = sum;

	return answer;
}