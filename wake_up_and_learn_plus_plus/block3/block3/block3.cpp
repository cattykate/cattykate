#include <iostream>
using namespace std;

int main() {
	int num = 0;

	cout << "Enter the number from 1 to 3: ";
	cin >> num;
	
	switch (num) {
	case 1:
		cout << "\nA bad beginning makes a bad ending\n";
		break;
	case 2:
		cout << "A bird in the hand is worth two in the bush\n";
		break;
	case 3:
		cout << "A cat in gloves catches no mice\n";
		break;
	default:
		cout << "You can enter only 1, 2, 3\n";
	}
	system("pause");
	return 0;
	
}