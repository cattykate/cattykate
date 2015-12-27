#include <iostream>
using namespace std;

class A1 {
public:
	A1(int aval) : a1(aval) {};
	virtual void print() {
		cout << "class A1: " << a1 << endl;
	}
	virtual void show() {
		cout << "a1 " << endl;
	}
protected :
	int a1;
};

class A2 {
public:
	A2(int aval) : a2(aval) {};
	virtual void print() {
		cout << "class A2: " << a2 << endl;
	}
protected:
	int a2;
};

class A3 {
public:
	A3(int aval) : a3(aval) {};
	virtual void print() {
		cout << "class A3: " << a3 << endl;
	}
protected:
	int a3;
};

int main() {
	A1 aobj;
	aobj.
}