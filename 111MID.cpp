#include<stdio.h>
#include<math.h> 
float pay, km, BasePay, Day, etg = 0.9, pass, longway, final, is_repeat=0, arr[5]={0, 1.20,1.20, 1.50, 1.8};
int car;
double fee=0;
int main(){ 
	do{
		printf("請輸入車種，1)小型車，2)計程車，3)大型車，4)聯結車:");
		scanf("%d",&car);
		if(car<0 || car>4){
			is_repeat = 1;
				printf("輸入錯誤，請重新輸入car。\n");
		}
		else{
			is_repeat = 0;
		}
	}while(is_repeat);
	do{	
		printf("請輸入繳費方式，1)eTag用戶，2)預約用戶，3)繳費用戶：");
		scanf("%f",&pay);
		if(pay<0 || pay>3){
			is_repeat = 1;
			printf("輸入錯誤，請重新輸入pay。\n");
		}
		else{
			is_repeat = 0;
		}
	}while(is_repeat);	
	do{
		printf("請輸入里程數:");
		scanf("%f",&km);
		if(km<0){
			is_repeat = 1;
			printf("輸入錯誤，請重新輸入km。\n");
		}
		else{
			is_repeat = 0;
		}
	}while(is_repeat);
	
	//計算各車基本費用 
	BasePay = arr[car] * km;
	
	//非計程車車費計算 
	if(km<=20 && car != 2){
		longway = 0;
		pass = 0;		
		Day = BasePay;
	}	
	else if(20<km<=200 && car != 2){
		longway = 0;
		Day = 20*arr[car];
		pass = BasePay - Day - longway;
	}
	else if(km>200 && car != 2){
		Day = 20*arr[car];
		longway = km * arr[car] * 0.75;
		pass = BasePay - Day - longway;
	}
	
	//計程車車費計算
	if(car == 2){
		longway = 0;
		pass = BasePay;		
		Day = 0;
	}
	
	//通行費四捨五入 
	float a = round(pass);
	
	//判斷是否有etg優惠 
	if(pay == 1){
		final = a * etg;
	}
	else{
		final = a;
	}

	printf("基本費用 每日優惠 長途折扣 總通行費  四捨五入後費用 最後費用\n");
	printf("%0.3f  %0.3f    %0.3f    %0.3f   %0.3f        %0.3f", BasePay, Day, longway, pass , a, final);
}

	

 
