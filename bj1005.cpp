#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int t;

	cin >> t;

	while (t--) {
		int n, k, w;
		vector<int> d; //시간
		vector<int> rule[1000]; //규칙
		vector<int> dep; // 시작점 판별
		vector<int> res; // 결과
		queue<int> start; // 시작점 모아놓은곳

		cin >> n >> k;
		if (n < 2 || n > 1000 || k < 1 || k > 100000) {
			cout << "Please enter valid number" << endl;
			return 0;
		}

		d.resize(n + 1);
		dep.resize(n + 1);
		res.resize(n + 1);

		for (int i = 1; i < n+1; i++) {
			cin >> d[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y;

			cin >> x >> y;

			rule[x].push_back(y);
			dep[y]++;
		}

		cin >> w;

		for (int i = 1; i < n + 1; i++) {
			if (dep[i] == 0) {
				start.push(i);
				res[i] = d[i];
			}
		}

		while (!start.empty()) {
			int st = start.front();

			if (st == w) {
				cout << res[st] << endl;
				break;
			}
			else {
				for (int &i : rule[st]) {
					dep[i]--;
					if (dep[i] == 0) {
						start.push(i);
					}
					res[i] = max(res[i], res[st] + d[i]);
				}
			}

			start.pop();
		}


		
	}
    return 0;
}

