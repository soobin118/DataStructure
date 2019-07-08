#include<stdio.h>
typedef struct
{
	int h,m,s;
}time;
time difference(time t1,time t2)
{
	time output;
	if(t2.s<t1.s)
	{
		t2.m-=1;
		t2.s+=60;
	}
	output.s=t2.s-t1.s;
	if(t2.m<t1.m)
	{
		t2.h-=1;
		t2.m+=60;
	}
	output.m=t2.m-t1.m;
	output.h=t2.h-t1.h;
	return output;
}
int main()
{
	time t1,t2,t3;
	scanf("%d %d %d",&t1.h,&t1.m,&t1.s);
	scanf("%d %d %d",&t2.h,&t2.m,&t2.s);
	t3=difference(t1,t2);
	if(t3.h==0&&t3.m==0&& t3.s==0)
		printf("0\n");
	else
		printf("%d %d %d\n",t3.h,t3.m,t3.s);
}