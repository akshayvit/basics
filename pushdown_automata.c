#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define z0 '$'
#define _MAX 100000
#define false 0
#define true 1

struct stack
{
	int top;
	int max_size;
	char* arr;
};

struct stack* createstack(int n)
{
	struct stack* st=(struct stack*)malloc(sizeof(struct stack));
	st->top=-1;
	st->max_size=n;
	st->arr=(char*)malloc(sizeof(char)*st->max_size);
	return st;
}

void push(struct stack* st,char val)
{
	st->arr[++(st->top)]=val;
}

void pop(struct stack* st)
{
	st->top--;
}

int main()
{
	int tc;
	char s[100];
	int i,j;
	int temptc;
	struct stack* stk;
	printf("\nPushdown automata given by the 7 tuple: (Q,F,q0,Z0,T,S,Y)\n where Q=(q0,q1), \n F=q1,\nZ0=Top of stack,\nT=Stack Symbol,\nS=(a,b),\nY=Transition function");
	printf("Language is given by wcwR where wR=reverse(w)\n");
	printf("\nTransitions are given below:\n\n");
	printf("Y(q0,a,Z0)=(q0,aZ0)\n");
	printf("Y(q0,b,Z0)=(q0,bZ0)\n");
	printf("Y(q0,a,b)=(q0,ab)\n");
	printf("Y(q0,a,a)=(q0,aa)\n");
	printf("Y(q0,b,b)=(q0,bb)\n");
	printf("Y(q0,b,a)=(q0,ba)\n");
	printf("Y(q0,c)=(q1)\n");
	printf("Y(q1,a,a)=(q1,NULL)\n");
	printf("Y(q1,b,b)=(q1,NULL)\n");
	printf("Y(q1,a,b)=(D)\n");
	printf("Y(q1,b,a)=(D)\n\n");
	printf("D : Dead State\n\n");
	printf("Executing.....\n\n");
	printf("Enter the number of test cases or number of times you want to take the trial: ");
	scanf("%d",&tc);
	temptc=tc;
	printf("\n\n");
	while(tc--)
	{
	int flag=false;
	printf("Here is your number %d trial...\n\n",temptc-tc);
	stk=createstack(_MAX);
	push(stk,z0);
	printf("Enter a string that belongs to the language [wcv] where v=reverse(w) and w belongs to (a,b): ");
	scanf("%s",s);
	printf("\nOperating a pushdown automata for checking the acceptance of %s......\n",s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='c')
		{
			flag=true;
			continue;
		}
		if(!flag)
		{
			push(stk,s[i]);
		}
		else
		{
			if(stk->arr[stk->top]==s[i])
			{
			pop(stk);
		}
		else{
			break;
		}
		}
	}
	printf("Result:\n\n");
	stk->arr[stk->top]==z0 ? printf("Hurrah! The string %s is accepted by our Pushdown automata\n",s) : printf("Sorry! The string %s is not accepted by our Pushdown automata\n",s) ;
	stk->top=-1;
}
	printf("\nSuccesfully Done...\n\n");
	printf("Thank you!\n");
	
	return 0;
}
