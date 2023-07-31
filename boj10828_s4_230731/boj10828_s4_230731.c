#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
int stack[10000] = { -1 };
int top = -1;

void push(int num);
int pop(void);

int main() {
	int N;
	scanf("%d", &N);

	char str[10];
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%s", str);

		if (strcmp(str, "push")==0) {
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n",pop());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", top + 1);
		}
		else if (strcmp(str, "empty") == 0) {
			if (top == -1) printf("%d\n", 1);
			else printf("%d\n", 0);
		}
		else if (strcmp(str, "top") == 0) {
			if (top == -1) printf("%d\n", -1);
			else printf("%d\n", stack[top]);
		}
	}
	return 0;
}

void push(int num) {
	if (top == 9999) {
		fprintf(stderr, "The stack is full.\n");
		exit(1);
	}
	stack[++top] = num;
}

int pop(void) {
	if (top == -1) {
		return -1;
	}
	return stack[top--];
}