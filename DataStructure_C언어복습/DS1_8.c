#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char name[8];
	int s1,s2,s3;
	double average;
}student;
int main()
{
	int n,i,sum=0;
	student *s;
	scanf("%d",&n);
	s=(student *)malloc(sizeof(student)*n);
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d %d",s[i].name,&s[i].s1,&s[i].s2,&s[i].s3);
	}
	for(i=0;i<n;i++)
	{
		sum=s[i].s1+s[i].s2+s[i].s3;
		s[i].average=sum/3.0;
	}
	for(i=0;i<n;i++)
	{
		printf("%s ",s[i].name);
		printf("%.1f",s[i].average);
		if(s[i].s1>=90 || s[i].s2>=90 || s[i].s3>=90)
			printf(" GREAT");
		if(s[i].s1<70 ||s[i].s2<70 ||s[i].s3<70)
			printf(" BAD");
		printf("\n");
	}
}