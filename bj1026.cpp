#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	int t;
	cin >> t;
	if (t > 50 || t < 0) {
		cout << "Please enter valid number" << endl;
		return 0;
	}

	int res = 0;
	vector<int> a;
	vector<int> b;
	a.clear();
	b.clear();

	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;

		if (temp > 100 || temp < 0) {
			cout << "Please enter valid number" << endl;
			return 0;
		}

		a.push_back(temp);
	}
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;

		if (temp > 100 || temp < 0) {
			cout << "Please enter valid number" << endl;
			return 0;
		}

		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);

	for (int i = 0; i < t; i++) {
		res += a.at(i) * b.at(i);
	}

	cout << res << endl;

    return 0;
}

