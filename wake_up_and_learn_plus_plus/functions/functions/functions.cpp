#include <iostream>

void mySwap(int *x, int *y) {
	int tmp = 0;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void SwapWithLink(int &x, int &y){
	int tmp = 0;

	tmp = x;
	x = y;
	y = tmp;
}

void modification(int &val) {
	val = 16; // value 
}


int main() {

	int a = 12;
	int b = 3;

	mySwap(&a, &b);

	modification(a);

	SwapWithLink(a, b);


	return 0;
}