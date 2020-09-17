#include <stdio.h> 
#define len 1000 
int stackA[len],stackB[len],stackC[len]; 
int topA=0,topB=0,topC=0;
void Push(int *stack,int val,int *top) 
{ 
	if(*top>=len) 
		printf("STACK OVERFLOW\n"); 
	else 
	{ 
		stack[*top]=val; 
		(*top)++; 
	} 
} 
int Pop(int *stack, int *top) 
{ 
	if(*top<0)  
		printf("EMPTY STACK! No VALUES LEFT TO POP\n"); 
	else 
	{ 
		int x=stack[(*top)]; 
		(*top)--; 
		return x; 
	} 
} 
 
void duplicate_stack(int *stack) 
{ 
	int t=0;
	printf("Original stack at address %p:\n",&stackA);
	while(t<topA)
		printf("%d ",stack[t]),t++;
	topA=topA-1;
	while(topA>=0)   
		Push(stackB,Pop(stack,&topA),&topB); 
	topB=topB-1;
	while(topB>=0) 
		Push(stackC,Pop(stackB,&topB),&topC); 
	t=0;
	printf("\nDuplicated stack at address %p:\n",&stackC);
	while(t<topC)
		printf("%d ",stackC[t]),t++;
} 
int main() 
{ 
	int n,val; 
	printf("Enter number of values you wish to push in stack: ");
	scanf("%d",&n); 
	for(int i=0;i<n;i++) 
	{ 
		scanf("%d",&val); 
		Push(stackA,val,&topA); 
	} 
	duplicate_stack(stackA); 
	return 0; 
} 
