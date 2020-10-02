#include<stdio.h>
#include<string.h>

int multiply(int r1,int c1,int r2, int c2,int m[][100][100],int a,int b,int c)
{ 
	for (int i=0;i<r1;i++) 
		for (int j=0;j<c2;j++) 
		{ 
			m[c][i][j] = 0; 
			for (int k=0;k<c1;k++)
				m[c][i][j]=m[c][i][j]+m[a][i][k]*m[b][k][j];
		}
    return r1*c1*c2; 
}

void disp(int r,int c,int m[][100][100],int a)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d ",m[a][i][j]);
        printf("\n");
    }
}

int main()
{
    int m[100][100][100];
    int d[8];
    for(int i=0,k=0;i<4;i++,k=k+2)
    {
    	char ch='A'+i;
    	printf("\nEnter the dimensions of the matrix %c : ",ch);
    	scanf("%d%d",&d[k],&d[k+1]);
    	printf("Enter the matrix %c : \n",ch);
    	for(int j=0; j<d[k]; j++)
       		for(int l=0; l<d[k+1]; l++)
            	scanf("%d",&m[i][j][l]);
    }
    int x=0,mini=1000000,pos=0;
    char str[5][100]={"((AB)C)D","(A(BC))D" ,"A((BC)D)" ,"A(B(CD))" ,"(AB)(CD)"};
    printf("\nFOR THE ORDERING : ((AB)C)D\n");
    x=multiply(d[0],d[1],d[2],d[3],m,0,1,4);
    x=x+multiply(d[0],d[3],d[4],d[5],m,4,2,5);
    x=x+multiply(d[0],d[5],d[6],d[7],m,5,3,6);
    printf("\nNo. of scalar multipliactions done = %d ",x);
    printf("\nFINAL MATRIX : \n");
    disp(d[0],d[7],m,6);
    if(x<mini)
    	mini=x,pos=0;
    printf("\nFOR THE ORDERING : (A(BC))D\n");
    x=multiply(d[2],d[3],d[4],d[5],m,1,2,7);
    x+=multiply(d[0],d[1],d[2],d[5],m,0,7,8);
    x+=multiply(d[0],d[5],d[6],d[7],m,8,3,9);
    printf("\nNo. of scalar multipliactions done = %d ",x);
    printf("\nFINAL MATRIX : \n");
    disp(d[0],d[7],m,9);
    	if(x<mini)
    		mini=x,pos=1;
    printf("\nFOR THE ORDERING : A((BC)D)\n");
    x=multiply(d[2],d[3],d[4],d[5],m,1,2,10);
    x+=multiply(d[2],d[5],d[6],d[7],m,10,3,11);
    x=x+multiply(d[0],d[1],d[2],d[7],m,0,11,12);
    printf("\nNo. of scalar multipliactions done = %d ",x);
    printf("\nFINAL MATRIX : \n");
    disp(d[0],d[7],m,12);
    	if(x<mini)
    		mini=x,pos=2;
    printf("\nFOR THE ORDERING : A(B(CD))\n");
    x=multiply(d[4],d[5],d[6],d[7],m,2,3,13);
    x+=multiply(d[2],d[3],d[4],d[7],m,1,13,14);
    x+=multiply(d[0],d[1],d[2],d[7],m,0,14,15);
    printf("\nNo. of scalar multipliactions done = %d ",x);
    printf("\nFINAL MATRIX : \n");
    disp(d[0],d[7],m,15);
    	if(x<mini)
    		mini=x,pos=3;
    printf("\nFOR THE ORDERING : (AB)(CD)\n");
    x=x+multiply(d[0],d[1],d[2],d[3],m,0,1,16);
    x+=multiply(d[4],d[5],d[6],d[7],m,2,3,17);
    x+=multiply(d[0],d[3],d[4],d[7],m,16,17,18);
    printf("\nNo. of scalar multipliactions done = %d ",x);
    printf("\nFINAL MATRIX : \n");
    disp(d[0],d[7],m,18);
   		if(x<mini)
    		mini=x,pos=4;
    printf("\nThe most efficient ordering is %s requiring %d scalar operations",str+pos,mini);
    return 0;
}
