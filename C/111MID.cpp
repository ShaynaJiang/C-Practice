#include<stdio.h>
#include<math.h> 
float pay, km, BasePay, Day, etg = 0.9, pass, longway, final, is_repeat=0, arr[5]={0, 1.20,1.20, 1.50, 1.8};
int car;
double fee=0;
int main(){ 
	do{
		printf("�п�J���ءA1)�p�����A2)�p�{���A3)�j�����A4)�p����:");
		scanf("%d",&car);
		if(car<0 || car>4){
			is_repeat = 1;
				printf("��J���~�A�Э��s��Jcar�C\n");
		}
		else{
			is_repeat = 0;
		}
	}while(is_repeat);
	do{	
		printf("�п�Jú�O�覡�A1)eTag�Τ�A2)�w���Τ�A3)ú�O�Τ�G");
		scanf("%f",&pay);
		if(pay<0 || pay>3){
			is_repeat = 1;
			printf("��J���~�A�Э��s��Jpay�C\n");
		}
		else{
			is_repeat = 0;
		}
	}while(is_repeat);	
	do{
		printf("�п�J���{��:");
		scanf("%f",&km);
		if(km<0){
			is_repeat = 1;
			printf("��J���~�A�Э��s��Jkm�C\n");
		}
		else{
			is_repeat = 0;
		}
	}while(is_repeat);
	
	//�p��U���򥻶O�� 
	BasePay = arr[car] * km;
	
	//�D�p�{�����O�p�� 
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
	
	//�p�{�����O�p��
	if(car == 2){
		longway = 0;
		pass = BasePay;		
		Day = 0;
	}
	
	//�q��O�|�ˤ��J 
	float a = round(pass);
	
	//�P�_�O�_��etg�u�f 
	if(pay == 1){
		final = a * etg;
	}
	else{
		final = a;
	}

	printf("�򥻶O�� �C���u�f ���~�馩 �`�q��O  �|�ˤ��J��O�� �̫�O��\n");
	printf("%0.3f  %0.3f    %0.3f    %0.3f   %0.3f        %0.3f", BasePay, Day, longway, pass , a, final);
}

	

 
