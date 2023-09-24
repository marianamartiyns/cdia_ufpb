#include <iostream>

using std::cout;
using std::endl;

class temperatura {
	double celsius;
public:
	temperatura(double c):celsius(c) {}

	double get_celsius() { return celsius; }
	void set_celsius(double c) { celsius = c; }

	operator double() const {
		return ((celsius * 9.0 / 5.0) + 32.0);
	}
};

int main(void) {
	temperatura temp_c(28.0);

	double temp_f = temp_c;

	cout << "Temperatura Celsius: " << temp_c.get_celsius() << endl;
	cout << "Temperatura Farenheit: " << temp_f << endl;

	return 0;
}
