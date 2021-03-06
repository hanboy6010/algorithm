#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

vector<int> first;
vector<int> second;
char temp_first[100] = { 0, };
char temp_second[100] = { 0, };

int main()
{
	cin >> temp_first >> temp_second;

	int i = 0;
	while (temp_first[i] != 0) {
		char temp = temp_first[i];
		
		first.push_back(temp_first[i] - 48);
		i++;
	}

	i = 0;
	while (temp_second[i] != 0) {
		second.push_back(temp_second[i] - 48);
		i++;
	}

	int result = 0;
	for (int i = 0; i < first.size(); i++) {
		int four = 0;

		int j = 0;
		while (i + j < first.size() && j < second.size()) {
			if (first[i + j] + second[j] == 4) {
				four++;
				break;
			}
			j++;
		}

		if (four == 0) {
			if (i + second.size() <= first.size()) {
				result = first.size();
				break;
			}
			else if(i == first.size() - 1) {
				result = second.size() + i + 1;
				break;
			}
			else {
				result = second.size() + i;
				break;
			}
		}
	}
	if (result == 0) {
		result = first.size() + second.size();
	}

	cout << result << endl;
    return 0;
}

