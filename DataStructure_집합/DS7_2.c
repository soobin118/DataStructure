#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int elem;
	struct node *next;
}set;
set* getnode()
{
	set *p;
	p = (set *)malloc(sizeof(set));
	p->next = NULL;
	return p;
}
set* insert(set *a, int item)
{
	set *t;
	if (a == NULL)
	{
		a = getnode();
		a->elem = item;
		a->next = NULL;
	}
	else
	{
		t = getnode();
		t->elem = item;
		t->next = NULL;
		a->next = t;
		a = t;
	}
	return a;
}
void _union(set *a, set *b)
{
	if (a == NULL && b == NULL)
		printf(" 0");
	else if(a!= NULL && b!=NULL)
	{
		a = a->next;
		b = b->next;
		while (a != NULL && b != NULL)
		{
			if (a->elem == b->elem)
			{
				printf(" %d", a->elem);
				a = a->next;
				b = b->next;
			}
			else
			{
				if (a->elem < b->elem)
				{
					printf(" %d", a->elem);
					a = a->next;
				}
				else
				{
					printf(" %d", b->elem);
					b = b->next;
				}
			}
		}
	}
	if (a == NULL && b != NULL)
	{
		if (b->elem == 0)
			b = b->next;
		while (b != NULL)
		{
			printf(" %d", b->elem);
			b = b->next;
		}
	}
	if (a != NULL && b == NULL)
	{
		if(a->elem==0)
			a = a->next;
		while (a != NULL)
		{
			printf(" %d", a->elem);
			a = a->next;
		}
	}
	printf("\n");
}
void intersect(set *a, set *b)
{
	if (a == NULL || b == NULL)
		printf(" 0");
	else
	{
		a = a->next;
		b = b->next;
		while (a != NULL && b != NULL)
		{
			if (a->elem == b->elem)
			{
				printf(" %d", a->elem);
				a = a->next;
				b = b->next;
			}
			else
			{
				if (a->elem < b->elem)
					a = a->next;
				else
					b = b->next;
			}
		}
	}
	printf("\n");
}
int main()
{
	int i, n, m,item;
	set *a = NULL, *b = NULL, *ap = NULL, *bp = NULL;
	scanf("%d", &n);
	if (n == 0)
	{
		a = getnode();
		a = NULL;
		ap = a;
	}
	else {
		a = getnode();
		a->elem = 0;
		ap = a;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &item);
			ap = insert(ap, item);
		}
	}
	scanf("%d", &m);
	if (m == 0)
	{
		b = getnode();
		b = NULL;
		bp = b;
	}
	else {
		b = getnode();
		b->elem = 0;
		bp = b;
		for (i = 0; i < m; i++)
		{
			scanf("%d", &item);
			bp = insert(bp, item);
		}
	}
	_union(a, b);
	intersect(a, b);
}
