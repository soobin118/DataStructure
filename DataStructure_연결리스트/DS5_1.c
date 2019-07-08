#include<stdio.h>
#include<stdlib.h>

struct node{
   char ele;
   struct node *pre;
   struct node *next;
};

int n=0;

void initList(struct node *H, struct node *T)
{
   H->pre=NULL;
   H->next=T;
   T->pre=H;
   T->next=NULL;
}

char get_entry(struct node *H, int position)
{
   int i;
   struct node *q;

   if(position>n)
   {
      printf("invalid position");
      return '\n';
   }

   q=H;
   for(i=1 ; i<=position ; i++)
   {
      q=q->next;
   }

   return q->ele;
}

void add(struct node *H, int position, int ele)
{
   struct node *r;
   struct node *q;
   int i;

   if(position>n+1)
   {
      printf("invalid position\n");
      return;
   }

   q=H;
   for(i=1 ; i<position ; i++)
   {
      q=q->next;
   }

   r = (struct node*)malloc(sizeof(struct node)); // 货肺款 畴靛 积己
   r->ele=ele;
   r->pre=q;
   r->next=q->next;

   (q->next)->pre=r; //error
   q->next=r;
   n+=1;
}

void _delete(struct node *H, int position)
{
   int i;
   struct node *q;

   if(position>n)
   {
      printf("invalid position\n");
      return;
   }
   
   q=H;
   for(i=1 ; i<=position ; i++)
   {
      q=q->next;
   }

   (q->pre)->next = q->next;
   (q->next)->pre = q->pre;   

   free(q);
   n-=1;
}

void print(struct node *H)
{
   int i;
   struct node *q=H;
   for(i=1 ; i<=n ; i++)
   {
      q=q->next;
      printf("%c",q->ele);
   }
   printf("\n");
   //getchar();
}

int main()
{
   struct node H,T;
   int num,position,i;
   char funtion,ele;

   initList(&H,&T);

   scanf("%d",&num);

   for(i=0 ; i<num; i++)
   {
      getchar();
      scanf("%c",&funtion);
      //getchar();
      switch(funtion)
      {
      case 'A':
         scanf("%d %c",&position,&ele);
         add(&H,position,ele); break;
      case 'D':
         scanf("%d",&position);
         _delete(&H,position); break;
      case 'G':
         scanf("%d",&position);
         printf("%c\n",get_entry(&H,position)); break;
      case 'P':
         print(&H); break;
      }
   }

   return 0;
}