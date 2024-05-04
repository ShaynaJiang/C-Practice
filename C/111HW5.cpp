#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int num(char ch)
{
    switch(ch)
    {
        case 'A': return 1 ;break;  
        case 'B': return 2 ;break;   
        case 'C': return 3 ;break;  
        case 'D': return 4 ;break;  
        case 'E': return 5 ;break;   
        case 'F': return 6 ;break;   
        case 'G': return 7 ;break;   
        case 'H': return 8 ;break;   
    }
}

main(){
  int cont;
  do{
	char loc[12], s='0';
	int i, j, is_repeat, x, y, pp, qq, t, v, u, w;
	do{
		printf("請輸入電力座標(最後兩碼若為空請輸入空格)－"); 
		for(i=0; i<11; i++){
			scanf("%c",&loc[i]);
		}
		fflush(stdin);
		//loc[11] = '\0';
		if(strlen(loc) != 9 && strlen(loc) != 11){
			printf("輸入格式錯誤。\n");
			continue;
		}
		if( !isalpha(loc[0]) && loc[0] != 'Z' && loc[0] != 'z' && loc[0] != 'S' && loc[0] != 's'){
			printf("輸入錯誤，第一碼需為英文字母。\n");
			continue;
		}
		if( !isdigit(loc[7]) && !isdigit(loc[8]) ){
			printf("輸入錯誤，第6、7碼需為數字。\n");
			continue;
		}	
		if(loc[5] <'A' || loc[5] > 'H' || loc[6] < 'A' || loc[6] > 'E'){
			printf("輸入錯誤，第6碼需為大寫A~H。\n");
			continue;
		}
		if(loc[6] < 'A' || loc[6] > 'E'){
			printf("輸入錯誤，第7碼需為大寫A~E。\n");
			continue;
		}
		if(loc[0] == 'Z' || loc[0] == 'z' || loc[0] =='S' || loc[0] == 's'){
			printf("目前不支援轉換金馬地區電力座標\n");
			continue;
		}
		if( !isdigit(loc[9]) && loc[9] != ' '){
			printf("第10碼需為數字或空格。\n");
			continue;
		}
		if( !isdigit(loc[10]) && loc[10] != ' '){
			printf("第11碼需為數字或空格。\n");
			continue;
		}
		if(!isdigit(loc[1]) && !isdigit(loc[2]) && !isdigit(loc[3]) && !isdigit(loc[4]) && !isdigit(loc[5])){
			printf("2~6碼需為數字。\n");
			continue;
		}
		else{
			break;
		}
	}while(1);
		
	pp = (loc[1]-'0')*10 + (loc[2]-'0');
	qq = (loc[3]-'0')*10 + (loc[4]-'0');
	t = loc[7]-'0';
	u = loc[8]-'0';
	
	if(loc[9] == ' '){
		v = 0;
	} 
	else{
		v = loc[9]-'0';
	}
	if(loc[10] == ' '){
		w = 0;
	}
	else{
		w = loc[10]-'0';	
	}
	if(loc[0] == 'x' || loc[0] == 'X' || loc[0] == 'y' || loc[0] == 'Y'){
		x = 275000 + 800*pp + 100*(num(loc[5])-1) + 10*t + v;
		y = 2614000+ 500*qq + 100*(num(loc[6])-1) + 10*u + w;
	}
	else{
		x = 250000 + 800*pp + 100*(num(loc[5])-1) + 10*t + v;
		y = 2500000+ 500*qq + 100*(num(loc[6])-1) + 10*u + w;
	}
	
	
	printf("T67二度分帶座標為－X：%d、Y：%d\n", x, y);
	//是否繼續	
	printf("是否繼續轉換，Y)是，N)否：");
	scanf(" %c", &cont);
	 
 }while(toupper(cont) == 'Y');

	
}  
