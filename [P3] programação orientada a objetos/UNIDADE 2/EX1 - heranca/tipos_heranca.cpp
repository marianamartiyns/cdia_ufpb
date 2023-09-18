#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class base {
private:
	int x;
protected:
	int y;
public:
	base(int i) { x = i; y = 0; }
	int get_x() { return x; }
	void set_x(int i) { x = i; }
};

class public_derive : public base {
	//get_x e set_x sao publicos - acessivel
	//y eh protegido - acessivel dentro da classe
	//x eh privado - nao acessivel
public:
	public_derive(int i) : base(i) { }
	void print() {
		y++;
		cout << "get_x = " << get_x() << endl;
		cout << "y = " << y << endl;
	}
};

class protected_derive : protected base {
	//get_x e set_x sao protegidos - acessiveis dentro da classe
	//y eh protegido - acessivel dentro da classe (e pelos descendentes)
	//x - nao acessivel
public:
	protected_derive(int i) : base(i) { }
};

class private_derive : private base {
	//get_x e set_X - privados - acessiveis dentro da classe
	//y eh privado - acessivel dentro da classe (mas nao pelos descendentes)
	//x - nao acessivel
public:
	private_derive(int i) : base(i) { }
};

int main(void) {
	public_derive pud1(10);
	protected_derive prod1(15);
	private_derive prid1(25);

	pud1.set_x(15);
	cout << "pud1.get_x() = " << pud1.get_x() << endl;
//	cout << "prod1.get_x() = " << prod1.get_x() << endl; //erro!
//	cout << "prid1.get_x() = " << prid1.get_x() << endl; //erro!

	//prd1.set_x(20); protected - nao acessivel atraves de objeto

}




