// data types
#include <iostream>

int main(){
	int x = 0;
	char ch = 0;
	float f = 0;

	x = 12;
	ch = 'A';
	f = 12.89F;

	ch = x;
	x = f;
	f = ch;
	f = x;

	std::cout << x << " " << ch << " " << f << std::endl;

	for (int i = 1; i <= 10; ++i) {
		std::cout << i << "/2 =  " << (float)i / 2 << "\n";
	}

	system("pause");
	return 0;
}