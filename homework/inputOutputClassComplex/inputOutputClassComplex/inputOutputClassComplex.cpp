#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

class Complex{
public:
	Complex();
	Complex(double im, double re);
	double image;
	double real;
	double argument;
	double module;

	void getArgument();
	void getModule();

	bool operator< (Complex c);
	bool operator> (Complex c);
};

Complex::Complex(double im, double re){
	image = im;
	real = re;

	getArgument();
	getModule();
}

Complex::Complex(){}

void Complex::getArgument(){
	const double PI = 3.14159265;
	if (real > 0) argument = atan(image / real);
	else if (real < 0 && image > 0) argument = PI + atan(image / real);
	else if (real < 0 && image < 0) argument = (-PI) + atan(image / real);
}

void Complex::getModule(){
	module = sqrt(image*image + real*real);
}

ostream &myManipulator(ostream &out){
	 out << scientific << setprecision(5);
	return out;
}

ostream &operator<<(ostream &out, Complex &c){
	out << "|z| = " << myManipulator <<  c.module  << endl;
	out << "cos(Phi) = " << myManipulator << cos(c.argument)  << endl;
	out << "sin(Phi) = " << myManipulator << sin(c.argument)  << endl << endl;
	return out;
}

ofstream &operator<<(ofstream &out, Complex &c){
	out << "|z| = " << c.module << myManipulator <<endl;
	out << "cos(Phi) = " << cos(c.argument) << myManipulator << endl;
	out << "sin(Phi) = " << sin(c.argument) << myManipulator << endl << endl;
	return out;
}

istream &operator>>(istream &in, Complex &c){
	in >> c.image >> c.real;
	return in;
}

bool Complex::operator< (Complex c)
{
	if (module < c.module) return true;
	if (module == c.module) {
		if (real < c.real) return true;
		else return false;
	}
	if (module > c.module) return false;
}

bool Complex::operator>(Complex c)
{
	if (module > c.module) return true;
	if (module == c.module) {
		if (real > c.real) return true;
		else return false;
	}
	if (module < c.module) return false;
}

int main() {
	Complex c(1.0, 1.0);
	cout << "Complex c(1.0, 1.0)\n\n";
	cout << c;

	ofstream out("Complex.txt");
	if (!out) cout << "Can't open the file!";
	out << c;
	out.close();

	Complex a(0.0, 0.0);
	cout << "Enter the image and real parts of arbitrary complex number\t";
	cin >> a;
	a.getModule();
	a.getArgument();

	cout << "Result of comparison: \n";
	if (a < c) cout << "Your number < c \n";
	else if (a > c) cout << "Your number  > c \n";
	else cout << "Your number = c \n";

	system("pause");
	return 0;
}