#include<stdio.h> 
  
int main() 
{
	int n;
	printf("Enter size of matrices ");
	scanf("%d",&n);
	printf("Enter values for %dx%d sparse matrix 1\n",n,n);
	int val1[3][n*n/2],val2[3][n*n/2];
	int k1=0,k2=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int x;
			scanf("%d",&x);
				if(x!=0) 
                		val1[0][k1]=i,val1[1][k1]=j,val1[2][k1]=x,k1++; 
        }
    printf("Enter values for %dx%d sparse matrix 2\n",n,n);
    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int x;
			scanf("%d",&x);
				if(x!= 0) 
                		val2[0][k2]=i,val2[1][k2]=j,val2[2][k2]=x,k2++;
        }
	 	int result[4][k1+k2+2];
    	int c1=0,c2=0,len=0;
        while (c1<k1 && c2<k2)
        {
        	if (val1[0][c1]>val2[0][c2]||  (val1[0][c1]==val2[0][c2] && val1[1][c1]>val2[1][c2]))
            	result[0][len]=val2[0][c2],result[1][len]=val2[1][c2],result[2][len]=val2[2][c2],result[3][len]=0-val2[2][c2],len++,c2++; 
            else if (val1[0][c1]<val2[0][c2]||  (val1[0][c1]==val2[0][c2] && val1[1][c1]<val2[1][c2]))
				result[0][len]=val1[0][c1],result[1][len]=val1[1][c1],result[2][len]=val1[2][c1],result[3][len]=val1[2][c1],len++,c1++; 
            else
                result[0][len]=val1[0][c1],result[1][len]=val1[1][c1],result[2][len]=val1[2][c1]+val2[2][c2],result[3][len]=val1[2][c1]-val2[2][c2],len++,c1++,c2++;
        }  
        while (c1<k1)  
            result[0][len]=val1[0][c1],result[1][len]=val1[1][c1],result[2][len]=val1[2][c1],result[3][len]=val1[2][c1],len++,c1++; 
        while (c2<k2)
          	result[0][len]=val2[0][c2],result[1][len]=val2[1][c2],result[2][len]=val2[2][c2],result[3][len]=-val2[2][c2],len++,c2++;
        printf("ROW\tCOLUMN\tSUM\tDIFFERENCE\n");
        for(int i=0;i<len;i++)
        	printf("%d\t%d\t%d\t%d\n",result[0][i]+1,result[1][i]+1,result[2][i],result[3][i]);
return 0;
} 


/*OUTPUT:


Enter a value 6
Enter values for 6x6 sparse matrix
6 7 1 0 0 1
4 0 0 1 3 4 
8 7 6 0 0 0
0 0 0 0 0 1
0 0 0 2 0 0
1 0 1 3 0 0
Non negative values and their positions in matrix are
0 0 0 0 1 1 1 1 2 2 2 3 4 5 5 5 
0 1 2 5 0 3 4 5 0 1 2 5 3 0 2 3 
6 7 1 1 4 1 3 4 8 7 6 1 2 1 1 3 

*/
