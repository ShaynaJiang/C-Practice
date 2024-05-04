#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>
#define red "\033[0;32;31m"
#include <ctype.h>


int main(){
	char a[43][6]= {"Anita", "Beryl", "Chloe", "Doris", "Emily", "Flora", "Grace", "Helga", "Irene", "Josie", 
				  "Kathy", "Lorna", "Madge", "Naomi", "Olive", "Pancy", "Rhoda", "Sonia", "Terri", "Viola", 
				  "Wendy", "Alvin", "Basil", "Clyde", "Duane", "Elmer", "Floyd", "Giles", "Homer", "Irwin", 
				  "Jamie", "Keith", "Lewis", "Miles", "Nicky", "Ozzie", "Percy", "Reule", "Simon", "Teddy", 
				  "Urban", "Vince", "Willy"};
	
	srand(time(NULL));
	
	int count = 0, is_repeat = 0;
	int r = rand()%43;
	//printf("%s",a[r]);
	char b[6];
        int i, j;
	while(1){
		do{
			printf("Please guess:");
        		scanf("%s", &b);
			for(i=0; i<5; i++){
			
				if(strlen(b)>5||!(isalpha(b[i]))){
					printf(red"Input error!\n");
					is_repeat = 1;
					break;}
				else{
					is_repeat = 0;
					break;}		
			}
		}while(is_repeat);

		for(j=0; j<5; j++){	
			a[r][j] = toupper (a[r][j]);
               		b[j] = toupper (b[j]);
		}
		do{     
			for(i=0; i<5; i++){
				if(a[r][i] == b[i]){
					printf("\033[30;42m%c\033[m",b[i]);
                                	count+=1;
				}
				else if (b[i] == a[r][i+1%5] || b[i] ==  a[r][i+2%5] || b[i] == a[r][i+3%5] || b[i] == a[r][i+4%5]){
					printf("\033[30;43m%c\033[m",b[i]);
				}
				else if (b[i] == a[r][i-1%5] || b[i] ==  a[r][i-2%5] || b[i] == a[r][i-3%5] || b[i] == a[r][i-4%5]){
					printf("\033[30;43m%c\033[m",b[i]);
				}
				else{
					printf("\033[30;47m%c\033[m",b[i]);
				}
			}
			printf("\n");
		}while(strlen(b)==5&&(isalpha(b[6])));
		if(count == 5){
			printf("\033[30;41mBINGO\033[m\n");
			break;
		}
	}			
}


