#include <iostream>
using namespace std;

#define WHEN_SIZE 6
#define WHAT_SIZE 2

template <typename T>
int first_index_of(T* when, T* what, int index) {

	for (int i = index; i < WHEN_SIZE; i++) {

		bool match = true;
		for (int j = 0; j < WHAT_SIZE; j++) {

			if (j + i < WHEN_SIZE) {
				if (what[j] != when[j + i]) {
					match = false;
				}
			}

			if (!match) goto label;
		}

		if (match) return i;

	label:;
	}

	return -1;
}

int main()
{

	char when[WHEN_SIZE] = { 'a', 'b', 'c', 'd', 'g', 'h' };
	char what[WHAT_SIZE] = { 'd', 'g' };
	int ind = first_index_of(when, what, 2);

	return 0;
}

