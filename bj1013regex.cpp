#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <regex>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		string num;
		std::cin >> num;
		
		if (regex_match(num, regex("(100+1+|01)+")) == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

    return 0;
}

