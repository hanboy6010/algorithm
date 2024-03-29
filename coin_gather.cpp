#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> coins;
int result[1000][1000] = { 0, };

int main()
{
	int n = 0, m = 0;
	scanf_s("%d %d", &n, &m);
	if (n < 1 || m < 1 || n > 1000 || m > 1000) {
		printf("Please enter valid number");
		return 0;
	}

	int max_value = 0;
	for (int i = 0; i < n; i++) {
		vector<int> ttemp;
		for (int j = 0; j < m; j++) {
			int temp = 0;
			scanf_s("%d", &temp);

			ttemp.push_back(temp);
			max_value +=temp;
		}
		coins.push_back(ttemp);
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				result[i][j] = coins[i][j];
			}
			else if (j == 0) {
				result[i][j] = result[i - 1][j] + coins[i][j];
			}
			else if (i == 0) {
				result[i][j] = result[i][j - 1] + coins[i][j];
			}
			else {
				result[i][j] = min(result[i - 1][j], result[i][j - 1]) + coins[i][j];
			}			
		}
	}

	printf("%d\n", result[n - 1][m - 1]);

}

