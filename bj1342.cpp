#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

char st_ring[10];
vector<int> qtt(26);

int calculate(char pre, int pos) {
	int result = 0;
	
	if (pos == strlen(st_ring)) {
		result++;
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (qtt[i] < 1 || i + 'a' == pre) {
				continue;
			}
			else {
				--qtt[i];
				result += calculate('a' + i, pos + 1);
				++qtt[i];
			}
		}
	}

	return result;
}

int main()
{
	cin >> st_ring;

	for (int i = 0; i < strlen(st_ring); i++) {
		qtt[st_ring[i] - 'a']++;
	}
	
	cout << calculate(0, 0) << "\n";
    return 0;
}

