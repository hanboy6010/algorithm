#include <iostream>

using namespace std;

int main()
{
	double a;
	double b;
	double c;

	cin >> a >> b;
	if (a < 0 || b > 10) {
		cout << "Please enter vaild number";
		return 0;
	}

	c = a / b;

	cout.precision(15);
	cout << c << endl;

    return 0;
}

