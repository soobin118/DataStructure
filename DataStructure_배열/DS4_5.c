#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,**p,m,a=1,k=0,l=0;
	scanf("%d%d", &n,&m);
	p = (int **)malloc(sizeof(int *)*n);
	for (i = 0; i < n; i++)
	{
		p[i] = (int *)malloc(sizeof(int)*m);
	}
	i = 0;
	j = 0;
	while (1)
	{
		p[i][j] = a++;
		if (a > n*m)
			break;
		if (n == 1)
		{
			j++;
		}
		else if (m == 1)
		{
			i++;
		}
		else {
			if (j < m - 1 && j>0)
			{
				if (i == 0)
				{
					i++;
					j--;
				}
				else if (i != n - 1)
				{
					i++;
					j--;
				}
				else if(i==n-1 && l<m-1)
				{
					i = k;
					j = ++l;
				}
				else if (i == n - 1 && l == m - 1)
				{
					i = k;
					j = l;
				}
			}
			else if (j == 0)
			{
				if (l != m - 1)
				{
					i = k;
					j = ++l;
				}
				else
				{
					i = k;
					j = l;
				}
			}
			else if (j == m - 1)
			{
				k++;
				if (i != n - 1)
				{
					i++;
					j--;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}
}