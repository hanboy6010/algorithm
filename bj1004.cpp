#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int t;

	cin >> t;

	while (t--) {
		int x1, y1, x2, y2, n, c1, c2, r;
		int result = 0;

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> c1 >> c2 >> r;
			double dis1 = sqrt(pow(x1 - c1, 2) + pow(y1 - c2, 2));
			double dis2 = sqrt(pow(x2 - c1, 2) + pow(y2 - c2, 2));

			if (dis1 > r && dis2 > r) {

			}
			else if (dis1 < r && dis2 < r) {

			}
			else {
				result++;
			}
		}
		cout << result << endl;
		
	}
    return 0;
}

