#include <stdio.h>
#include <stdlib.h>
int func(int n)
{
	if(n==1)
	return 1;
	else
	return n+func(n-1);
}
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	printf("%d\n",func(n));
}
