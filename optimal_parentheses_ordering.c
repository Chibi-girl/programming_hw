#include<stdio.h> 
#include<stdlib.h>

int a[10000][10000],ans[10000][10000],b[10000][10000];

void multiply(int u,int v,int y)
{
	for(int i=0;i<u;i++)
    	for(int j=0;j<y;j++)
    	{
    		int t=0;
            for(int k=0;k<v;k++)
                    t=t+(a[i][k])*(b[k][j]);
            ans[i][j]=t;
        }
}

void printParenthesis(int i, int j, int n,int *bracket, char *name) 
{ 
    if (i == j) 
    { 
        printf("%c", (*name)++); 
        return; 
    } 
    printf("("); 
    printParenthesis(i, *((bracket+i*n)+j), n, 
                     bracket, name); 
    printParenthesis(*((bracket+i*n)+j) + 1, j, 
                     n, bracket, name); 
    printf(")"); 
} 

void matrixChainOrder(int *p, int n) 
{ 
    int min_op[n][n];
    int ways[n-2];
    int bracket[n][n];  
    for (int i=1; i<n; i++) 
        min_op[i][i] = 0; 
    for (int L=2; L<n; L++) 
    { 
        for (int i=1; i<n-L+1; i++) 
        { 
            int j = i+L-1; 
            min_op[i][j] = 10000007;
            for (int k=i; k<=j-1; k++) 
            { 
                int op= min_op[i][k] + min_op[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (op<min_op[i][j]) 
                    min_op[i][j] =op,bracket[i][j] = k; 
                if(L==n-1)
                	ways[k-1]=op;
            } 
        } 
    } 
    char name = 'A';
    printf("Total number of scalar multiplications for all %d ways of parentheses ordering\n",n-2); 
  	for(int i=0;i<n-2;i++)
  		printf("%d ",ways[i]);
    printf("\nOptimal Parenthesization is : "); 
    printParenthesis(1, n-1, n, (int *)bracket, &name); 
    printf( "\nOptimal Cost is : %d",min_op[1][n-1]); 
} 

int main() 
{ 
	int n,x,y,l=1,u,v;
	printf("Enter number of matrices: ");
	scanf("%d",&n);
	int arr[n+1];
	printf("Enter order of %d matrices so that number of coulums of previous matrix = number of rows of next matrix\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		arr[i]=x;
		if(i==n-1)
			arr[n]=y;
	}
	printf("Enter the elements of Matrix %d of order %dx%d\n",l,arr[l-1],arr[l]);
	u=arr[l-1],v=arr[l];
    for(int i=0;i<u;i++)
    	for(int j=0;j<v;j++)
        	scanf("%d",&a[i][j]);
	for(int l=2;l<=n;l++)
	{
        printf("Enter the elements of Matrix %d of order %dx%d\n",l,arr[l-1],arr[l]);
        x=arr[l-1],y=arr[l];
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
            	scanf("%d",&b[i][j]);
        multiply(u,v,y);
        for(int i=0;i<u;i++)
        	for(int j=0;j<y;j++)
            	a[i][j]=ans[i][j];
      	v=y;
    }
    printf("The final matrix after multiplication in every order is same hence associative. The final matrix is:\n");
    for(int i=0;i<u;i++)
    {
    	for(int j=0;j<y;j++)
        	printf("%d ",a[i][j]);
        printf("\n");
    }
    matrixChainOrder(arr, n+1); 
    return 0; 
}







/*
OUTPUT:

Enter number of matrices: 4
Enter order of 4 matrices so that number of coulums of previous matrix = number of rows of next matrix
3 1
1 2
2 3
3 4
Enter the elements of Matrix 1 of order 3x1
1
2
3
Enter the elements of Matrix 2 of order 1x2
2 0
Enter the elements of Matrix 3 of order 2x3
2 3 -1
0 2 -1
Enter the elements of Matrix 4 of order 3x4
2 3 -1 0
2 3 1 1
0 1 2 2
The final matrix after multiplication in every order is same hence associative. The final matrix is:
20 28 -2 2 
40 56 -4 4 
60 84 -6 6 
Total number of scalar multiplications for all 3 ways of parentheses ordering
30 54 51 
Optimal Parenthesization is : (A((BC)D))
Optimal Cost is : 30

*/
