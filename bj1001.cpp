#include <iostream>

using namespace std;

int main() {
	int a;
	int b;
	int c;

	cin >> a;
	if (a < 0) {
		cout << " please enter over 0";
	}

	cin >> b;
	if (b > 10) {
		cout << "please enter under 10";
	}

	c = a - b;
	cout << c;
}