#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int res = 0;
vector<int> crain;
vector<int> lug;

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	cin >> n;
 	if (n < 1 || n > 50) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp < 0 || temp > 1000000) {
			return 0;
		}

		crain.push_back(temp);
	}

	cin >> m;
	if (n < 1 || n > 10000) {
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		if (temp < 0 || temp > 1000000) {
			return 0;
		}

		lug.push_back(temp);
	}

	sort(crain.begin(), crain.end(), cmp);
	sort(lug.begin(), lug.end(), cmp);

	if (crain[0] < lug[0]) {
		cout << -1 << endl;
		return 0;
	}

	while (!lug.empty()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < lug.size(); j++) {
				if (crain[i] >= lug[j]) {
					lug.erase(lug.begin() + j);
					break;
				}
				
			}
		}
		res++;
	}

	cout << res << endl;
    return 0;
}

