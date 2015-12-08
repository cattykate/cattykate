#include <iostream>
#include <math.h>
using namespace std;

class Complex{
public:
	Complex(double re, double im);

	double real;
	double image;
	double argument;
	double module;

	void getArgument();
	void getModule();
};

Complex::Complex(double re, double im){
	real = re;
	image = im;

	void getArgument();
	void getModule();
}

void Complex::getArgument(){
	const double PI = 3.14159265;
	if (real > 0) argument = atan(image / real);
	else if (real < 0 && image > 0) argument = PI + atan(image / real);
	else if (real < 0 && image < 0) argument = (-PI) + atan(image / real);
}

void Complex::getModule(){
	module = sqrt(image*image + real*real);
}

int main() {

	Complex c(1, 1);
	int a = 2;

	system("pause");
	return 0;
}

