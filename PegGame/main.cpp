#include <iostream>
#include "PegGame.h"

using namespace std;

int main() {
	int hole;

	cout << "Enter a value from 0-14 representing the open space: ";
	cin >> hole;

	PegGame game(hole);

	game.print();

	system("PAUSE");
	return 0;
}