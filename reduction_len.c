#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char fname[1000],str[100],s[100]="";
scanf("%s",fname);
FILE *fptr;
if ((fptr = fopen(fname, "r")) == NULL)
{
	printf("Error! opening file");
	exit(1);
}
fscanf(fptr, "%[^\n]",str);
printf("String of 0-s and 1-s read:\n%s",str);
int n,z=0,tot=0;
scanf("%d",&n);
int freq[n+1];
char ch;
fclose(fptr);
for(int i=0;i<=n;i++)
	freq[i]=0;
for(int i=0;i<strlen(str);i++)
	if(str[i]=='0')
	{
		if(str[i-1]=='1')
		{
			freq[z]++;
			while(z>0)
				ch='A',strncat(s,&ch,1),z--;
		}
		z++;
		if(z==n)
			freq[z]++,z=0,ch='A'+n,strncat(s,&ch,1);
	}
	else if(i>0 && str[i]=='1' && str[i-1]=='0')
	{
		z++;
		if(z!=1)
			freq[z]++,ch='A'+z-1,strncat(s,&ch,1),z=0;
	}
	else
	{
		z++;
		if(z==n)
			freq[z]++,ch='A'+(n+1),strncat(s,&ch,1),z=0;
	}
	if(z!=0)
	{
		freq[z]++;
		if(str[strlen(str)-1]=='1')
			while(z>0)
				ch='A',strncat(s,&ch,1),z--;
		else
			ch='A'+n,strncat(s,&ch,1);
	}
printf("%s\n",s);
for(int i=1;i<=n;i++)
	tot=tot+i*freq[i];
printf("Actual length of string %d and length of string counted using frequencies is %d\n",(int)strlen(str),tot);
printf("Percentage reduction in length is %lf",((double)1-((double)strlen(s)/(double)strlen(str)))*100);
return 0;
}
