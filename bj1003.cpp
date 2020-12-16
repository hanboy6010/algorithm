#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
	int arr[41] = {0, 1, 1};

	for (int i = 3; i < 41; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	return arr[n];
}

int main()
{
	int t;

	cin >> t;

	for(int i = 0; i < t; i++) {
		int x;
		cin >> x;

		if (x > 40) {
			cout << "Please enter vaild number";
		}
		else {

			if (x == 0) {
				printf("%d %d\n", 1, 0);
			}
			else if (x == 1) {
				printf("%d %d\n", 0, 1);
			}
			else {
				printf("%d %d\n", fib(x-1), fib(x));
			}
		}
	}

    return 0;
}

