#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
int mount[101][71];
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
bool visit[101][71];
int answer = 0;
bool ispeak;

void dfs(int x, int y) {
	int xnow = 0;
	int ynow = 0;

	for (int i = 0; i < 8; i++) {
		xnow = x + dx[i];
		ynow = y + dy[i];

		if (xnow < 0 || ynow < 0 || xnow > n || ynow > m) {
			continue;
		}
		if (mount[x][y] < mount[xnow][ynow]) {
			ispeak = false;
		}
		if (visit[xnow][ynow] == true) {
			continue;
		}

		if (mount[x][y] == mount[xnow][ynow]) {
			visit[xnow][ynow] = true;
			dfs(xnow, ynow);
		}

	}
}

int main()
{
	cin >> n >> m;

	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			mount[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == true) {
				continue;
			}
			visit[i][j] = true;
			ispeak = true;
			dfs(i, j);
			if (ispeak == true) {
				answer++;
			}
		}
	}
	cout << answer << endl;

    return answer;
}

