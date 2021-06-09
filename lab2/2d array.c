#include<stdio.h>
int main()
{
	float x[3][4]={{13.5, 24.88, 66.28, 30.0},{2.84, 412.15, 13.2, 9.9},{15.5, 38.89, 12.5, 16.18}};
	float y[12];
	int i,j,k;
	k=0;
	for (i=0;i<4;i++)
		for(j=0;j<3;j++)
			{
				y[k]=x[j][i];
				k++;
			}
	for (i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
				printf("%.2f ",x[i][j]);
		printf("\n");
			
    }
	printf("\n");		
	for (k=0;k<12;k++)
		printf("%.2f ",y[k]);	
	return 0;
}
