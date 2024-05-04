#include<stdio.h>

int d[5001][2000] = { 0 };

int main()
{ 
  while(1)
  { 
	d[1][0] = 1;
	int i, j;
	for (i = 2; i <= 5000; i++)	{
		for (j = 0; j < 2000; j++){
			//將數量一位一位數存入陣列
			d[i][j] += d[i - 1][j] + d[i - 2][j];
		   	d[i][j + 1] += d[i][j] / 10;
		   	d[i][j] %= 10;
	 	 }
	 }
	
	int n, is_repeat;
	do{
		printf("Please input the numbers of generations(1-500):");
		scanf("%d", &n);
		//輸入數量判斷	
		if(n<0 || n>500){
			printf("輸入錯誤\n");
			is_repeat = 1;
		}
		else{
			is_repeat = 0;
		}
	}while(is_repeat);
	
	for(j=1; j<n+1; j++)
	{ 	
		printf("第%d代數量：",j);
		//從第一個不為0的數開始輸出
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
	break;
   }
	return 0;	
}


