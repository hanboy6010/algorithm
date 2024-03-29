#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> coms;
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;

		coms.push_back({ temp2, temp1 });
	}

	vector<int> res(n + 1, 0);
	queue<int> q;
	int mx = 0;

	for (int i = 0; i < m; i++) {
		q.push(coms[i].second);
		res[coms[i].first]++;

		while (!q.empty()) {
			int start = q.front();

			for (int j = 0; j < m; j++) {
				if (start == coms[j].first) {
					res[coms[i].first]++;
					q.push(coms[j].second);
				}
			}

			q.pop();
		}
		mx = max(mx, res[coms[i].first]);
	}

	vector<int> answer;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == mx) {
			answer.push_back(i);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

    return 0;
}

