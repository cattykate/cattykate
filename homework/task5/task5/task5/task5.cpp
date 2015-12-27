#include <iostream>

class Series {
public:
	Series() {};
	~Series() {};

	Series(int num) : n(num) {
		for (int i = 0; i < n; i++) {
			sum += i * i / 2.0;
		}
	}

	float getSum() { return sum; }

private:
	int n = 0;
	float sum = 0;
};

template < class T >
class KateList {
private:
	T* listPtr;
	int size;
public:
	KateList(int s) : size(s), listPtr(new T[s]) {
		for (int i = 0; i < size; i++) {
			listPtr[i] = T();
		}
	}

	//~KateList() { delete[] listPtr; }

	void addLast(T value) {
		size++;
		T* listPtrUpdated = new T[size];
		listPtrUpdated = listPtr;
		listPtrUpdated[size - 1] = value;
		listPtr = &(listPtrUpdated[0]);
	}

	void addFirst(T value) {
		size++;
		T* listPtrUpdated = new T[size];
		listPtrUpdated[0] = value;

		for (int i = 0; i < size - 1; i++) {
			listPtrUpdated[i + 1] = listPtr[i];
		}
		listPtr = &(listPtrUpdated[0]);
	}

	void deleteLast() {
		size--;
		T* listPtrUpdated = new T[size];
		for (int i = 0; i < size; i++) {
			listPtrUpdated[i] = listPtr[i];
		}
		listPtr = listPtrUpdated;
	}

	T& operator[] (int i) {
		return listPtr[i];
	}

	KateList operator+ (KateList plusItem) {
		KateList sum(plusItem.size + this->size);
		for (int i = 0; i < this->size; i++) {
			sum.listPtr[i] = this->listPtr[i];
			/* int b = this->listPtr[i].getSum();
			int a = 2;*/
		}
		for (int i = this->size; i < this->size + plusItem.size; i++) {
			sum.listPtr[i] = plusItem.listPtr[i - size];
		}
		return sum;
	}

	void sort() {
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (listPtr[i].getSum() > listPtr[j].getSum()) {
					Series temp = listPtr[i];
					listPtr[i] = listPtr[j];
					listPtr[j] = temp;
				}
			}
		}
	}

	int getSize() {
		return size;
	}
	/* ostream& operator<< (ostream& stream, KateList<T>& list) {
	for (int i = 0; i < size; i++) {
	stream << list[i].getSum();
	}
	return stream;
	}*/
};

int main(int narg, char** args)
{
	int s = 3;
	KateList<Series> obj(s);
	for (int i = 0; i < obj.getSize(); i++) {
		std::cout << obj[i].getSum() << std::endl;
	}
	std::cout << "--" << std::endl;

	obj.addLast(Series(4));
	for (int i = 0; i < obj.getSize(); i++) {
		std::cout << obj[i].getSum() << std::endl;
	}
	std::cout << "--" << std::endl;

	obj.addFirst(Series(3));
	for (int i = 0; i < obj.getSize(); i++) {
		std::cout << obj[i].getSum() << std::endl;
	}
	std::cout << "--" << std::endl;

	obj.deleteLast();
	for (int i = 0; i < obj.getSize(); i++) {
		std::cout << obj[i].getSum() << std::endl;
	}
	std::cout << "--" << std::endl;

	KateList<Series> obj2(2);
	obj2.addLast(Series(5));
	for (int i = 0; i < obj2.getSize(); i++) {
		std::cout << obj2[i].getSum() << std::endl;
	}
	std::cout << "--" << std::endl;

	KateList<Series> obj3(0);
	obj3 = obj + obj2;
	for (int i = 0; i < obj3.getSize(); i++) {
		std::cout << obj3[i].getSum() << std::endl;
	}
	std::cout << "--" << std::endl;

	obj3.sort();
	for (int i = 0; i < obj3.getSize(); i++) {
		std::cout << obj3[i].getSum() << std::endl;
	}
}