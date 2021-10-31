#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<int>, string);

int main()
{
	vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	string hand = "right";

	solution(numbers, hand);

	return 0;
}

struct Coordinate
{
private:
	int x;
	int y;
public:
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	Coordinate(int _x, int _y):x(_x), y(_y) {	}
	Coordinate():x(0), y(0) {}
};


// +---+---+---+
// | 1 | 2 | 3 |
// +---+---+---+
// | 4 | 5 | 6 |
// +---+---+---+	=> Adjust to Cartesian coordinate system
// | 7 | 8 | 9 |
// +---+---+---+
// | * | 0 | # |
// +---+---+---+

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	map<int, Coordinate> keypads;
	Coordinate leftHand(0, 3);	// *에 왼손 위치
	Coordinate rightHand(2, 3);	// #에 오른손 위치

	keypads[0] = Coordinate(1,3);

	string movingHands ="";
	
	int x = 0;
	int y = 0;

	for (int i = 1; i < 10; i++)
	{
		keypads[i] = Coordinate(x, y);

		x++;
		if (x > 2)
		{
			x -= 3;
			y += 1;
		}
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		if (keypads[numbers[i]].getX() == 0) { 
			movingHands += 'L';
			leftHand.setX(keypads[numbers[i]].getX());
			leftHand.setY(keypads[numbers[i]].getY());
			continue;
		}
		else if (keypads[numbers[i]].getX() == 2)
		{
			movingHands += 'R';
			rightHand.setX(keypads[numbers[i]].getX());
			rightHand.setY(keypads[numbers[i]].getY());
			continue;
		}
		else
		{
			int lHandXDiff = abs(keypads[numbers[i]].getX() - leftHand.getX());
			int lHandYDiff = abs(keypads[numbers[i]].getY() - leftHand.getY());
			int lHandMove = lHandXDiff + lHandYDiff;

			int rHandXDiff = abs(keypads[numbers[i]].getX() - rightHand.getX());
			int rHandYDiff = abs(keypads[numbers[i]].getY() - rightHand.getY());
			int rHandMove = rHandXDiff + rHandYDiff;

			if (lHandMove == rHandMove)
			{
				movingHands += (hand == "left" ? "L" : "R");
			}
			else
			{
				movingHands += (lHandMove > rHandMove ? "R" : "L");
			}
		}

		if (movingHands[movingHands.size() - 1] == 'L')
		{
			leftHand.setX(keypads[numbers[i]].getX());
			leftHand.setY(keypads[numbers[i]].getY());
		}
		else if (movingHands[movingHands.size() - 1] == 'R')
		{
			rightHand.setX(keypads[numbers[i]].getX());
			rightHand.setY(keypads[numbers[i]].getY());
		}
	}

	cout << movingHands;

	return answer;
}