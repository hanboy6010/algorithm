#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;


int main()
{
	int n, m;
	int sub_res = 0; // + 나 - 만을 눌러서 가는 방법
	int num_res = 0; // 번호와 +, -를 눌러서 가는 방법
	vector<int> valid;

	cin >> n >> m;
	if (n < 0 || n > 500000 || m < 0 || m > 10) {
		cout << " Plesae enter valid number" << endl;
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		valid.push_back(i);
	}

	int cnt = 0;
	while (m--) {
		int temp;
		cin >> temp;

		valid.erase(valid.begin() + (temp - cnt));
		cnt++;
	}

	int present = 100; // 현재 있는 체널

	sub_res = abs(n - present);

	int pre_res = 0, temp_res = 0;
	int count = 0;
	int n_temp = n;
	while (1) {
		int remain = n_temp % 10;

		for (int i : valid) {
			if(i == remain) {
				temp_res += remain * pow(10, count);
				num_res++; // 누른 버튼 수 +1
			}
		}

		if (pre_res == temp_res) {
			int swing = 10;
			int re;
			for (int i : valid) {
				if (abs(i - remain) < swing) {
					swing = abs(i - remain);
					re = i;
				}
			}
			temp_res += re * pow(10, count);
			num_res++; // 누른 버튼 수 +1
		}

		pre_res = temp_res;
		n_temp /= 10;
		count++;

		if (n_temp < 1) {
			break;
		}
	}

	num_res += abs(n - temp_res);
	int res = min(sub_res, num_res);

	cout << res << endl;
    return 0;
}

