#include<stdio.h>
void main()
{
	int N,i,j,sum[101],S,a;
	char stack[101]={NULL};
	
	scanf("%d ",&N);


	for(i=0; i<N; i++)
	{
		sum[0] = NULL;
		j=0;
		a=-1;
		
		gets(stack);

		while(1)
		{
			if(stack[j]==NULL)
				break;
			
			if(stack[j]=='*')
			{
				S = sum[a-1]*sum[a];
				sum[a-1] = S;
				sum[a] = NULL;
				a--;
				j++;
			}
			else if(stack[j]=='/')
			{
				S = sum[a-1]/sum[a];
				sum[a-1] = S;
				sum[a] = NULL;
				a--;
				j++;
			}
			else if(stack[j]=='+')
			{
				S = sum[a-1]+sum[a];
				sum[a-1] = S;
				sum[a] = NULL;
				a--;
				j++;
			}
			else if(stack[j]=='-')
			{
				S = sum[a-1]-sum[a];
				sum[a-1] = S;
				sum[a] = NULL;
				a--;
				j++;
			}
			else
			{
				a++;
				sum[a]= 1 + stack[j] - '1';
				j++;
			}
		}
		
		printf("%d\n",sum[0]);
	}

}