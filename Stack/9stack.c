#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char *stack,int *head, int *tail,  char c,int n)
{
	if ((*tail) - (*head) == n-1)
	{
		printf("Stack FULL\n");
		return 0;
	}
	if ((*tail)==-1)
	{
		*tail += 1;
		stack[*tail] = c;
	}
	else
	{
		(*tail) += 1;
		stack[*tail] = c;
	}
}
char pop(char *stack, int *head, int *tail)
{
	int c;
	if ((*tail)== -1)
	{
		printf("Stack Empty\n");
		return '0';
	}
	else
	{
		c=stack[*tail];
		(*tail) -= 1;
		return c;
	}
}
void peek(char *stack, int *head, int *tail)
{
	if ((*tail)== -1)
	{
		printf("Stack Empty\n");
		return 0;
	}
	else
	{
		printf("%c\n", stack[*tail]);
	}
}
void duplicate(char *stack, int *head, int *tail,int n)
{
	char c;
	c = pop(stack, head, tail);
	push(stack, head, tail, c, n);
	push(stack, head, tail, c, n);
}
void upRotate(char *stack, int *head, int *tail,int n)
{
	char tmp;
	int i;
	tmp = stack[*tail];
	for (i = 1; i <= n-1; i++)
	{
		stack[(*tail) - i+1]=stack[(*tail) - i];
	}
	stack[(*tail) - n + 1] = tmp;
}
void downRotate(char *stack, int *head, int *tail, int n)
{
	char tmp;
	int i;
	if (n > (*tail) + 1)
	{
		return 0;
	}
	tmp = stack[(*tail)-n+1];
	for (i = n-2; i >= 0; i--)
	{
		stack[(*tail) - i - 1] = stack[(*tail) - i];
	}
	stack[*tail] = tmp;
}
void print(char *stack, int *tail)
{
	int i;
	for (i = (*tail); i >= 0; i--)
	{
		printf("%c", stack[i]);
	}
	printf("\n");
}
int main()
{
	int popr,i,cnt,stacksize,t=-1,h=0, *tail, *head,rotn;
	char *stack,op[6],c;
	tail = &t;
	head = &h;
	scanf("%d", &stacksize);
	stack = (char *)malloc(sizeof(stacksize*sizeof(char)));
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		scanf(" %s", op);
		if (strcmp(op, "PUSH") == 0)
		{
			scanf(" %c", &c);
			push(stack, head, tail, c, stacksize);
		}
		else if (strcmp(op, "POP") == 0)
		{
			popr=pop(stack, head, tail);
		}
		else if (strcmp(op, "PEEK") == 0)
		{
			peek(stack, head, tail);
		}
		else if (strcmp(op, "DUP") == 0)
		{
			duplicate(stack, head, tail, stacksize);
		}
		else if (strcmp(op, "UpR") == 0)
		{
			scanf("%d", &rotn);
			upRotate(stack, head, tail, rotn);
		}
		else if (strcmp(op, "DownR") == 0)
		{
			scanf("%d", &rotn);
			downRotate(stack, head, tail, rotn);
		}
		else
		{
			print(stack, tail);
		}
	}
}