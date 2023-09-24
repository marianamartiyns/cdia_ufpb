#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class matrix {
	vector<vector<int>> data;
public:
	matrix(vector<vector<int>> m):data(m) {}

	vector<int>& operator[](int index) {
		return data[index];
	}

	matrix& operator=(const matrix& outro) {
		if (this != &outro) {
			data = outro.data;
		}

		return *this;
	}

	void print_data() {
		for (const auto& row : data) {
			for (int num : row) {
				cout << num << " ";

			}
			cout << endl;
		}
	}

};

int main(void) {
	vector<vector<int>> v1 = {{1,2,3}, {4,5,6}, {7,8,9}};
	vector<vector<int>> v2 = {{7,8,9}, {1,2,3}, {4,5,6}};

	matrix m1(v1);
	matrix m2(v2);

	cout << "m1: " << endl;
	m1.print_data();
	cout << endl;

	cout << "m2: " << endl;
	m2.print_data();
	cout << endl;

	cout << "m1[1][1] = ";
	cout << m1[1][1] << endl;

	cout << "m2[0][2] = ";
	cout << m2[0][2] << endl;

	m1 = m2;

	cout << endl;

	cout << "m1 (apos m1 = m2):" << endl;
	m1.print_data();
	cout << endl;

	return 0;
}
