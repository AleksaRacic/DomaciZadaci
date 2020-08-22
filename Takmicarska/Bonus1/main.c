#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 


typedef struct Par{
	unsigned short int br, vr;
}par;

void swap(par* a, par* b) 
{ 
    par t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int partition (par arr[], int low, int high) 
{ 	
	int i,j;
    par pivot;
	pivot = arr[high];    
    i = (low - 1);  
  	
    for (j = low; j <= high- 1; j++) 
    { 
        if (arr[j].br > pivot.br) 
        { 
            i++;  
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(par arr[], int low, int high) 
{ 
    if (low < high) 
    { 

        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
int main() {
	unsigned short n,i,j;
	long int brjaja = 0;
	scanf("%hu", &n);
	par *jaja = NULL;
	jaja = malloc(n*sizeof(par));
	for(i = 0;i<n;i++){
		scanf("%hu%hu", &jaja[i].br, &jaja[i].vr);
	}
	quickSort(jaja, 0, n-1);
	
	int max_time  = jaja[0].vr;
	for(i = 1;i<n;i++) if(jaja[i].vr>max_time) max_time = jaja[i].vr;
	bool *termini = NULL;
	termini = calloc(max_time,sizeof(bool));
	for(i = 0; i<n;i++){
		for(j = jaja[i].vr; j>0; j--){
			if(!termini[j-1]){
				termini[j-1] = true;
				brjaja += jaja[i].br;
				break;
			}
		}
	}
	printf("%ld",brjaja);
	return 0;
}
