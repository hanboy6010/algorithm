#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int combi(int r, int n) {
	if (n == r || r == 0) {
		return 1;
	}
	else {
		return combi(r - 1, n - 1) + combi(r, n - 1);
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		long long int res;

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
			res = combi(n, m);
		}
		cout << res << endl;
	}
    return 0;
}

