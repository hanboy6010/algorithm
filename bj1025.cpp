#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int map[10][10] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}		
	}

	int res = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int x = -n; x < n; x++) {
				for (int y = -m; y < m; y++) {
					if (x == 0 && y == 0) {
						continue;
					}

					int temp = 0;
					int tempx = i;
					int tempy = j;

					while (tempx >= 0 && tempx < n && tempy >= 0 && tempy < m) {
						temp = temp * 10 + map[tempx][tempy];

						if (fabs(sqrt(temp) - (int)sqrt(temp)) == 0) {
							res = temp;
						}

						tempx += x;
						tempy += y;
					}
				}
			}
		}
	}
	cout << res << endl;
    return 0;
}

