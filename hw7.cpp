#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct{
	char str[50];
	int cnt;
}Str;

int main(){
	char tmp[50];
	FILE *fp;
	Str words[200];
	int num = 0;
	int i,j,new = 1;
	
	fp = fopen("/tmp/TaiwanTravelGuide.txt","r");
	
	while(fscanf(fp,"%s",tmp) != EOF){
		new = 1;
		for(i=0; i<num; i++){
			if(strcmp(tmp, words[i].str) == 0){
				new = 0;
				words[i].cnt++;
			}
		}
		if(new){
			for(j=0; tmp[j]!='\0'; j++){
				words[num].str[j] = tmp[j];
			}
			words[num].str[j] = '\0';
			words[num++].cnt = 1;
		}
	}
	printf("Times of the words show are:\n");
	for(i=num-1; i>=0; i--){
		printf("%-10s %2d\n", words[i].str, words[i].cnt);
	}
	fclose(fp);
	return 0;
}
