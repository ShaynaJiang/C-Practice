#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int id_num(char ch)
{
    switch(ch)
    {
        case 'A': return 10 ;break;   case 'P': return 23; break;
        case 'B': return 11 ;break;   case 'Q': return 24; break;
        case 'C': return 12 ;break;   case 'R': return 25; break;
        case 'D': return 13 ;break;   case 'S': return 26; break;
        case 'E': return 14 ;break;   case 'T': return 27; break;
        case 'F': return 15 ;break;   case 'U': return 28; break;
        case 'G': return 16 ;break;   case 'V': return 29; break;
        case 'H': return 17 ;break;   case 'W': return 32; break;
        case 'I': return 34 ;break;   case 'X': return 30; break;
        case 'J': return 18 ;break;   case 'Y': return 31; break;
        case 'K': return 19 ;break;   case 'Z': return 33; break;
        case 'L': return 20 ;break;   
        case 'M': return 21 ;break;   
        case 'N': return 22 ;break;   
        case 'O': return 35 ;break;
    }
}
main()
{ 	
    char id[11];
    id[10] = '\0';
    int i = 0, j, tmp, tmp1, total1,total2, total = 0;
  while(1)
  {
    printf("請輸入身分證號碼:");
    for(i=0; i<10; i++)
		scanf(" %c",&id[i]);

    if(id[0]<='z'&& id[0]>='a') 
		id[0]-=32;
	if(!(isalpha(id[0])))
		printf("格式錯誤，第一碼需為英文\n");
    
    if((id[1] != '1')&&(id[1] != '2'))
		printf("格式錯誤，第二碼需為1或2\n");
			
	for(j=1; j<10; j++){
		if(id[j]<48 || id[j]>57)
			printf("格式錯誤，後九碼需為數字\n");
	}
    tmp = id_num(id[0]);
    tmp1 = tmp/10;

    total = tmp1*1 + (tmp-10*tmp1)*9 + (id[1]-'0')*8 + (id[2]-'0')*7 + (id[3]-'0')*6 + (id[4]-'0')*5 + (id[5]-'0')*4 + (id[6]-'0')*3 + (id[7]-'0')*2 + (id[8]-'0')*1 + (id[9]-'0')*1;
    
    total1 = total/100;
    total2 = (total-100*total1)/10;

    if((total-100*total1-10*total2) == 0) 
    {	
	printf("合法，將加入串列\n");
	break;
    }
} 
}

