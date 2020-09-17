#include <stdio.h> 
#define len 10000 
int stackA[len],stackB[len]; 
int topA=-1,topB=-1;
void Push(int *stack,int val,int *top) 
{ 
	if(*top>=len) 
		printf("STACK OVERFLOW\n"); 
	else 
	{ 
		(*top)++; 
		stack[*top]=val; 
	} 
} 
int Pop(int *stack, int *top) 
{ 
	if(*top<0)  
		printf("EMPTY STACK! No VALUES LEFT TO POP\n"); 
	else  
		(*top)--;
} 
void sort_stack(int *st1,int *st2)
{
	while(topA>=0)
	{
		int temp=st1[topA];
		Pop(st1,&topA);
		while(topB>=0 && st2[topB]>temp)
		{
			int t=st2[topB];
			Pop(st2,&topB);
			Push(st1,t,&topA);
		}
		Push(st2,temp,&topB);
	}
	printf("\nThe sorted single stack containing elements of stack 1, stack 2, stack 3:\n");
	for(int i=0;i<=topB;i++)
		printf("%d ",st2[i]);
}
void input(int k)
{
int n,val; 
	printf("Enter number of values you wish to push in stack %d\n",k);
	scanf("%d",&n); 
	printf("Enter %d values for stack %d\n",n,k);
	for(int i=0;i<n;i++) 
	{ 
		scanf("%d",&val); 
		Push(stackA,val,&topA); 
	} 
}
int main() 
{ 
	input(1);
	input(2);
	input(3);
	sort_stack(stackA,stackB);
	return 0; 
} 
