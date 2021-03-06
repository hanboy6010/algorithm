#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m = 0;													// n = 입력받을 수의 갯수, m = m번 나온 수를 찾을 것이다.
	int count = 1;													// 숫자가 몇번 나왔는지 나타내는 수
	int temp;
	vector<int> num;												// 숫자가 들어갈 벡터

	cin >> n >> m;													// n과 m 입력
	

	for (int i = 0; i < n; i++)										// push_back 함수를 이용하여 벡터에 숫자를 입력해준다.
	{
		cin >> temp;
		num.push_back(temp);
	}

	sort(num.begin(), num.end());									// 입력받은 숫자들 오름차순 정렬 - m과 같은 횟수로 나온 수중 가장 작은것을 출력하기 위해 오름차순 정렬한다.

	for (int i = 1; i < num.size(); i++)
	{
		if (num[i] == num[i - 1])									// 만약 벡터의 이전 숫자와 지금 숫자가 같다면 count에 +1을 해준다.
		{
			count++;
			if (count == m)
			{
				cout << num[i] << endl;								// m과 나온 횟수가 같은 수중 가장 작은 수가 가장 먼저 나오므로 출력하고 프로그램을 종료한다.
				return 0;
			}
		}
		else
		{
			count = 1;												// 만약 벡터의 이전 숫자와 지금 숫자가 다르다면 count를 1로 초기화 해준다. 
			if (i == num.size() - 1)
			{
				cout << -1 << endl;									// 벡터의 마지막까지 m번 나온 숫자들이 없다면 -1을 출력한다.
			}
		}
	}
	return 0;
}