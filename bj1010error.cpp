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
		int n, m;
		int res;

		cin >> n >> m;
		if (n < 0 || n > m || m > 30) {
			cout << "Please enter valid number";
			return 0;
		}

		if (n == m) {
			res = 1;
		}
		else if (n == 1 || m - n == 1) {
			res = m;
		}
		else {
			int temp = m - n;
			double mul = 1;
			double div = 1;

			for (int i = 0; i < temp; i++) {
				mul *= m - i;
				div *= 1 + i;
			}
			res = mul / div;
		}
		cout << res << endl;
	}
    return 0;
}

