#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Vector{
public:
    Vector(int n);
 
    int* vec;
    int size;

    float getModule();

    friend float operator* (Vector va, Vector vb);
    friend float operator+ (Vector va, Vector vb);
};

float Vector::getModule() {
    float mod = 0.0;
    for (int i = 0; i < size; i++){
        mod = mod + vec[i] * vec[i];
    }
    return sqrt(mod);
}

Vector::Vector(int n) {

    size = n;
    vec = new int[n];

    for (int i = 0; i < n; i++)
    {
        vec[i] = 0;
    }
}

float operator* (Vector va, Vector vb){
    float scal = 0.0;
    for (int i = 0; i < va.size; i++)
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
    Vector va(4);
    Vector vb(4);

    va.vec[0] = 1;
    va.vec[1] = 1;
    va.vec[2] = 1;
	va.vec[3] = 1;

    vb.vec[0] = 1;
    vb.vec[1] = 1;
    vb.vec[2] = 1;
	vb.vec[3] = 1;

    float prAB = va + vb;

    cout << "The projection of vector a on vector b = " << prAB << endl;

	return 0;
}


