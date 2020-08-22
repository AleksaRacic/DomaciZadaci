#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 100
#define MAX_INT 2147483647

int min_(int a , int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}
int main() {
	
	int c,r;
	
	scanf("%d%d",&r,&c);
	
	if(!(r<MAX && r>0 && c<MAX && c>0)){
		return 0;
	}else{
		int *m = NULL;
		m = malloc(r*c*sizeof(int));
		if(!m){
			return 0;
		}else{
			int i,j;
			for(i=0; i<r; i++){
				for(j=0; j<c; j++){
					scanf("%d",&m[i*(c)+j]);
				
			}
		}
			//ispis matrice
		for(i=0; i<r; i++){
			for(j=0; j<c-1; j++){
				printf("%d ",m[i*(c)+j]);
				
		}
			printf("%d\n",m[i*(c)+j]);
		}
			
			//najmanji element u svakoj koloni
		int min;
		float sum = 0;
		for(j=0; j<c; j++){
			min = MAX_INT;
			for(i=0; i<r; i++){
				min = min_(min, m[i*(c)+j]);
			}
			printf("%d\n",min);
			sum = sum + min;
		}
		float average = sum/c;
		printf("%.2f\n", average);
		
			//izbacivanje elemenata
		int c1 = 0;
		for(j=0; j<c; j++){
			min = MAX_INT;
			for(i=0; i<r; i++){
				min = min_(min, m[i*(c)+j]);
			}
			if(!(min > average)){
				for(i=0; i<r; i++){
				m[i*(c)+c1] = m[i*(c)+j];
			}
				c1++;
				
			}
		}
		
		for(i=0; i<r; i++){
			for(j=0; j<c1-1; j++){
				printf("%d ",m[i*(c)+j]);
				
		}
			printf("%d\n",m[i*(c)+j]);
		}
		
		
	}
	free(m);
	return 0;
}
}
