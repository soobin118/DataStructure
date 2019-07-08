#include<stdio.h>
#include<stdlib.h>
void print(int *s, int qsize)
{
	int i;
	for (i = 0; i < qsize; i++)
	{
		printf(" %d", s[i]);
	}
	printf("\n");
}
int insertion(int *s, int data, int *head, int *tail, int qsize)
{
	if (*tail-*head==qsize-1)
	{
		printf("overflow");
		print(s, qsize);
		return 1;
	}
	else
	{
			*tail += 1;
			s[(*tail)%qsize] = data;
			return 0;
	}
}
int deletion(int *s, int *head, int *tail)
{
	if (*tail - *head == 0)
	{
		printf("underflow");
		return 1;
	}
	else {
		*head += 1;
		s[*head] = 0;
		return 0;
	}
}
int main()
{
	int qsize,n,i,*s,data,h=0,t=0,*head=&h,*tail=&t,answer=0;
	char op;
	scanf("%d%d",&qsize, &n);
	s = (int *)malloc(sizeof(int)*qsize);
	for (i = 0; i < qsize; i++)
		s[i] = 0;
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &op);
		if (op == 'I')
		{
			scanf("%d", &data);
			answer=insertion(s, data, head, tail,qsize);
			if (answer == 1)
				break;
		}
		else if (op == 'D')
		{
			answer=deletion(s, head, tail);
			if (answer == 1)
				break;
		}
		else
		{
			print(s, qsize);
		}
	}
}