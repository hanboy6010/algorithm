#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	int n;
	cin >> n;
	if (n < 1 || n > 100000) {
		cout << "Enter valid number";
		return 0;
	}

	vector<int> number(n);
	vector<int> qtt;
	vector<int> result(n);

	int max_num = 0;
	for(int i = 0; i < n; i++) {
		cin >> number[i];
		max_num = max(number[i], max_num);
	}

	qtt.resize(max_num + 1);

	for (int i = 0; i < n; i++) {
		qtt[number[i]]++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j * j <= number[i]; j++) {
			if (number[i] % j == 0) {
				if (number[i] / j != j) {
					result[i] += qtt[j] + qtt[number[i] / j];
				}
				else {
					result[i] += qtt[j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] - 1 << "\n";
	}
    return 0;
}

