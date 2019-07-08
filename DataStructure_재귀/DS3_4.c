#include<stdio.h>
#include<stdlib.h>
int maxfunc(int *p, int n)
{
	int i,maxnum=p[0];
	if (n - 1 > 0)
	{
		maxfunc(p, n - 1);
		for (i = 0; i < n-1; i++)
		{
			if (maxnum < p[i])
				maxnum = p[i];
		}
		if (maxnum < p[n - 1])
			maxnum = p[n - 1];
	}
	return maxnum;
}
int main()
{
	int i,n,mn ,*p;
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	mn=maxfunc(p, n);
	printf("%d\n", mn);
}