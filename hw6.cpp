#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>
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
	do{
		
	}

