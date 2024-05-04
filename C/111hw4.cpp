#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
int id_num(char ch)
{
    switch(ch)
    {
        case 'A': case 'a': return 10 ;break;   case 'P': case 'p': return 23; break;
        case 'B': case 'b': return 11 ;break;   case 'Q': case 'q': return 24; break;
        case 'C': case 'c': return 12 ;break;   case 'R': case 'r': return 25; break;
        case 'D': case 'd': return 13 ;break;   case 'S': case 's': return 26; break;
        case 'E': case 'e': return 14 ;break;   case 'T': case 't': return 27; break;
        case 'F': case 'f': return 15 ;break;   case 'U': case 'u': return 28; break;
        case 'G': case 'g': return 16 ;break;   case 'V': case 'v': return 29; break;
        case 'H': case 'h': return 17 ;break;   case 'X': case 'x': return 30; break;
        case 'J': case 'j': return 18 ;break;   case 'Y': case 'y': return 31; break;
        case 'K': case 'k': return 19 ;break;   case 'W': case 'w': return 32; break;
        case 'L': case 'l': return 20 ;break;   case 'Z': case 'z': return 33; break;
        case 'M': case 'm': return 21 ;break;   case 'I': case 'i': return 34; break;
        case 'N': case 'n': return 22 ;break;   case 'O': case 'o': return 35; break; 
    }
}
int main()
{ 	
    char id[11];
    id[10] = '\0';
    int i, j, fir, fir2, sec, total = 0, is_repeat;	

	printf("請輸入統一證號:");
   	for(i=0; i<10; i++){
    	scanf(" %c",&id[i]);	
	}	
			
	if(!isalpha(id[0]) || !isalpha(id[1])){
    	printf("a1\n");
    	return 0;  
	}
	if(id[1] < 'A' || id[1] > 'D'){	
    	printf("a2\n");
	 	return 0;
    }

	for(j=2; j<10; j++){
		if(id[j] < '0' || id[j] > '9'){	
	    	printf("a3\n");
	    	return 0;
		}
	}
				
	fir = id_num(id[0]) / 10;
	fir2 = id_num(id[0]) % 10;
	sec = id_num(id[1]) % 10;
		 
	total = fir*1 + fir2*9 + sec*8 + (id[2]-'0')*7 + (id[3]-'0')*6 + (id[4]-'0')*5 + (id[5]-'0')*4 + (id[6]-'0')*3 + (id[7]-'0')*2 + (id[8]-'0')*1 + (id[9]-'0')*1;
		    
	if(total%10 == 0) {	
		printf("統一證號%s合格\n",id);
		return 0;
   	}
	else{
		printf("統一證號%s不合格\n",id);
		return 0;
  	} 
}



