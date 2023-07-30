#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * N);


	int cnt = 0;
	while (cnt < N) {
		scanf("%d", &arr[cnt]);
		cnt++;
	}

	int x, y, z;
	int max = 0;
	int sum = 0;

	for (x = 0; x < N-2; x++) {
		for (y = x+1; y < N-1; y++) {
			for (z = y+1; z < N; z++) {
				sum = arr[x] + arr[y] + arr[z];
				if (sum > M) break; /****Problem occurs!****/
				if (sum > max) max = sum;
			}
		}
	}

	printf("%d", max);
	free(arr);
	return 0;
}