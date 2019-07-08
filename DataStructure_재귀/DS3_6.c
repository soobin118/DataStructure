#include<stdio.h>
int func(int a, int b)
{
	int r;
	if (b > 0)
	{
		r = a%b;
		a = b;
		b = r;
		func(a, b);
	}
	else return a;
}
int main()
{
	int a, b, gcd;
	scanf("%d%d", &a, &b);
	gcd=func(a, b);
	printf("%d\n", gcd);
}