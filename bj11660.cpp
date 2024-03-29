#include <stdio.h>
#include <cstring>
#include <algorithm>


int main()
{
	int n, m = 0;
	scanf("%d %d", &n, &m);

	if (n < 1 || n > 1024) {
		printf ("Enter valid number");
		return 0;
	}
	if (m < 1 || m > 100000) {
		printf ("Enter valid number");
		return 0;
	}
	
	int pre_sum[1025][1025];
	int temp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &temp);
			pre_sum[i + 1][j + 1] = pre_sum[i][j + 1] + pre_sum[i + 1][j] - pre_sum[i][j] + temp;
		}
	}
	
	int x1, y1, x2, y2;
	while (m--) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 > x2 || y1 > y2) {
			printf ("Enter valid number");
			return 0;
		}

		printf ("%d \n", pre_sum[x2][y2] - pre_sum[x1 - 1][y2] - pre_sum[x2][y1 - 1] + pre_sum[x1 - 1][y1 - 1]);
	}

    return 0;
}

