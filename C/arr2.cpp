#include<stdio.h>
#include<stdlib.h>
int main()
{	while(1)
	{
		int n, i, j=0;
		int arr[10000] = {1,1};
		char ch[10000] = "";
		printf("Please input the number of generations (>0):");
		scanf("%d",&n);
		for(i=1; i<n; i++)
		{
			arr[i] = arr[i-1] + arr[i-2];
		 }
		for(j=0; j<n; j++)
		{
			printf("第%d代數量:%10d\n",j+1,arr[j]);
		 }
		if(n>0)
		break;
	 }
		system("pause");
	 return 0;	 
 }
