#include <iostream>
#include <vector>
using namespace std;

class Series {
public:
	Series() {};
	~Series() {};

	Series(int num) : n(num) {
		for (int i = 0; i < n; i++){
			sum = sum + i * i / 2.0;
		}
	}
	float getSum() { return sum; }

private:
	int n = 0;
	float sum = 0;
};

template <class T>
class KateList {
private:
	vector<T> listPtr;
public:
	KateList(int s) : listPtr(s) { };

	~KateList() { listPtr.clear(); }

	void addLast(T value) { listPtr.push_back(value); }

	void addFirst(T value) {
		listPtr.insert(listPtr.begin(), value);
	}

	void deleteLast() { listPtr.pop_back(); }

	T& operator[] (int i) {
		return listPtr[i];
	}

	KateList operator+ (KateList plusItem) {

		KateList sum(plusItem.getSize() + this->getSize());

		for (int i = 0; i < this->getSize(); i++) {
			sum.listPtr[i] = this->listPtr[i];
		}

		for (int i = this->getSize(); i < this->getSize() + plusItem.getSize(); i++) {
			sum.listPtr[i] = plusItem.listPtr[i - getSize()];
		}
		return sum;
	}

	int getSize() {
		return listPtr.size();
	}
};

int main()
{
	int s = 5;
	KateList<Series> obj(s);
	for (int i = 0; i < obj.getSize(); i++) {
		cout << obj[i].getSum() << endl;
	}
	cout << "--" << endl;

	obj.addLast(Series(4));
	for (int i = 0; i < obj.getSize(); i++) {
		cout << obj[i].getSum() << endl;
	}
	cout << "--" << endl;

	obj.addFirst(Series(3));
	for (int i = 0; i < obj.getSize(); i++) {
		cout << obj[i].getSum() << endl;
	}
	cout << "--" << endl;

	obj.deleteLast();
	for (int i = 0; i < obj.getSize(); i++) {
		cout << obj[i].getSum() << endl;
	}
	cout << "--" << endl;

	KateList<Series> obj2(3);
	obj2.addLast(Series(4));
	for (int i = 0; i < obj2.getSize(); i++) {
		cout << obj2[i].getSum() << endl;
	}
	cout << "--" << endl;

	KateList<Series> obj3(0);
	obj3 = obj + obj2;
	for (int i = 0; i < obj3.getSize(); i++) {
		cout << obj3[i].getSum() << endl;
	}
	cout << "--" << endl;

	return 0;
}