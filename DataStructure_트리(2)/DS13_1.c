#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int data, id;
	struct tree *left, *right;
}node;
void preorder(node *a)
{
	printf(" %d", a->data);
	if (a->left != NULL)
		preorder(a->left);
	if (a->right != NULL)
		preorder(a->right);
}
void inorder(node *a)
{
	if (a->left != NULL)
		inorder(a->left);
	printf(" %d", a->data);
	if (a->right != NULL)
		inorder(a->right);
}
void postorder(node *a)
{
	if (a->left != NULL)
		postorder(a->left);
	if (a->right != NULL)
		postorder(a->right);
	printf(" %d", a->data);
}
node *maketree(int i, int d, node *left, node *right)
{
	node *t;
	t = (node *)malloc(sizeof(node));
	t->data = d;
	t->id = i;
	t->left = left;
	t->right = right;
	return t;
}
int main()
{
	int ordernum, nodeid;
	node *a[8];
	a[7] = maketree(8, 80, NULL, NULL);
	a[6] = maketree(7, 130, NULL, NULL);
	a[5] = maketree(6, 120, a[6], a[7]);
	a[4] = maketree(5, 90, NULL, NULL);
	a[3] = maketree(4, 70, NULL, NULL);
	a[2] = maketree(3, 50, NULL, a[5]);
	a[1] = maketree(2, 30, a[3], a[4]);
	a[0] = maketree(1, 20, a[1], a[2]);
	scanf("%d %d", &ordernum, &nodeid);
	if (nodeid > 8)
		printf("-1");
	else
	{
		if (ordernum == 1)
			preorder(a[nodeid-1]);
		else if (ordernum == 2)
			inorder(a[nodeid-1]);
		else
			postorder(a[nodeid-1]);
	}
	printf("\n");
}