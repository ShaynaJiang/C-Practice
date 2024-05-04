#include<stdio.h>
main(){
		char bir1[11], bir2[11], bir3[11];
		int i, count1=0, count2=0, count3=0, count4=0;
		printf("Please input A's birthday(2023/03/18)：");
		scanf(" %s",bir1);
		printf("Please input B's birthday(2023/03/18)：");
		scanf(" %s",bir2);
		printf("Please input C's birthday(2023/03/18)：");
		scanf(" %s",bir3);
		for(i=5;i<10;i++)
			if(bir1[i] == bir2[i]) //判斷A和B生日一樣 
				count1 += 1;
		for(i=5;i<10;i++)			
			if(bir1[i] == bir3[i]) //判斷A和C生日一樣 
				count2 += 1;
		for(i=5;i<10;i++)		
			if(bir2[i] == bir3[i]) //判斷B和C生日一樣 
				count3 += 1;

		if(count1 == 5 && count2!=5 && count3!=5)
			printf("A's birthday(%s) and B's birthday(%s) are the same day.",bir1,bir2);
		else if(count2 == 5 && count1!=5 && count3!=5)
			printf("A's birthday(%s) and C's birthday(%s) are the same day.",bir1,bir3);
		else if(count3 == 5 && count1!=5 && count2!=5)
			printf("B's birthday(%s) and C's birthday(%s) are the same day.",bir2,bir3);
		else if(count1 == 5 && count2 ==5 && count3 == 5)
			printf("A's birthday(%s), B's birthday(%s) and C's(%s) birthdayare the same day.",bir1,bir2,bir3);
		else 
			printf("They are all different.");
} 
