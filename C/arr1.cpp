#include<stdio.h>
#include<stdlib.h>
void big_add(int * arr[])
{	
	int i, n, carry;	
	for(carry=i=0; i<n; i++)
	{	
		arr[i] = arr[i-1] + arr[i-2] + carry;
		carry = arr[i] / 10;
		arr[i] %= 10;
	 }
}
main()
{	while(1)
	{
		int n, j=0;
		int arr[10000] = {1,1};
		char ch[10000] = "";
		printf("Please input the number of generations (>0):");
		scanf("%d",&n);
		for(j=0; j<n; j++)
		{
			printf("第%d代數量:%10d\n",j+1,big_add(arr[j]));
		 }
		 if(n>0)
		 break;
	 }
	
	system("pause");
	return 0;	 
 }
