#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int m, n, k;
int x, y;
int grid[51][51] = { 0 };
int temp_grid[51][51] = { 0 };
int next_y[4] = { 1, -1, 0, 0 };
int next_x[4] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	temp_grid[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextx = x + next_x[i];
		int nexty = y + next_y[i];

		if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) {
			continue;
		}

		if (grid[nexty][nextx] == 1 && temp_grid[nexty][nextx] == 0) {
			dfs(nexty, nextx);
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int res = 0;

		cin >> m >> n >> k;
		if (m < 0 || n < 0 || m > 50 || n > 50) {
			cout << "Please enter valid number" << endl;
			return 0;
		}

		for (int i = 0; i < k; i++) {
			cin >> x >> y;

			if (x < m  && y < n) {
				grid[y][x] = 1;
			}

		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 && temp_grid[i][j] == 0) {
					res++;
					dfs(i, j);
				}
			}
		}

		cout << res << endl;
	}
	return 0;
}

