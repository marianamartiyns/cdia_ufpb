#include <iostream>

using std::cout;
using std::endl;

class number {
	int value;
public:
	number(int i): value(i) {}

	int get_value() { return value; }
	void set_value(int i) { value = i; }

	number* operator&() {
		return this;
	}
};

void print_number_info(number* n) {
	cout << "value: " << n->get_value() << endl;
	cout << "value address: " << n << endl;
}

int main(void) {
	number num(42);

	print_number_info(&num);

	cout << "&num = " << &num << endl;

	return 0;
}
