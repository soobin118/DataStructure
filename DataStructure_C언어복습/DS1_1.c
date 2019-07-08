#include<stdio.h>
int sum(int x)
{
	int i,s=0;
	for(i=1;i<=x;i++)
		s+=i;
	return s;
}
int main()
{
	int x,i,output=0;
	scanf("%d",&x);
	for(i=1;i<=x;i++)
		output+=sum(i);
	printf("%d\n",output);
}