#include<stdio.h>
#include<stdlib.h>
struct set {
	int elem;
	struct set *next;
};
struct set *getnode()
{
	struct set *p;
	p = (struct set *)malloc(sizeof(struct set));
	p->next = NULL;
	return p;
}
struct set *insert(struct set *p, int item)
{
	struct set *t;
	if (p == NULL)
	{
		p = getnode();
		p->elem = item;
		p->next = NULL;
	}
	else {
		t = getnode();
		t->elem = item;
		t->next = NULL;
		p->next = t;
		p = t;
	}
	return p;
}
int isSubset(struct set *a, struct set *b)
{
	int setcnt = 0, allcnt = 0,flag=0;
	if (a == NULL)
		return 0;
	else if (b == NULL)
		return a->elem;
	else
	{
		while (a != NULL && b != NULL)
		{
			if (a->elem == b->elem)
			{
				a = a->next;
				b = b->next;
			}
			else
			{
				while (a->elem != b->elem)
				{
					b = b->next;
					if (b == NULL)
						break;
				}
				if (b == NULL)
				{
					flag = 1;
					return a->elem;
				}
			}
		}
		if (flag==0)
			return 0;
	}
}
int main()
{
	struct set *a=NULL, *b=NULL,*ap=NULL,*bp=NULL;
	int n, m, i,item;
	scanf("%d", &n);
	if (n == 0)
	{
		a = getnode();
		a = NULL;
		ap = a;
	}
	else
	{
		scanf("%d", &item);
		a = insert(a, item);
		ap = a;
		for (i = 1; i < n; i++)
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
		scanf("%d", &item);
		b = insert(b, item);
		bp = b;
		bp = b;
		for (i = 1; i < m; i++)
		{
			scanf("%d", &item);
			bp = insert(bp, item);
		}
	}
	printf("%d", isSubset(a, b));
}