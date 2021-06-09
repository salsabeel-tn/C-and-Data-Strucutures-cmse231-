#include <stdio.h>
#include <stdlib.h>

 

float average(int num[],int n)
{ int i,s=0;
float av;

 

    for(i=0;i<n;i++)
    s=s+num[i];
    av=(float) s/n;
    return av;
}
void greater(int num[],int n,int av)
{
    int i;
    for (i=0;i<n;i++)
    if (num[i]>av)
    printf("%d\t",num[i]);
}
void occur(int num[],int n)
{
    int occ[100];
    int i;
    for(i=0;i<100;i++)
    occ[i]=0;
    
    for(i=0;i<n;i++)
    occ[num [i]-1]=occ[num [i]-1]+1;
    
    for(i=0;i<100;i++)
    printf("the number %d occurs %d \n",i+1,occ[i] );
}
void main()
{
int number[10];
int i=0;
float AV;
do
{
number[i] = rand()%100+1;
printf("%d\t",number[i]);
i++;
}while(i !=10 );

 

AV=average(number,10);
printf("\nthe average=%.2f\n",AV);
greater(number,10,AV);
printf("\n");
occur(number,10);

 


}
