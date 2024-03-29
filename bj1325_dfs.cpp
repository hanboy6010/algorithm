#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
int n, m;
vector<int> coms[10001];
vector<bool> visit(n + 1, false);
vector<int> res;
int mx = 0;

void dfs(int node) {
	res[node]++;
	mx = max(mx, res[node]);

	for (int i = 0; i < coms[node].size(); i++) {
		int next = coms[node][i];

		if (!visit[next]) {
			visit[next] = true;
			dfs(next);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;

		coms[temp1].push_back(temp2);
	}

	res = vector<int>(n + 1, 0);

	for (int i = 1; i < n + 1; i++) {
		visit = vector<bool>(n + 1, false);

		visit[i] = true;
		dfs(i);
	}

	for (int i = 0; i < res.size(); i++) {
		if (res[i] == mx) {
			cout << i << " ";
		}
	}
    return 0;
}

