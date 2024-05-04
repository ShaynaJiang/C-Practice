#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(){
	char **a, k[10] = "kitty";
	int n, i;
	a = (char**)malloc(sizeof(char*)*2);
	for(i=0; i<2; i++){
		*(a+i) = (char*)malloc(sizeof(char)*sizeof("abc"));
		strcpy(*(a+i),"abc");
	}

	
}
