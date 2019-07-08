#include<stdio.h>
#include<stdlib.h>
int main()
{
	int j,temp,i,n,*p,s,**sp;
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	scanf("%d",&s);
	sp=(int **)malloc(sizeof(int *)*s);
	for(i=0;i<s;i++)
		sp[i]=(int *)malloc(sizeof(int)*2);
	for(i=0;i<s;i++)
		scanf("%d%d",&sp[i][0],&sp[i][1]);
	for(i=0;i<s;i++)
	{
		for(j=0;j<=(sp[i][1]-sp[i][0])/2;j++)
		{
			temp=p[sp[i][0]+j];
			p[sp[i][0]+j]=p[sp[i][1]-j];
			p[sp[i][1]-j]=temp;
		}
	}
	for(i=0;i<n;i++)
		printf(" %d",p[i]);
	printf("\n");
	free(p);
	for(i=0;i<s;i++)
		free(sp[i]);
	free(sp);
}