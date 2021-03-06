#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int t;
int seq = 10;
int sum = 9;
int row = 0;
int column = 0;
int temp = 0;
int diff = 0;
vector<int> vec;

int sumsum(int seq) {
	int temp = vec[seq - 1] + vec[seq - 9];
	vec.push_back(temp);
	sum += temp;
	return 0;
}

void result(int col, int ro) {
	int col_temp = col;
	int ro_temp = ro;
	int  res = 0;

	while (ro_temp > 0) {		
		ro_temp--;
		temp += col_temp * pow(10, ro_temp);
		col_temp--;
	}
	diff = sum - t;

	if (diff < col_temp) {
		res = temp - diff;
		cout << res << endl;
		return;
	}
	else {
		temp = col * pow(10, ro - 1);
		diff -= col_temp + 1;
		col_temp = col - 1;
		ro_temp = ro_temp - 1;
		result(col_temp, ro_temp);
	}
}

int main()
{	
	vec.push_back(0);
	cin >> t;
	if (t > 1000000 || t < 0) {
		cout << "Please enter valid number";
		return 0;
	}

	if (t == 0) {
		cout << t << endl;
	}
	
	for (int i = 1; i < 10; i++) {
		vec.push_back(1);
	}

	while (1) {
		if (seq % 9 == 1) {
			vec.push_back(1);
			sum++;
		}
		else {
			sumsum(seq);
		}

		if (sum > t) {
			break;
		}
		else {
			seq++;
		}
	}

	if (seq % 9 == 0) {
		row = seq / 9;
	}
	else {
		row = seq / 9 + 1;
	}
	column = seq % 9 + (row - 2);
	
	result(column, row);

    return 0;
}

