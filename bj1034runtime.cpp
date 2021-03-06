#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int n, m, k;
int res = 0;
int table[50][50] = { 0, };
int temp_table[50][50] = { 0, };
int row_sum[50] = { 0, };
vector<int> correct_row;
vector<int> result;

bool cmp(int a, int b) {
	return a > b;
}

void button(int z) {
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
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;

			table[i][j] = temp;
			row_sum[i] += temp;
		}
	}

	cin >> k;

	for (int i = 0; i < n; i++) {
		if ((m - k) == row_sum[i] || (k > (m - row_sum[i]) &&(k - (m - row_sum[i])) % 2 == 0)) {
			correct_row.push_back(i);
		}
	}

	for (int i : correct_row) {
		int temp_res = 0;
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
			int temp_sum = 0;
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
	cout << result.at(0) << endl;

    return 0;
}

