// this
#include <iostream>
using namespace std;

class Test {
	int i;
public:
	void load_i(int val) {
		this->i = val;
	}
	int get_i() {
		return this->i;
	}
};

int main() {
	
	Test obj;
	obj.load_i(100);
	cout << obj.get_i();

	return 0;
}