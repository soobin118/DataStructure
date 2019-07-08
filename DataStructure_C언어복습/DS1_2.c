#include<stdio.h>
void abc(int *t)
{
	int i,j,temp;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(t[j]<t[j+1])
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}
}
int main()
{
	int teninters[10],i,*t=teninters;
	for(i=0;i<10;i++)
	{
		scanf("%d",&teninters[i]);
	}
	abc(t);
	for(i=0;i<10;i++)
		printf("%d ",t[i]);
}