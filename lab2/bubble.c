#include <stdio.h>
#include <stdlib.h>
void bubble (int number[],int n)
{
	int i,j,swap;
	for (i = 0 ; i < n - 1; i++)
  
    for (j = 0 ; j < n - i - 1; j++)
    
      if (number[j] < number[j+1]) 
      {
        swap       = number[j];
        number[j]   = number[j+1];
        number[j+1] = swap;
      }
    
  

  
}

int main()
{
int number[6],num,j,i;
// to eleminate duplicates
number[0] = rand()%100+1;
i=1;
while(i<6)
{

num=rand()%100+1;

j=0;	
while(j<i&& num!=number[j])
 j++;
 
if(j==i)
{

 
 number[i]=num;
 i++;
 
}

} 
for(i=0;i<6;i++)
printf("%d  ",number[i]);
bubble(number,6);
printf("\n");
for(i=0;i<6;i++)
printf("%d  ",number[i]);
return 0;
}
