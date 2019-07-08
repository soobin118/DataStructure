#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,**p,i,j,a=1;
	scanf("%d",&n);
	p=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		p[i]=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(j=0;j<n;j++)
				p[i][j]=a++;
		}
		else
		{
			for(j=n-1;j>=0;j--)
				p[i][j]=a++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf(" %d",p[i][j]);
		printf("\n");
	}
}