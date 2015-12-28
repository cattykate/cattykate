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
	virtual void show() {
		cout << "a2" << endl;
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
	virtual void show() {
		cout << "a3" << endl;
	}
protected:
	int a3;
};

class B1 : public A1, A2, A3 {
public:
	B1(int bval, int a1val, int a2val, int a3val) : b1(bval), A1(a1val), A2(a2val), A3(a3val) {};
	virtual void print() {
		cout << "class B1: " << b1 << endl;
	}
	virtual void show() {
		cout << "b1, a1, a2, a3 " << endl;
	}
protected:
	int b1;
};

class B2 : public A1, A2, A3 {
public:
	B2(int bval, int a1val, int a2val, int a3val) : b2(bval), A1(a1val), A2(a2val), A3(a3val) {};
	virtual void print() {
		cout << "class B2: " << b2 << endl;
	}
	virtual void show(){
		cout << "b2, a1, a2, a3 " << endl;
	}
protected:
	int b2;
};

class B3 : public A1, A2, A3 { 
public:
	B3(int bval, int a1val, int a2val, int a3val) : b3(bval), A1(a1val), A2(a2val), A3(a3val) {};
	virtual void print() {
		cout << "class B2: " << b3 << endl;
	}
	virtual void show(){
		cout << "b3, a1, a2, a3 " << endl;
	}
protected:
	int b3;
};


int main() {

}