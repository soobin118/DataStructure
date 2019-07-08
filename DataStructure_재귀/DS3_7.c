#include<stdio.h>
#include<string.h>
int count(char *st,char c,int n,int a)
{
	int i,cnt=0;
	for (i = a; i < n; i++)
	{
		if (st[i] == c)
			cnt++;
	}
	if (a <= n)
	{
		count(st, c, n, a + 1);
	}
	return cnt;
}
int main()
{
	int n,a=0,cnt=0;
	char st[100],c;
	scanf("%s\n", st);
	scanf("%c", &c);
	n = strlen(st);
	cnt=count(st, c, n, a);
	printf("%d\n", cnt);
}