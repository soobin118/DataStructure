#include<stdio.h>
#include<stdlib.h>
int *prefixAverages1(int *p,int n)
{
	int i,j,sum=0,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<=i;j++)
		{
			sum=sum+p[j];
		}
		a[i]=sum/(i+1.0)+0.5;
	}
	return a;
}
int *prefixAverages2(int *p,int n)
{
	int j,sum=0,*a;
	a=(int *)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
		{
			sum=sum+p[j];
			a[j]=sum/(j+1.0)+0.5;
		}
	return a;
}
int main()
{
	int n,i,*p,*a1,*a2;
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	a1=prefixAverages1(p,n);
	a2=prefixAverages2(p,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a1[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a2[i]);
	}
}