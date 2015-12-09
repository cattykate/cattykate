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
};

Complex::Complex(double im, double re){
	image = im;
	real = re;

	getArgument();
	getModule();
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

ostream &operator<<(ostream &stream, Complex &obj){
	stream << "|z| = " << setprecision(5) << obj.module << endl;
	stream << "cos(Phi) = " << setprecision(5) << cos(obj.argument) << endl;
	stream << "sin(Phi) = " << setprecision(5) << sin(obj.argument) << endl << endl;
	return stream;
}

ofstream &operator<<(ofstream &stream, Complex &obj){
	stream << "|z| = " << setprecision(5) << obj.module << endl;
	stream << "cos(Phi) = " << setprecision(5) << cos(obj.argument) << endl;
	stream << "sin(Phi) = " << setprecision(5) << sin(obj.argument) << endl << endl;
	return stream;
}

istream &operator>>(istream &stream, Complex &obj){
	stream >> obj.image >> obj.real;
	return stream;
}

int main() {
	Complex c(1.0, 1.0);
	cout << c;

	Complex a;
	cin >> a;
	
	ofstream out("Complex.txt");
	if (!out) cout << "Can't open the file!";
	out << c;
	out.close();

	system("pause");
	return 0;
}

