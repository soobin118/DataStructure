#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,**p,i,j,a=1,i1,j1;
	scanf("%d%d",&n,&m);
	p=(int **)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		p[i]=(int *)malloc(sizeof(int)*m);
	i1=0;j1=0;
	while(a<=n*m)
	{
		for(j=j1;j<m-j1;j++)
			p[i1][j]=a++;
		for(i=i1+1;i<n-i1;i++)
			p[i][m-j1-1]=a++;
		if(n>1 &&a<=n*m)
		{
		for(j=m-j1-2; j>=j1; j--)
			p[n-i1-1][j]=a++;
		}
		if(m>1&&a<=n*m)
		{
		for(i=n-i1-2;i>i1;i--)
			p[i][j1]=a++;
		}
		i1+=1;
		j1+=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf(" %d",p[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
		free(p[i]);
	free(p);
}