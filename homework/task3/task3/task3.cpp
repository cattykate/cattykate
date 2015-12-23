#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n = 0;

class Vector{	
public:
	Vector(int n);
	
	vector<int> vec;

	float getModule();

	friend float operator* (Vector va, Vector vb);
	friend float operator+ (Vector va, Vector vb);
};

float Vector::getModule() {
	float mod = 0.0;
	for (int i = 0; i < vec.size(); i++){
		mod = mod + vec[i] * vec[i];
	}
	return sqrt(mod);
}

Vector::Vector(int n) {  
	for (int i = 0; i < n; i++)
	{
		vec.push_back(0);
	}
}

float operator* (Vector va, Vector vb){
	float scal = 0.0;
	for (int i = 0; i < n; i++)
	{
		scal = scal + va.vec[i] * vb.vec[i];
	}
	return scal;
}

float operator+ (Vector va, Vector vb){
	return va * vb / vb.getModule();
}

int main()
{
	Vector va(100); 
	Vector vb(100);

	cout << "Enter the size of vectors: ";
	cin >> n;

	cout << "Enter the vector a: ";
	for (int i = 0; i < n; i++){
		cin >> va.vec[i];
	}

	cout << "Enter the vector b: ";
	for (int i = 0; i < n; i++){
		cin >> vb.vec[i];
	}

	float prAB = va + vb;

	cout << "The projection of vector a on vector b = " << prAB<< endl;

	system("pause");
	return 0;
}


