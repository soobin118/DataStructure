#include<stdio.h>
#include<string.h>
int par(char exp)
{
		if (exp == '{')
			return 1;
		else if (exp == '[')
			return 2;
		else if (exp == '(')
			return 3;
		else if (exp == '}')
			return 4;
		else if (exp == ']')
			return 5;
		else if (exp == ')')
			return 6;
		else
			return 0;
}
void pop(char *stack, int *head, int *tail)
{
	(*tail) -= 1;
}
void push(char *stack, int *head, int *tail,char c)
{
	if ((*tail) == -1)
	{
		(*tail) += 1;
		stack[*tail] = c;
	}
	else
	{
		if (par(c) - par(stack[*tail]) == 3)
		{
			pop(stack,head, tail);
		}
		else
		{
			(*tail) += 1;
			stack[*tail] = c;
		}
	}
}
int main()
{
	int i,cnt=0,n,t=-1,h=0,*tail,*head;
	char exp[1001],stack[1000];
	tail = &t;
	head = &h;
	gets(exp);
	n = strlen(exp);
	for (i = 0; i < n; i++)
	{
		if (par(exp[i]) == 0)
			continue;
		else
		{
			push(stack, head, tail, exp[i]);
			cnt++;
		}
	}
	if ((*tail) != -1)
	{
		printf("Wrong_%d\n", cnt);
	}
	else
		printf("OK_%d\n", cnt);
}