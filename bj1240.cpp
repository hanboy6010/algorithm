#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	int temp1, temp2, temp3;

	vector<bool> visit(n, 0);
	vector<vector<int>> dots(n, vector<int> (3, 0));
	for (int i = 0; i < n - 1; i++) {
		cin >> temp1 >> temp2 >> temp3;
		dots[i][0] = temp1;
		dots[i][1] = temp2;
		dots[i][2] = temp3;
	}

	vector<pair<int, int>> goal;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		goal.push_back({ temp1, temp2 });
	}

	stack<int> s;
	stack<int> dis;
	for (int i = 0; i < goal.size(); i++) {
		visit = vector<bool>(n, 0);
		int res = 0;
		int start = goal[i].first;
		int end = goal[i].second;

		s.push(start);
		while (!s.empty()) {
			int now = s.top();
			bool ismatch = false;
			for (int j = 0; j < dots.size(); j++) {
				if (visit[j] == true) {
					continue;
				}
				if (dots[j][0] == now) {
					s.push(dots[j][1]);
					dis.push(dots[j][2]);
					ismatch = true;
					visit[j] = true;
					break;
				}
				else if (dots[j][1] == now) {
					s.push(dots[j][0]);
					dis.push(dots[j][2]);
					ismatch = true;
					visit[j] = true;
					break;
				}
			}
			if (s.top() == end) {
				while (!dis.empty()) {
					int tem = dis.top();
					res += tem;
					s.pop();
					dis.pop();
				}
				s.pop();
			}
			if (ismatch == false) {
				s.pop();
				dis.pop();
			}
		}
		cout << res << endl;
	}
    return 0;
}

