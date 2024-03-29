#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<pair<long long, long long>> dots;
vector<pair<long long, long long>> convex;

long long ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	return (a.first*b.second + b.first*c.second + c.first*a.second) - (b.first*a.second + c.first*b.second + a.first*c.second);
}

bool minimum_y(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

bool anti_clockwise(pair<long long, long long> a, pair<long long, long long> b) {
	long long ac = ccw(dots[0], a, b);
	if (ac == 0) {
		return (a.first + a.second) < (b.first + b.second);
	}
	else {
		return ac > 0;
	}
}

int main()
{
	long long n = 0;
	int m = 0;
	int result = 0;

	scanf_s("%d %d", &n, &m);
	
	if (m <= 0 || m > 100000) {
		printf("Please Enter valid number");
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int temp_x, temp_y = 0;
		scanf_s("%d %d", &temp_x, &temp_y);
		if (temp_x > n || temp_y > n) {
			printf("Please enter valid number");
			return 0;
		}
		dots.push_back(make_pair(temp_x, temp_y));
	}

	sort(dots.begin(), dots.end(), minimum_y);
	sort(dots.begin() + 1, dots.end(), anti_clockwise);

	convex.push_back(dots[0]);
	convex.push_back(dots[1]);

	for (int i = 2; i < m; i++) {
		while (convex.size() > 1) {
			pair<long long, long long> second = convex[convex.size() - 1];
			pair<long long, long long> first = convex[convex.size() - 2];
			convex.pop_back();

			if (ccw(first, second, dots[i]) > 0) {
				convex.push_back(second);
				break;
			}
		}
		convex.push_back(dots[i]);
	}

	printf("%d\n", convex.size());

    return 0;
}

