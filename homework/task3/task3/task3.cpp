#include <iostream>
#include <cmath>
using namespace std;

class Vector{	
private:
	int x;
	int y;

	float getModule();
public:
	Vector();
	Vector(int xx, int yy);

	friend float operator* (Vector va, Vector vb);
	friend float operator+ (Vector va, Vector vb);
};

float Vector::getModule() {
	return sqrt(x*x + y*y);
}

Vector::Vector(int xx, int yy) {
	x = xx;
	y = yy;
}

float operator* (Vector va, Vector vb){
	return (va.x * vb.x + va.y * vb.y);
}

float operator+ (Vector va, Vector vb){
	return va * vb / vb.getModule();
}

int main()
{
	Vector a(4, 2);
	Vector b(-10, 0);

	float prAB = a + b;

	cout << "The projection of vector a on vector b = " << prAB<< endl;

	system("pause");
	return 0;
}


