#include<stdio.h>
int func(int n)
{
	printf("%d\n", n % 10);
	if (n / 10 > 0)
	{
		func(n / 10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	func(n);
}