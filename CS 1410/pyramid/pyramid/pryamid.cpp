#define HEIGHT 2
#include <iostream>
using namespace std;

int main()
{
	for (int level = 0; level < HEIGHT; level++)
	{
		for (int spaces = 0; spaces < HEIGHT - level - 1; spaces++)
			cout << ' ';
		for (int xes = 0; xes < 2 * level + 1; xes++)
			cout << 'X';
		cout << endl;
	}

	return 0;
}