#include<stdio.h>
#include<stdlib.h>
typedef struct tree {
	int data, id;
	struct tree *left, *right;
}node;
node *maketree(int i, int d, node *l, node *r)
{
	node *t;
	t = (node *)malloc(sizeof(node));
	t->id = i;
	t->data = d;
	t->left = l;
	t->right = r;
	return t;
}
int *sum(node *a,int *r)
{
	*r += a->data;
	if (a->left != NULL)
		sum(a->left,r);
	if (a->right != NULL)
		sum(a->right, r);
	return r;
}
int main()
{
	int nodeid,r=0,*rp=&r;
	node *a[8];
	a[7] = maketree(8, 80, NULL, NULL);
	a[6] = maketree(7, 130, NULL, NULL);
	a[5] = maketree(6, 120, a[6], a[7]);
	a[4] = maketree(5, 90, NULL, NULL);
	a[3] = maketree(4, 70, NULL, NULL);
	a[2] = maketree(3, 50, NULL, a[5]);
	a[1] = maketree(2, 30, a[3], a[4]);
	a[0] = maketree(1, 20, a[1], a[2]);
	scanf("%d", &nodeid);
	if (nodeid > 8)
		printf("-1\n");
	else
	{
		rp = sum(a[nodeid - 1],rp);
		printf("%d\n", *rp);
	}
}