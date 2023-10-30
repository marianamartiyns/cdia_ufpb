#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int main(void) {
	vector<int> numeros = {1,2,3,4,5,6,7,8,9,0};

	auto itera = std::find(numeros.begin(), numeros.end(), 9);

	if (itera != numeros.end()) {
		cout << "valor encontrado: " << *itera << endl;
	} else {
		cout << "valor nao encontrador!" << endl;
	}

	return 0;
}

