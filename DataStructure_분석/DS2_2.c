#include<stdio.h>
#include<stdlib.h>
int mostones(int **p,int n)
{
	int i,j,k=0,output=0;
	for(i=0;i<n;i++)
	{
		for(j=k;j<n;j++)
		{
			if(p[i][j]==0)
			{
				if(j>k)
				{
					output=i;
				}
				k=j;
				break;
			}
			else if(j==n-1)
			{
				output=i;
				break;
			}
		}
		if(j==n-1)
			break;
	}
	return output;
}
int main()
{
	int n,i,j,answer;
	int **s;
	scanf("%d",&n);
	s=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		s[i]=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&s[i][j]);
		}
	answer=mostones(s,n);
	printf("%d\n",answer);
}