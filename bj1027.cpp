#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

double slope(int x1, int y1, int x2, int y2) {
	return (double)(y2 - y1) / (x2 - x1);
}

int main()
{
	int t;
	cin >> t;

	if (t > 50 || t < 0) {
		cout << "Please enter valid number";
		return 0;
	}

	int x[50] = { 0, };
	int y[50] = { 0, };
	int result[50] = { 0, };

	for (int i = 0; i < t; i++) {
		long long int temp;
		cin >> temp;

		if (temp > 1000000000 || temp < 0) {
			cout << "Please enter valid number";
			return 0;
		}

		x[i] = i + 1;
		y[i] = temp;
	}

	int res = 0;
	for (int i = 0; i < t; i++) {
		double highest = -999999999;
		for (int j = i + 1; j < t; j++) {
			if (slope(x[i], y[i], x[j], y[j]) > highest) {
				highest = slope(x[i], y[i], x[j], y[j]);
				result[i]++;
				result[j]++;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		res = max(res, result[i]);
	}
	cout << res << endl;

    return 0;
}

