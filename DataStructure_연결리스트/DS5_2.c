#include<stdio.h>
#include<stdlib.h>
struct poly{
	int coef;
	int exp;
	struct poly *next;
};
void appendTerm(struct poly *h, int coef, int exp)
{
	struct poly *t,*last=h;
	t=(struct poly *)malloc(sizeof(struct poly));
	t->coef=coef;
	t->exp=exp;
	t->next=NULL;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=t;
}
struct poly *addPoly(struct poly a, struct poly b)
{
	struct poly result;
	struct poly *i,*j,*k;
	int sum;
	result.next=NULL;
	i=a.next;
	j=b.next;
	k=&result;
	while((i!=NULL) && (j!=NULL))
	{
		if(i->exp > j->exp)
		{
			appendTerm(k,i->coef,i->exp);
			i=i->next;
		}
		else if(i->exp < j->exp)
		{
			appendTerm(k,j->coef,j->exp);
			j=j->next;
		}
		else
		{
			sum=i->coef+j->coef;
			if(sum!=0)
			{
				appendTerm(k,sum,i->exp);
			}
			i=i->next;
			j=j->next;
		}
	}
	while(i!=NULL)
	{
		appendTerm(k,i->coef,i->exp);
		i=i->next;
	}
	while(j!=NULL)
	{
		appendTerm(k,j->coef,j->exp);
		j=j->next;
	}
	return &result;
}
int main()
{
	int i,n,m,coef,exp;
	struct poly x,y,*result;
	x.next=NULL;
	y.next=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&coef,&exp);
		appendTerm(&x,coef,exp);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&coef,&exp);
		appendTerm(&y,coef,exp);
	}
	result=addPoly(x,y);
	result=result->next;
	while(result!=NULL)
	{
		printf(" %d %d",result->coef,result->exp);
		result=result->next;
	}
}