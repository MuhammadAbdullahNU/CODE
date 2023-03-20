#include<iostream>
#include<string>
using namespace std;

class idiot {
	string name[5] = { "ali", "faizan", "zaka", "waqar", "saim" };
	char grade[5] = { 'A', 'B', 'C', 'D', 'E' };
public:
	char& operator [] (string n) {
		for (int i = 0; i < 5; i++) {
			if (n == name[i]) {
				return grade[i];
			}
		}
	}
};
int main() {
	string name;
	idiot i1;
	cout << "Enter the name of student : ";
	cin >> name;
	cout << i1[name] << " is the grade of student : ";
	return 0;
}