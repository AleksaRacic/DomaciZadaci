#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int k = 2;
	int i = 2;
	switch(++k){
		case 2: 	
			printf("%d", k);
			k = k+1;
		case 3: printf("%d\n", k);
				k+= i == i +1;
				printf("%d\n", k);
				printf("%d\n", i);
				
		default: k = k+1; i = i+1;
				printf("%d\n", k);
				printf("%d\n", i);
			printf("%d", k);
	}
	return 0;
}
