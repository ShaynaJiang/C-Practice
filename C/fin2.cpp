#include<stdio.h>
int d[5001][2000] = { 0 };
int main()
{ 
  while(1)
  { 
	d[1][0] = 1;
	int i, j;
	for (i = 2; i <= 5000; i++)
	{
		for (j = 0; j < 2000; j++)
		{
			d[i][j] += d[i - 1][j] + d[i - 2][j];
		   	d[i][j + 1] += d[i][j] / 10;
		   	d[i][j] %= 10;
	 	 }
	 }
	
	int n=50;

for(i=1; i <= n  ; i++)
  {
    int j;
    /* multiply the value */
    for (j = 49; j >= 0; j--)
    {
      d[j]=d[j]*i;
    }
    /*進位留下個位數，其餘的加點前一位 */
    for (j = 49; j >= 0; j--)
    {
      if (d[j] >= 10)
          d[j-1]=d[j-1]+(d[j]/10);
          d[j]=d[j]%10;
    }
  }
	for(i=0; i< 50 ; i++)
  {
     printf("%d",d[i]);
  }
  printf("\n");

}
   }
	return 0;	
}

