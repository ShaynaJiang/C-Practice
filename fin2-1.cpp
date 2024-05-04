#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i, p = 1, n;
    scanf("%d",&n);
    if(n != 50)
    {
        printf("Input erro!\n");
        exit (0);
    }
   for(i = 1; i <= n; i++){
       	p = p * i;     
   		printf("%d! = %d\n",i,p);
   }
   return 0;
}
