#include<iostream>
using namespace std;

class matrix {
	int** a;
	friend istream& operator >> (istream& in,const matrix& m);
	friend ostream& operator << (ostream& out,const matrix& m);
public:
	matrix() {
		a = new int* [3];
		for (int i = 0; i < 3; i++) {
			a[i] = new int[3];
		}
	}
	matrix operator + (matrix& m) {
		matrix temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp.a[i][j] = a[i][j] + m.a[i][j];
			}
		}
		return temp;
	}
	matrix operator - (matrix& m) {
		matrix temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp.a[i][j] = a[i][j] - m.a[i][j];
			}
		}
		return temp;
	}
	matrix operator * (matrix& m) {
		matrix temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp.a[i][j] = 0;
				for (int k = 0; k < 3; k++) {
					temp.a[i][j] += a[i][k] * m.a[k][j];
				}
			}
		}
		return temp;
	}
	matrix operator ++ () {
		matrix temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp.a[i][j] = ++a[i][j];
			}
		}
		return temp;
	}
	matrix operator ++ (int) {
		matrix temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp.a[i][j] = a[i][j] ++;
			}
		}
		return temp;
	}
	matrix operator -- () {
		matrix temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp.a[i][j] = --a[i][j];
			}
		}
		return temp;
	}
	matrix operator -- (int) {
		matrix temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp.a[i][j] = a[i][j]--;
			}
		}
		return temp;
	}
	~matrix() {
		for (int i = 0; i < 3; i++) {
			delete[] a[i];
		}
		delete[] a;
	}
};
istream& operator >> (istream& in,const matrix& m) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Enter the elements of matrix : ";
			in >> m.a[i][j];
		}
	}
	return in;
}
ostream& operator << (ostream& out,const matrix& m) {
	out << "Matrix : " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out << m.a[i][j] << " ";
		}
		cout << endl;
	}
	return out;
}
int main() {
	matrix m1, m2;
	cout << "For matrix 1 :" << endl;
	cin >> m1;
	cout << m1;
	cout << "For matrix 2 :" << endl;
	cin >> m2;
	cout << m2;
	system("pause");
	system("cls");
	int choice = 0;
	cout << "Enter one of the following : " << endl;
	cout << "1. ADD " << endl;
	cout << "2. SUBTRACT " << endl;
	cout << "3. MULTIPLY " << endl;
	cin >> choice;
	system("cls");
	if (choice == 1) {
		matrix m3 = m1 + m2;
		cout << "Addition of matrix : " << endl;
		cout << m3;
	}
	if (choice == 2) {
		matrix m4 = m1 - m2;
		cout << "Difference of matrix : " << endl;
		cout << m4;
	}
	if (choice == 3) {
		matrix m5 = m1 * m2;
		cout << "Product of matrix : " << endl;
		cout << m5;
	}
	system("pause");
	return 0;
}