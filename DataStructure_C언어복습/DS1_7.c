#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n,*n1,*n2,*n3;
	scanf("%d",&n);
	n1=(int *)malloc(sizeof(int)*n);
	n2=(int *)malloc(sizeof(int)*n);
	n3=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",n1+i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",n2+i);
	}
	for(i=0;i<n;i++)
	{
		n3[i]=n1[i]+n2[n-i-1];
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",n3[i]);
	}
	printf("\n");
}