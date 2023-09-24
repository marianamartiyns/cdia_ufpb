#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class ponto {
	double x;
	double y;
public:
	ponto(double xx, double yy): x(xx), y(yy) {}
	double get_x() { return x; }
	void set_x(double xx) { x = xx; }
	double get_y() { return y; }
	void set_y(double yy) { y = yy; }
	void print_info() {
		cout << "ponto(" << x << ", " << y << ")" << endl;
	}
	ponto operator+(const ponto& outro) {
		double xr = x + outro.x;
		double yr = y + outro.y;
		return ponto(xr, yr);
	}
	ponto operator-(const ponto& outro) {
		double xr = x - outro.x;
		double yr = y - outro.y;
		return ponto(xr, yr);
	}
	bool operator==(const ponto& outro) {
		return ((x == outro.x) && (y == outro.y));
	}
	bool operator!=(const ponto& outro) {
		return ((x != outro.x) || (y != outro.y));
	}
	friend ostream& operator<<(ostream& os, const ponto& p) {
		os << "x: " << p.x << ", y: " << p.y << " ";
		return os;
	}

};

int main(void) {
	ponto a(10,20), b(20,30), c(40,50), d(50, 60);
	ponto k(10, 11);

        cout << "ponto a: ";
        a.print_info();
        cout << "ponto b: ";
        b.print_info();
        cout << "ponto c: ";
        c.print_info();
	cout << "ponto d: ";
	d.print_info();

	ponto e = a + b;
	//ponto e = a.operator+(b);

	ponto f = d - c;
	//ponto f = d.operator-(c);

        cout << "ponto e = a+b: ";
	e.print_info();
        cout << "ponto f = d-c: ";
	f.print_info();

	//if (f.operator==(k)) 
	if (f == k) { //(10,10) e (10,10)
		cout << "ponto f == k" << endl;
		cout << "ponto k: ";
		k.print_info();
	} else {
		cout << "ponto f != k" << endl;
		cout << "ponto k: ";
		k.print_info();
	}

	cout << "ponto a: " << a;
	cout << endl;
	cout << "ponto b: " << b;
	cout << endl;
	cout << "ponto c: " << c;
	cout << endl;
	cout << "ponto d: " << d;
	cout << endl;
	cout << "demais pontos: " << e << f << k << endl;

	return 0;
}
