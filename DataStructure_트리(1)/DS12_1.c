#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node *left, *right;
	int data;
}tree;
tree *makeTree(int n, tree *l, tree *r)
{
	tree *a;
	a = malloc(sizeof(tree));
	a->data = n;
	a->left = l;
	a->right = r;
	return a;
}
int main()
{
	tree *f[8] = { NULL };
	int n;
	f[7] = makeTree(80, 0, 0);
	f[6] = makeTree(130,0,0);
	f[5] = makeTree(120, f[6], f[7]);
	f[4] = makeTree(90, 0, 0);
	f[3] = makeTree(70, 0, 0);
	f[2] = makeTree(50, 0, f[5]);
	f[1] = makeTree(30, f[3], f[4]);
	f[0] = makeTree(20, f[1], f[2]);
	scanf("%d", &n);
	if (n > 8)
		printf("-1\n");
	else
	{
		printf("%d", f[n - 1]->data);
		if (f[n - 1]->left != NULL)
			printf(" %d", (f[n - 1]->left)->data);
		if (f[n - 1]->right != NULL)
			printf(" %d", (f[n - 1]->right)->data);
		printf("\n");
	}
}