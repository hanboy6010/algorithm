#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)																							// ccw함수 = 세 점의 좌표를 입력해서 좌회전인지 우회전인지 구분하는 함수
{
	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;																									// 세점의 외적을 한 것을 저장하는 변수 TEMP

	if (temp > 0)																																// TEMP 값이 양수이면 좌회전, 음수이면 우회전, 0이면 일직선이다.
	{
		return 1;
	}
	else if (temp < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

vector<pair<int, int>> convex_hull(vector<pair<int, int>> list)																					// 입력받은 카메라의 좌표들 중에서 컨벡스헐을 구성하는 좌표들을 뽑아내는 함수
{
	vector<pair<int, int>> convex;
	pair<int, int> gizoon = list[0];																											// 첫번째 좌표를 기준으로 정한다. 첫번째 좌표는 입력받은 좌표들중 x좌표가 가장 작은 좌표이다.
	pair<int, int> temp;

	for (int i = 1; i < list.size() - 1; i++)																									// 첫번째 기준좌표를 제외한 나머지 좌표들을 y좌표를 기준으로 정렬한다.
	{
		for (int j = 1; j < list.size() - 1; j++)
		{
			if (list[j].second > list[j + 1].second)																							// 정렬은 버블정렬을 사용하였다.
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}

	list.push_back(gizoon);																														// 기준점을 컨벡스헐을 만들기 위한 마지막 좌표로 한번 더 넣어준다.
	convex.push_back(gizoon);

	for (int i = 0; i < list.size() - 1; i++)
	{
		if (gizoon.first == list[i + 2].first && gizoon.second == list[i + 2].second)															// 컨벡스헐의 종료조건이다.
		{
			int kkw = ccw(list[i].first, list[i].second, list[i + 1].first, list[i + 1].second, list[i + 2].first, list[i + 2].second);			// ccw를 통해 점의 진행방향이 계속 같은 방향으로 회전하는 점들만 모아서 컨벡스헐 배열에 넣어준다.
			if (kkw == 1)
			{
				convex.push_back(list[i + 1]);
			}

			return convex;																														// 함수가 종료될 조건이 되면 만들어진 컨벡스 배열을 리턴한다.
		}
		else
		{
			int kkw = ccw(list[i].first, list[i].second, list[i + 1].first, list[i + 1].second, list[i + 2].first, list[i + 2].second);			// 종료조건이 아닐시 실행되는 부분
			if (kkw == 1)
			{
				convex.push_back(list[i + 1]);
			}
		}

	}

}

vector<char> check(vector<pair<int, int>> jewel, vector<pair<int, int>> convex)																	// 입력받은 보석들의 좌표에서 x축 양의 방향으로 쭉 직선을 그렸을 때
{																																				// 컨벡스헐의 선분들과 홀수번 만나면 컨벡스헐 안에 있고, 짝수번 만나면 컨벡스헐 밖에 있는것을
	vector<char> check;																															// 이용하여 보석들이 카메라의 시야 안에 있는지 없는지 체크하는 함수이다. 

	for (int i = 0; i < jewel.size(); i++)
	{
		int count = 0;																															// 직선이 컨벡스헐의 선분을 만나는 횟수를 저장하는 변수
		for (int j = 0; j < convex.size() - 1; j++)
		{																																		// 컨벡스헐을 그린 순서대로 배열에 저장이 되어있기 때문에 선분을 이루는 좌표순서 또한 동일하다.
			if (jewel[i].first >= convex[j].first || jewel[i].first >= convex[j + 1].first)														// 컨벡스헐의 선분과 만나기 위해서는 일단 보석의 x좌표가 컨벡스헐의 선분의 x좌표 두개중에서
			{																																	// 하나라도 큰것이 존재해야 한다. (x축의 양의 방향으로 직선을 그리기 때문에)
				if (jewel[i].second <= convex[j].second && jewel[i].second >= convex[j + 1].second)												// 그 다음 두 선분의 y좌표들 사이에 보석의 y좌표가 있다면
				{																																// 보석으로부터 나오는 직선은 무조건 컨벡스헐의 선분을 지나게 된다.
					count++;
				}
				else if (jewel[i].second >= convex[j].second && jewel[i].second <= convex[j + 1].second)										// 같은 조건으로 컨벡스헐의 선분을 지날 때마다 count변수에 1씩 증가시켜준다.
				{
					count++;
				}
			}
		}

		if ((count % 2) == 0)																													// 보석의 좌표가 컨벡스헐의 선분과 홀수번 만났는지 짝수번 만났는지 체크하는 부분
		{
			check.push_back('N');																												// 짝수번 만났으면 N을 배열에 넣는다.
		}
		else
		{
			check.push_back('Y');																												// 홀수번 만났으면 Y를 배열에 넣는다.
		}
	}

	return check;																																// 함수가 종료되면 그동안 저장해놓은 배열을 리턴해준다.
}

int main()
{
	int n, m = 0;																																// n = 입력받을 보석의 갯수, m = 입력받을 카메라의 갯수						
	int temp_x;														
	int temp_y;												

	cin >> n >> m;																																// n과 m 입력											

	vector<pair<int, int>> jewel;																												// 보석의 좌표들을 저장해놓을 벡터 배열
	vector<pair<int, int>> cam;																													// 카메라의 좌표들을 저장해놓을 벡터 배열
	vector<pair<int, int>> convex;																												// 컨벡스헐의 좌표들을 저장해놓을 벡터 배열
	vector<char> sol;																															// 정답인 N 혹은 Y 배열들을 저장해놓을 벡터 배열

	for (int i = 0; i < n; i++)										
	{
		cin >> temp_x >> temp_y;																												// 입력받은 n개만큼 보석을 입력받아 배열에 넣어준다.
		jewel.push_back(make_pair(temp_x, temp_y));
	}

	for (int i = 0; i < m; i++)										
	{
		cin >> temp_x >> temp_y;																												// 입력받은 m개만큼 카메라를 입력받아 배열에 넣어준다.
		cam.push_back(make_pair(temp_x, temp_y));
	}

	sort(jewel.begin(), jewel.end());																											// 보석과 카메라 배열들을 정렬해준다.
	sort(cam.begin(), cam.end());

	for (int i = 0; i < m-1; i++)
	{
		if (cam[i].first == cam[i + 1].first && cam[i].second == cam[i + 1].second)																// 정렬되어있는 카메라 배열에서 i번째와 i+1번째 좌표의 x, y좌표가 모두 같다면
		{																																		// 두 카메라가 동일 위치에 있으므로 예외 case이다.
			cout << "Two Cameras are in same location" << endl;
			return -1;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (jewel[i].first == jewel[i + 1].first && jewel[i].second == jewel[i + 1].second)														// 정렬되어있는 보석의 배열에서 i번쨰와 i+1번쨰 좌표의 x, y좌표가 모두 같다면
		{																																		// 두 보석이 동일 위치에 있으므로 예외 case이다.
			cout << "Two Jewels are in same location" << endl;
			return -1;
		}
	}

	convex = convex_hull(cam);																													//컨벡스헐을 만들어주는 convex함수 호출

	for (int i = 0; i < m - 2; i++)
	{
		int kkw = ccw(convex[i].first, convex[i].second, convex[i + 1].first, convex[i + 1].second, convex[i + 2].first, convex[i + 2].second);	// 만들어진 컨벡스헐 좌표들끼리 비교해봤을 때 ccw = 0이면 한줄에 있는 것이므로
		if (kkw == 0)																															// 예외 case이다.
		{	
			cout << "Three Cameras are in same line" << endl;
			return -1;
		}
	}
	
	sol = check(jewel, convex);																													// check함수를 호출해서 답이 들어있는 배열을 리턴받는다.

	for (int i = 0; i < sol.size(); i++)
	{
		cout << sol[i] << " ";																													// 답이 들어있는 sol 벡터 배열을 출력한다.
	}
	cout << endl;

	return 0;
}