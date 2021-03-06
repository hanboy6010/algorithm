#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int m, n, k;
int x, y;
int grid[50][50] = { 0 };
int temp_grid[50][50] = { 0 };
int next_y[4] = { 1, -1, 0, 0 };
int next_x[4] = { 0, 0, 1, -1 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nextx = x + next_x[i];
		int nexty = y + next_y[i];

		if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) {
			continue;
		}

		if (grid[nexty][nextx] && !temp_grid[nexty][nextx]) {
			temp_grid[nexty][nextx]++;
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

		memset(grid, 0, sizeof(grid));
		memset(temp_grid, 0, sizeof(temp_grid));

		for (int i = 0; i < k; i++) {
			cin >> x >> y;

			if (x < m  && y < n) {
				grid[y][x] = 1;
			}

		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] && !temp_grid[i][j]) {
					res++;
					temp_grid[i][j]++;
					dfs(i, j);
				}
			}
		}

		cout << res << endl;
	}
	return 0;
}

