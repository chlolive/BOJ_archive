#define _CRT_NO_SECURE_WARNINGS_
#include <stdio.h>
#define MAX_SIZE 1000000
#define INF 2000000

int min(int a, int b, int c);

int main() {
	int x;
	scanf("%d", &x);

	int dp_arr[MAX_SIZE];
	dp_arr[0] = INF;
	dp_arr[1] = 0;

	int a,b;
	for (int i = 2; i <= x; i++) {
		if (i % 3 != 0) a = 0;
		else a = i / 3;

		if (i % 2 != 0) b = 0;
		else b = i / 2;

		dp_arr[i] = min(dp_arr[a], dp_arr[b], dp_arr[i - 1]) + 1;
	}
	
	printf("%d\n", dp_arr[x]);

	return 0;
}

int min(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	else if (b <= a && b <= c) return b;
	else return c;
}