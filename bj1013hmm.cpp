#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

bool func(string num) {
	bool res = true;
	char state = 's';

	for (int i = 0; i < num.length(); i++) {
		if (state == 's') {
			if (num[i] == '0') {
				state = 'a';
				i++;
			}
			else {
				state = 'b';
				i++;
			}
		}
		else if (state == 'a') {
			if (num[i] == '0') {
				if (num[i + 1] == '1') {
					state = 'a';
					i++;
				}
				else if (num[i + 1] == '0') {
					res = false;
				}
			}
			else {
				if (num[i + 1] == '0') {
					state = 'b';
					i++;
				}
				else if (num[i + 1] == '1') {
					res = false;
				}
			}
		}
		else if (state == 'b') {
			if (num[i] == '1') {
				res = false;
			}
			else if (num[i] == '0') {
				state = 'c';
			}
		}
		else if (state == 'c') {
			if (num[i] == '0') {
				state = 'c';
			}
			else if (num[i] == '1') {
				state = 'd';
			}
		}
		else if (state == 'd') {
			if (num[i] == '0') {
				if (num[i + 1] == '1') {
					state = 'a';
					i++;
				}
				else if (num[i + 1] == '0') {
					res = false;
				}
			}
			else {
				if (num[i + 1] == '0') {
					state = 'b';
					i++;
				}
				else if (num[i + 1] == '1') {
					state = 'd';
					i++;
				}
			}
		}
	}
	if (state == 'b' || state == 'c') {
		res = false;
	}
	return res;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		string num;
		std::cin >> num;
		if (num.length() < 1 || num.length() > 200) {
			cout << "Please enter valid number";
			return 0;
		}

		if (func(num) == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

