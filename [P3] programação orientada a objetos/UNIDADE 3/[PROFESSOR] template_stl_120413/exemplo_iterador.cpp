#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void) {
	vector<int> numeros = {1,2,3,4,5,6,7,8,9,10};

	for (auto it = numeros.begin(); it != numeros.end(); ++it) {
		cout << *it << endl;
	}

	cout << endl;

	vector<int>::iterator _it = numeros.end();

	numeros.insert(_it, 11);

	_it = numeros.begin();

	numeros.insert(_it, 0);

	for (auto it = numeros.begin(); it != numeros.end(); ++it) {
		cout << *it << endl;
	}

	_it = numeros.begin();

	numeros.erase(_it);

	_it = numeros.end() - 1;
	numeros.erase(_it);

	cout << endl;

        for (vector<int>::const_iterator it = numeros.begin();
			it != numeros.end(); ++it) {
                cout << *it << endl;
        }

	cout << endl;

	for (vector<int>::reverse_iterator rit = numeros.rbegin();
			rit != numeros.rend(); ++rit) {
		cout << *rit << endl;
	}


	return 0;
}
