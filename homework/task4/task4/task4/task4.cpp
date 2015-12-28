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
	B1(int b1val, int a1val, int a2val, int a3val) : b1(b1val), A1(a1val), A2(a2val), A3(a3val) {};
	virtual void print() {
		cout << "class B1: " << b1 << endl;
	}
	virtual void show()  override {
		cout << "b1, a1, a2, a3 " << endl;
	}
protected:
	int b1;
};

class B2 : public A1, A2, A3 {
public:
	B2(int b2val, int a1val, int a2val, int a3val) : b2(b2val), A1(a1val), A2(a2val), A3(a3val) {};
	virtual void print() {
		cout << "class B2: " << b2 << endl;
	}
	virtual void show() override {
		cout << "b2, a1, a2, a3 " << endl;
	}
protected:
	int b2;
};

class B3 : public A1, A2, A3 { 
public:
	B3(int b3val, int a1val, int a2val, int a3val) : b3(b3val), A1(a1val), A2(a2val), A3(a3val) {};
	virtual void print() {
		cout << "class B3: " << b3 << endl;
	}
	virtual void show()  override {
		cout << "b3, a1, a2, a3 " << endl;
	}
protected:
	int b3;
};

class C1 : public B1, B2, B3 {
public:
	C1(int cval, int a1val, int a2val, int a3val, int b1val, int b2val, int b3val) : c1(cval), B1(b1val, a1val, a2val, a3val), B2(b2val, a1val, a2val, a3val), B3(b3val, a1val, a2val, a3val) {};
	void print() {
		cout << "class C1: " << c1 << endl;
	}
	void show() override {
		cout << "c1, b1, b2, b3" << endl;
	}
protected:
	int c1;
};

int main() {
	C1 c1obj(3, 1, 1, 1, 1, 1, 1);
	c1obj.print();
	c1obj.show();

	B1 b1obj = B1(2, 2, 2, 2);
	b1obj.print();
	b1obj.show();

	A1 a1obj = A1(1);
	a1obj.print();
	a1obj.show();

	return 0;
}