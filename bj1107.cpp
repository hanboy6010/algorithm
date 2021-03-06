#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

bool inavail[10];

int remote(int x) {
	if (x == 0) {
		if (inavail[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}

	int count = 0;

	while (x > 0) {
		if (inavail[x % 10]) {
			return 0;
		}

		x /= 10;
		count++;
	}

	return count;
}

int main()
{
	int n, m;
	cin >> n >> m;

	while (m--) {
		int temp;
		cin >> temp;

		inavail[temp] = true;
	}

	int res = abs(n - 100);

	for (int i = 0; i < 1000000; i++) {
		int temp = i;
		int count = remote(temp);

		if (count > 0) {
			int button = abs(temp - n);
			if (res > count + button) {
				res = count + button;
			}
		}
	}

	cout << res << endl;
	return 0;
}

