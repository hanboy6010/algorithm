#include<iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


int main()
{
	int n, m;
	cin >> n >> m;
	if (n < 1 || m < 1 || n > 100 || m > 100) {
		cout << "Enter valid number";
		return 0;
	}

	cout << m - gcd(n, m) << endl;
    return 0;
}

