#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*p,s,*ps,i,temp1,temp2;
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	scanf("%d",&s);
	ps=(int *)malloc(sizeof(int)*n);
	for(i=0;i<s;i++)
		scanf("%d",&ps[i]);
	temp2=p[ps[0]];
	for(i=0;i<s-1;i++)
	{
		temp1=temp2;
		temp2=p[ps[i+1]];
		p[ps[i+1]]=temp1;
	}
	p[ps[0]]=temp1;
	for(i=0;i<n;i++)
		printf(" %d",p[i]);
	printf("\n");
	free(p);
	free(ps);
}