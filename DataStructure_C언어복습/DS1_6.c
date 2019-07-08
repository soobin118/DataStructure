#include<stdio.h>
typedef struct
{
	char name[10];
	int score;
}student;
int average(student *std)
{
	int i,sum=0;
	for(i=0;i<5;i++)
		sum+=std[i].score;
	return sum/5;
}
void print_less_than_average_student(student std,int ave)
{
	if(ave>=std.score)
	{
		printf("%s\n",std.name);
	}
}
int main()
{
	student std[5];
	int ave,i;
	for(i=0;i<5;i++)
	{
		scanf("%s",std[i].name);
		scanf("%d",&std[i].score);
	}
	ave=average(std);
	for(i=0;i<5;i++)
	{
		print_less_than_average_student(std[i],ave);
	}
}