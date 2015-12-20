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
	out << setprecision(5);
	return out;
}

ostream &operator<<(ostream &out, Complex &obj){
	out << "|z| = " << obj.module << myManipulator << endl;
	out << "cos(Phi) = " << cos(obj.argument) << myManipulator << endl;
	out << "sin(Phi) = " << sin(obj.argument) << myManipulator << endl << endl;
	return out;
}

ofstream &operator<<(ofstream &out, Complex &obj){
	out << "|z| = " << obj.module << myManipulator <<endl;
	out << "cos(Phi) = " << cos(obj.argument) << myManipulator << endl;
	out << "sin(Phi) = " << sin(obj.argument) << myManipulator << endl << endl;
	return out;
}

istream &operator>>(istream &in, Complex &obj){
	cout << "Ener image and real part \t";
	in >> obj.image >> obj.real;
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

bool Complex::operator> (Complex c)
{
	if (module > c.module) return true;
	if (module == c.module) {
		if (real > c.real) return true;
		else return false;
	}
	if (module < c.module) return false;
}

int main() {
	Complex c(3.0, 1.0);
	cout << c;

	ofstream out("Complex.txt");
	if (!out) cout << "Can't open the file!";
	out << c;
	out.close();

	Complex a(0.0, 0.0);
	cin >> a;
	a.getArgument();
	a.getModule();
	cout << a;

	if (a < c) cout << "a < c";



	system("pause");
	return 0;
}