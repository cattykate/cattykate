#include <iostream>
using namespace std;

int main() {
	 
	bool isprime;

	for (int i = 1; i <= 100; i++) {
		isprime = true;
		for (int j = 2; j <= i / 2; j++) {
			if (i%j == 0) isprime = false;
		}
		if (isprime)
			cout << i << "prime.\n";
	}
	system("pause");
	return 0;
}