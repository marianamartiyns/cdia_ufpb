#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::ostream;

class coisa {
        int atributo;
public:
        coisa(int a = 0) { atributo = a; }
        friend ostream& operator<<(ostream& out, const coisa& c) {
                out << "coisa(" << c.atributo << ") ";
                return out;
        }
	friend bool operator<(const coisa& a, const coisa& b) {
		return ((a.atributo) < (b.atributo));
	}
};


int main() {
	vector<int> numeros = { 3, 1, 4, 2, 5, 9, 7, 11, 14, 21, 12, 0 };
	vector<coisa> coisas;

	coisas.push_back(coisa(10));
	coisas.push_back(coisa(20));
	coisas.push_back(coisa(30));

	std::sort(numeros.begin(), numeros.end());

	for (auto num : numeros) {
		cout << num << " ";
	}

	cout << endl;

	std::sort(coisas.begin(), coisas.end());

	for (auto c: coisas) {
		cout << c << " ";
	}

	cout << endl;


	return 0;
}

