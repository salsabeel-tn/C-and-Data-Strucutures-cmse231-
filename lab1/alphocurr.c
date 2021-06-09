#include <stdio.h>
#include<string.h>


void occur(char alpha[],int n)
{
    int occ[100];
    int i;
    for(i=0;i<=25;i++)
    occ[i]=0;
    
    for(i=0;i<n;i++)
    occ[alpha[i] - 'A']=occ[alpha[i] - 'A']+1;
    
    for(i=0;i<=25;i++)
    printf("the letter %c occurs %d \n",i+65,occ[i] );
}
void main()
{
char str1[11],str2[11],str3[11];
printf("Enter 3 capital letter strings of length 10 characters each:");
gets(str1);
gets(str2);
gets(str3);
strcat(str1,str2);
strcat(str1,str3);
occur(str1,strlen(str1));
}