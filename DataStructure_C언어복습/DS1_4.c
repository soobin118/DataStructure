#include<stdio.h>
#include<string.h>
void shift_left(char *str,int n)
{
	int i;
	char temp;
	temp=str[0];
	for(i=1;i<n;i++)
	{
		str[i-1]=str[i];
	}
	str[n-1]=temp;
}
int main()
{
	char str[100];
	int n,i;
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		printf("%s\n",str);
		shift_left(str,n);
	}
}