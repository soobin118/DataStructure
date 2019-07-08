#include<stdio.h>
void swap(int *ip,int *jp)
{
	int temp;
	temp=*ip;
	*ip=*jp;
	*jp=temp;
}
int main()
{
	int n,arr[50],i,j,k,*ip,*jp;
	scanf("%d",&n);
	for(k=0;k<n;k++)
		scanf("%d",arr+k);
	scanf("%d",&i);
	scanf("%d",&j);
	ip=&arr[i];
	jp=&arr[j];
	swap(ip,jp);
	for(k=0;k<n;k++)
	{
		printf("%d ",arr[k]);
	}
	printf("\n");
}