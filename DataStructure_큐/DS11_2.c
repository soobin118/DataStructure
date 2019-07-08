#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	struct node *f, *r;
	int data;
};

void add_front(struct node *d, int n)
{
	struct node *t,*i;
	if (d->data == 0)
	{
		d->data = n;
	}
	else {
		t = (struct node *)malloc(sizeof(struct node));
		t->data = n;
		t->f = NULL;
		t->r = NULL;
		i = d;
		while (i->f != NULL)
		{
			i = i->f;
		}
		i->f = t;
		t->r = i;
	}
}
void add_rear(struct node *d, int n)
{
	struct node *t, *i;
	if (d->data == 0)
		d->data = n;
	else {
		t = (struct node *)malloc(sizeof(struct node));
		t->data = n;
		t->f = NULL;
		t->r = NULL;
		i = d;
		while (i->r != NULL)
			i = i->r;
		t->f = i;
		i->r = t;
	}
}
int delete_front(struct node *d)
{
	struct node *i;
	i = d;
	if (i->data == 0 && i->f == NULL)
	{
		printf("underflow\n");
		return 1;
	}
	else if (i->data != 0 && i->f == NULL)
	{
		i->data = 0;
	}
	else {
		while (i->f != NULL)
		{
			i = i->f;
		}
		i->data = 0;
		i = i->r;
		i->f = NULL;
	}
	return 0;
}
int delete_rear(struct node *d)
{
	struct node *i;
	i = d;
	if (i->data == 0 && i->r == NULL)
	{
		printf("underflow\n");
		return 1;
	}
	else if (i->data != 0 && i->r == NULL)
	{
		i->data = 0;
	}
	else {
		while (i->r != NULL)
			i = i->r;
		i = i->f;
		i->r = NULL;
	}
	return 0;
}
void print(struct node *d)
{
	struct node *i;
	i = d;
	while (i->f != NULL)
	{
		i = i->f;
	}
	while (i->r != NULL)
	{
		printf(" %d", i->data);
		i = i->r;
	}
	printf(" %d", i->data);
	printf("\n");
}
int main()
{
	struct node *d;
	int cnt, n, i,answer=0;
	char op[3];
	d = (struct node *)malloc(sizeof(struct node));
	d->f = NULL;
	d->data = 0;
	d->r = NULL;
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		getchar();
		scanf("%s", &op);
		if (strcmp(op,"AF")==0)
		{
			scanf("%d", &n);
			add_front(d, n);
		}
		else if (strcmp(op, "AR") == 0)
		{
			scanf("%d", &n);
			add_rear(d, n);
		}
		else if (strcmp(op, "DF") == 0)
		{
			answer=delete_front(d);
			if (answer == 1)
				break;
		}
		else if (strcmp(op, "DR") == 0)
		{
			answer=delete_rear(d);
			if (answer == 1)
				break;
		}
		else
			print(d);
	}
}