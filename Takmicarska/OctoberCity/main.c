#include <stdio.h>
#include <stdlib.h>


int abs_(int a){
	return (a>0) ? a : -a;
}

int main() {
	int n,i;
	unsigned long long int broj;
	int *kuce = NULL;
	scanf("%d",&n);
	while(n!=0){
		
		broj = 0;
		kuce = malloc(sizeof(int)*n);
		for(i = 0; i<n;i++) scanf("%d",&kuce[i]);
		for(i = 0; i<n-1; i++){
			kuce[i+1] = kuce[i+1]+kuce[i];
			broj += abs_(kuce[i]);
		}
		printf("%llu\n",broj);
		free(kuce);
		scanf("%d",&n);
	}
	return 0;
}
