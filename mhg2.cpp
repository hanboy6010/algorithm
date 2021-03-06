#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m = 0;													// n = 입력받을 수의 갯수, m = m번 이상 연속하는 수의 합을 구할것이다.
	int temp;														// 최대합과 비교할 새로운 출발점으로부터의 최대합을 저장할 변수
	int maxnum = 0;													// 각 인덱스를 지나갈 때마다 연속된 수의 최대합을 저장하는 변수
	vector<int> num;												// 입력 받은 숫자가 들어갈 벡터

	cin >> n >> m;													// n과 m 입력

	for (int i = 0; i < n; i++)										// push_back 함수를 이용하여 벡터에 숫자를 입력해준다.
	{
		cin >> temp;
		num.push_back(temp);
	}

	for (int i = 0; i < m; i++)										// 맨 처음부터 m번째까지 수의 합을 초기 최댓값으로 지정해준다.
	{
		maxnum += num[i];
	}

	for (int i = 0; i < num.size() - (m-1); i++)					// 기존의 최대합과 새로 구한 최대합을 비교해주는 부분
	{
		temp = 0;													// 초기의 TEMP값은 0이다.
		for (int j = i; j < i + m; j++)								
		{
			if ((j + m) < num.size() + m)							// TEMP값에 변하는 인덱스에서 시작해서 연속된 최대합을 저장하기 위한 계산
			{
				temp += num[j];
			}
		}
		if (i > 0 && (i + m) < num.size() + m)						// 처음 최댓값은 위에서 구했으니 i가 0보다 크고, i + m 이 배열보다 넘어가면 안되므로 범위를 지정해준다.
		{
			if (temp >= maxnum + num[i + m - 1])					// 만약 그 인덱스에서 구한 연속된 합이 지금까지의 최대합보다 크면 최대합을 갱신한다.
			{
				maxnum = temp;
			}
			else
			{
				if (i == n - m && num[i + m - 1] < 0)				// 마지막 수가 음수일 때는 최대합에 굳이 더하지 않는 부분
				{
					
				}
				else
				{
					maxnum += num[i + m - 1];						// TEMP값보다 지금까지 구한 최대합이 클 경우 늘어난 인덱스의 값을 최대합에 더해준다.
				}
			}
		}	
	}
	
	cout << maxnum << endl;
	return 0;
}