#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
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

	vector<int> number;
	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp < 1 || temp > 1000000) {
			cout << "Enter valid number";
			return 0;
		}

		number.push_back(temp);
	}

	vector<int> result;
	for (int i = 0; i < n; i++) {
		int res = -1;
		for (int j = 0; j < n; j++) {
			if (number[0] % number[j] == 0) {
				res++;
			}
		}
		result.push_back(res);

		int first = number[0];
		number.erase(number.begin());
		number.push_back(first);
	}
	
	for (int i : result) {
		cout << i << endl;
	}

    return 0;
}

