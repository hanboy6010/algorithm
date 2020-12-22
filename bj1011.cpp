#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int t;

	cin >> t;

	while (t--) {
		double x, y;
		double d = 0;
		int k = 0;
		int res = 0;

		cin >> x >> y;
		if (x < 0 || y < 0 || x > y || y > pow(2, 31)) {
			cout << "Please enter vaild number";
			return 0;
		}
		
		d = y - x;
		while (1) {
			k++;
			if (pow(k, 2) >= d) {
				break;
			}
		}

		if (pow(k, 2) == d) {
			res = (2 * k) - 1;
		}
		else if ((int)((pow(k, 2) + pow(k - 1, 2)) / 2) < d) {
			res = (2 * k) - 1;
		}
		else {
			res = (2 * k) - 2;
		}
		cout << res << endl;
	}
    return 0;
}

