#include<stdio.h>
int d[5001][2000] = { 0 };
int main()
{ 
	d[1][0] = 1;

	int i, j, p=1;
	for (i = 2; i <= 2000; i++)
	{
		for (j = 2; j < 2000; j++)
		{
			p = p * i;
			//d[i][j] = p;
		   	d[i][j + 1] += p / 10;
		   	d[i][j] = p%10;
	 	 }
	 }
	
	int n = 50;

	
	for(j=1; j<51; j++)
	{ 	
		printf("%d! = ",j);
		for (i = 1999; i >= 0; i--)
		{	
	   		if (d[j][i] != 0)
	    		break;
	 	}
		if (i == -1)
	   		printf("0");
		else
			for (; i>=0; i--)
	   		{  
				printf("%d", d[j][i]);
			}
	printf("\n");
 }

	return 0;	
}

