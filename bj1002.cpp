#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int t;
	int x1;
	int x2;
	int y1;
	int y2;
	int r1;
	int r2;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 < -10000 || y1 < -10000 || x2 < -10000 || y2 < -10000 || x1 > 10000 || y1 > 10000 || x2 > 10000 || y2 > 10000) {
			i--;
			cout << "Please enter valid number";
		}
		else if (r1 > 10000 || r1 < 0 || r2 > 10000 || r2 < 0) {
			i--;
			cout << "Please enter valid number";
		}
		else {
			double r = r1 + r2;
			double rr = abs(r2 - r1);
			double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			if (distance > r || distance < rr) { // 안만나는 경우
				cout << 0 << endl;
			}
			else if (distance == r) { // 외접하는 경우
				cout << 1 << endl;
			}
			else if (rr == distance && distance != 0) { // 내접하는 경우
				cout << 1 << endl;
			}
			else if (r2 > r1 + distance) { // 안에 포함
				cout << 0 << endl;
			}
			else if (rr < distance && distance < r) { // 두점에서 만남
				cout << 2 << endl;
			}
			else if (distance == 0) { // 두원 일치
				if (r1 == r2) {
					cout << -1 << endl;
				}
				else{
					cout << 0 << endl;
				}				
			}
		}
	}
	return 0;
}

