#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
	int n;

	scanf_s("%d", &n);

	if (n < 1 || n > 1000000) {
		printf("Please enter valid number");
		return 0;
	}

	unsigned long long int divide = pow(10, 9) + 7;
	unsigned long long int result = 1;

	for (int i = 0; i < n + 2; i++) {
		result *= 2;
		result = result % divide;
	}

	result = result - pow(2, 3) + 3;

	printf("%d\n", result);
	return 0;
}

