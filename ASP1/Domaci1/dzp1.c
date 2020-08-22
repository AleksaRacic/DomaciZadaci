#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int* opcija1(int n, int duzina){
	int pozicija, i, j;
	int* niz;
	
				
				niz = malloc(duzina*sizeof(int));
				
				if (niz == NULL) { 
        			printf("Greska u alokaciji\n"); 
        			exit(0); 
    			} 
    			else { 
				for(i = 1; i<n ; i++){
					for(j = 0; j < i ; j++){
						printf("Unesite vrednost nepodrazumevane velicine elementa [%d,%d]\n", i,j);
						pozicija = (i*(i-1)/2)+j;
						//printf("%d\n", pozicija);
						scanf("%d", &niz[pozicija]);
					}
				}
}
return niz;
}


int main(int argc, char *argv[]) {
	int option, podrazumevana, pozicija;
	int* pointer;
	int n, duzina, i, j;
	float usteda;
	
	while(1){
		printf("1. Stvori matricu \n2. Postavi podrazumevanu vrednost\n3. Dohvati element\n4. Postavi vrednost elementu\n5. Ispisi broj nepodrazumevanih elemenata\n6. Ispisi matricu\n7. Izracunaj ustedu prostora\n8. Brisi matricu\n9. Izadji iz programa\n");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				printf("Unesi dimenziju matrice\n");
				scanf("%d", &n);
				duzina = ((n-1)*n) / 2;
				pointer = opcija1(n, duzina);
				break;
			
			case 2:
				printf("Unesite podrazumevanu vrednost\n");
				scanf("%d",&podrazumevana);
				break;
			case 3:
				printf("Unesite poyicije elemenata [i,j]\n");
				scanf("%d %d",&i , &j);
				//printf("%d %d \n", i,j);
				if(i<n && j<n && j>-1 && i > -1){
				
				if(i>j){
				
				pozicija = (i*(i-1)/2)+j;
				if(pointer!=NULL){
				printf("Vrednost %d \n", pointer[pozicija]);
			}else{
				printf("Ne postoji element\n");
			}
			}
			else{
				printf("%d\n", podrazumevana);
			}
			}
			else
			{
				printf("Nije dobar opseg\n");
			}
				break;
				
			case 4:
				printf("Unesite poziciju elementa [i,j]\n");
				scanf("%d %d", &i, &j);
				if(i<n && j<n && j>-1 && i > -1 && i>j){
					pozicija = (i*(i-1)/2)+j;
					printf("Unesite vrednost elementa\n");
					scanf("%d", &pointer[pozicija]); 
				}
				else{
					printf("nekorektan opseg\n");
				}
				break;
				
			case 5:
				printf("Broj nepodrazumevanih elemenata %d \n", duzina);
				break;
				
			case 6:
				for(i = 0; i<n; i++){
					for(j = 0; j<n; j++){
						if(i>j){
							pozicija = (i*(i-1)/2)+j;
							if(pointer!=NULL){
							printf("%d ", pointer[pozicija]);
						}else{
							printf("Na ");
						}
						}
						else{
							printf("%d ", podrazumevana);
						}
					}
					printf("\n");
				}
				break;
				
			case 7:
				usteda = 100 - 100.0 * duzina /pow(n,2);
				printf("%f posto\n", usteda);
				break;
				
			case 8:
				pointer = NULL;
				free(pointer);
				printf("Izbrisano\n");
				break;
				
			case 9:
				return 0;
				break;
				
			default:
				printf("Unesi broj u opsegu 1-9\n");
		}
	}
	
	return 0;
}
