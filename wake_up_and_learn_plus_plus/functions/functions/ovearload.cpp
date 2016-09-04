// Ovearload of functions

#include <iostream>

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else return b;
}

// This version of function ignores register of letters. uppercase  lowercase
char min(char a, char b) { 
	if (tolower(a) < tolower(b)) { 
		return a;
	}
	else return b;
}

/*function min() is for pointers to type int
this function compares values and returns pointer to minimal value
*/
int *min(int *a, int *b) {
	if (*a < *b) {
		return a;
	}
	else return b;
}

int main() {
	int i = 10;
	int j = 22;

	std::cout << "min ('X', 'a'): " << min('X', 'a') << std::endl;
	std::cout << "min(9, 3): " << min(9, 3) << std::endl;
	std::cout << "*min(&i, &j): " << *min(&i, &j) << std::endl;

	return 0;
}