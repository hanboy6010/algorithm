#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

long long int n, m, k;
long long int res = 0;
long long int table[50][50];
long long int temp_table[50][50];

bool cmp(long long int a, long long int b) {
	return a > b;
}

void button(long long int z) {
	for (int r = 0; r < n; r++) {
		if (temp_table[r][z] == 0) {
			temp_table[r][z] = 1;
		}
		else if (temp_table[r][z] == 1) {
			temp_table[r][z] = 0;
		}
	}
	return;
}

int main()
{
	vector<long long int> row_sum;
	vector<long long int> correct_row;
	vector<long long int> result;
	row_sum.clear();
	correct_row.clear();
	result.clear();

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			long long int temp;
			cin >> temp;

			table[i][j] = temp;
			row_sum[i] += temp;
		}
	}

	cin >> k;

	for (int i = 0; i < n; i++) {
		long long int last = m - row_sum[i];
		if (k == last || (k > last && (k - last) % 2 == 0)) {
			correct_row.push_back(i);
		}
	}

	for (int i : correct_row) {
		long long int temp_res = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				temp_table[x][y] = table[x][y];
			}
		}
		for (int z = 0; z < m; z++) {
			if (temp_table[i][z] == 0) {
				button(z);
			}
		}
		for (int a = 0; a < n; a++) {
			long long int temp_sum = 0;
			for (int b = 0; b < m; b++) {
				temp_sum += temp_table[a][b];
			}
			if (temp_sum == m) {
				temp_res++;
			}
		}
		result.push_back(temp_res);
	}

	sort(result.begin(), result.end(), cmp);
	cout << result[0] << endl;

	return 0;
}

