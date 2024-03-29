#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>


using namespace std;
vector<int> graph[10002];
vector<int> res_bfs;
vector<int> res_dfs;
bool visit[1002];

void bfs(int start) {

	queue<int> que;
	que.push(start);
	visit[start] = true;

	while (!que.empty()) {
		int temp = que.front();			
		que.pop();
		res_bfs.push_back(temp);

		for (int i = 0; i < graph[temp].size(); i++) {
			if (!visit[graph[temp][i]]) {
				que.push(graph[temp][i]);
				visit[graph[temp][i]] = true;
			}
		}
	}
}

void dfs(int start) {
	visit[start] = true;
	res_dfs.push_back(start);

	for (int i = 0; i < graph[start].size(); i++) {
		if (!visit[graph[start][i]]) {
			dfs(graph[start][i]);
		}
	}
}

int main() {
	int n, m, start;
	int x, y;

	cin >> n >> m >> start;
	if (n < 1 || n > 1000 || m < 1 || m > 10000) {
		cout << "Please enter valid number" << endl;
	}

	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	bfs(start);
	memset(visit, false, sizeof(visit));
	dfs(start);

	for (int i = 0; i < res_dfs.size(); i++) {
		cout << res_dfs[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < res_bfs.size(); i++) {
		cout << res_bfs[i] << " ";
	}
	cout << "\n";

	return 0;
}