#include<stdio.h>
#include<math.h> 

void f(int k){
	int i; 
	double sum, num=1.0, t=1.0;
	for(i=1; i<=k; i++){
		t = t*num;
		num += 1; 
		sum += 1/t;
		//printf("%d\n",t);
	}
	printf("Result¡G%0.30f\n",sum);
}
int main(){
	int is_repeat = 0, k;
	
	do{
		printf("Input¡G");
		scanf(" %d",&k);
		if(k<0 || sizeof(k) != sizeof(int)){
			is_repeat = 1;
			printf("Erro\n");	
		}	
		else{
			is_repeat = 0;
		}
	}while(is_repeat);
	
	f(k);	
}
