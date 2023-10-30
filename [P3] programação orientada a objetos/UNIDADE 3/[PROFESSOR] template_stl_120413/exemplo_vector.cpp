#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void) {
	vector<int> numeros;
	vector<string> palavras;

	numeros.push_back(10);
	numeros.push_back(20);
	numeros.push_back(30);
	numeros.push_back(40);
	//insert e erase dependem de iteradores

	if (numeros.empty()) {
		cout << "vector de numeros esta vazio!" << endl;
	} else {
		cout << "vector de numeros nao esta vazio!" << endl;
	}

	for (int num : numeros) {
		cout << num << " ";
	}

	cout << endl;

	palavras.push_back("abacate");
	palavras.push_back("laranja");
	palavras.push_back("abacaxi");

        if (palavras.empty()) {
                cout << "vector de palavras esta vazio!" << endl;
        } else {
                cout << "vector de palavras nao esta vazio!" << endl;
        }


	for (const string palavra : palavras) {
		cout << palavra << " ";
	}

	cout << endl;

	return 0;

}
