#include <stdio.h>
int layer, L, W, max;
int i, j, k, first=0, dash, trunk, p, q;

main(){
	int is_repeat = 1; 
	while(is_repeat){
	 	printf("�п�J�t�Ͼ�h��(����1~15�����_��)�G");
	 	scanf(" %d",&layer);
	  	if ((layer <= 15 && layer >= 1) && (layer%2 == 1))
	  		is_repeat = 0;
	  	else 
			printf("��J���~�Э��s��J�I\n");
	}
	//leaves
  	for(i=1; i <= layer; i++){
      	dash = (layer+2) - i;
		for(j = first; j <= first+2; j++){
			//left
			for(k = dash; k > 0; k--){
			   	printf("-");
			}
		 	//middle
			for(k=0; k <= j*2; k++){
		    	printf ("*");
			}
			//right
			for(k = dash; k > 0; k--){
		        printf("-");
		    }
			dash -= 1;
			
			printf("\n");
	  	}
		first += 1;
	}
	//trunk
	max = layer*2 + 3;
	W = (layer+1) / 2;
	trunk = (max-layer) / 2;
	for (i=1; i <= W; i++){
		//left
		for (j=1; j <= trunk; j++){
		    printf("-");
		}
		//middle
		for (j=1; j <= layer; j++){
	    	printf("*");
	    }
	    //right
		for (j=1; j <= trunk; j++){
		    printf("-");
		}	
		printf("\n");
	}
}









