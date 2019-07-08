#include<stdio.h>
void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
		printf("%c %c\n", A, C);
	else {
		hanoi(n - 1, A, C, B);
		printf("%c %c\n", A, C);
		hanoi(n - 1, B, A, C);
	}
}
int main()
{
	int N;
	char A = 'A', B = 'B', C = 'C';
	scanf("%d", &N);
	hanoi(N, A, B, C);
	return 0;
}