#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26


//const int oper[8] = {3,3,10,23,1,1,1,1};
typedef struct clan{
	int op;
	char c;
}clan;

int inside(clan elem[], int k, char c){
	int i;
	int flag;
	flag = 0;
	for(i = 0; i <k; i++){
		if(c == elem[i].c){
			flag = 1;
			break;
		}
	}
	if(flag){
		return i;
	}else{
		return -1;
	}
}

void upisi(int graf[MAX][MAX], clan elem[], int *rows){
	char str[100];
	char tmp[20];
	char tmp1[4];
	char opr;
	
	int poz;
	int num,operacija,i,j;
	char levi[4], desni[4];
	
	*rows = 0;
	
	while(fgets(str,100,stdin)){
		if(str[0]=='\n'){
			break;
		}
		sscanf(str,"%d: %c = %[^\n]",&num, &opr, &tmp);
		//printf("%c %c %c\n", tmp[0], tmp[1], tmp[2]);
		if(tmp[0]=='n'&&tmp[1] == 'o' && tmp[2]=='t'){
			//printf("and");
			operacija = 1;
			sscanf(tmp,"%*s %s",&levi);
			strcpy(desni,"2");
			
		}else{
			sscanf(tmp, "%s %s %s",&levi,&tmp1,&desni);
			if(tmp1[0]=='+' || tmp1[0]=='-'){
				operacija = 3;
			}else if(tmp1[0]=='*'){
				operacija = 10;
			}else if(tmp1[0] == '/'){
				operacija = 23;
			}else{
				operacija = 1;
			}
		}
		
		
		
		if(inside(elem, *rows, opr)!=-1){
			printf("Operacija je vec izvrsena\n");
			return;
		}else{
			elem[*rows].c = opr;
			elem[*rows].op = operacija;
			(*rows)++;
			for(i=0; i<*rows; i++){
				graf[*rows - 1][i] = 0;
				graf[i][*rows - 1] = 0;
			}
		}
		if(!(isdigit(levi[0]))){
			if((poz = inside(elem,*rows,levi[0]))!=-1){
				graf[poz][*rows-1] = elem[poz].op;
			}
		}
		if(!(isdigit(desni[0]))){
			if((poz = inside(elem,*rows,desni[0]))!=-1){
				graf[poz][*rows-1] = elem[poz].op;
			}
		}
		
	}
}

int max(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

void topolosko(int graf[MAX][MAX],int elem[],int n){
	int i,j,k,flag,d,l;
	int i1, j1;
	int tmp[MAX][MAX];
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			tmp[i][j] = graf[i][j];
		}
	}
	for(i = 0; i<n; i++){
		d = -1;
		for(j = 0; j<n; j++){
			flag = 0;
			if(tmp[j][0]==-1){
				continue;
			}
			for(k = 0; k<n && !flag; k++){
				if(tmp[k][j] > 0){
					flag = 1;
				}
			}
				
			if(!flag){
				d = j;
				break;
				}
		}
		if(d!=-1){
			elem[i] = d;
		}else{
			printf("topolosko ne valja\n");
		}
		for(j = 0; j < n ; j++){
			tmp[d][j] = -1;
		}
		
		
	}
}

int min(int a, int b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}

int kritput(int graf[MAX][MAX], int n, int EST[], int LST[], int L[], int T[], clan elem[]){
	topolosko(graf, T, n);
	int tmpmin;
	int flag;
	int i,j,k,l;
	int kriticni;
	
	for(i = 0; i<n; i++){
		
		j = T[i];
		EST[j] = 0;
		for(k = 0; k<n; k++){
			if(graf[k][j]!=0){
				EST[j] = max(EST[j],(EST[T[k]]+graf[k][j]));
			}
		}	
	}
	kriticni = 0;
	for(i = 0; i < n; i++){
		kriticni = max(kriticni,(elem[i].op+EST[i]));
	}
	for(i = n-1; i>-1; i--){
		j = T[i];
		LST[j] = kriticni - elem[j].op;
		flag = 1;
		for(k = 0; k<n; k++){
			if(graf[j][k]!=0){
				LST[j] = min(LST[j], (LST[k]-graf[j][k]));
			}
		}	
	}
	for(i = 0; i<n; i++){
		L[i] = LST[i] - EST[i];
	}
	return kriticni;
}

void marsal(int graf[MAX][MAX], int n, clan elem[]){
	int tmp[MAX][MAX];
	int i,j,k;
	
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			tmp[i][j] = graf[i][j];
		}
	}
	
	for(k=0;k<n;k++){
		for(i = 0; i<n; i++){
			for(j = 0; j<n; j++){
				tmp[i][j] = tmp[i][j]||(tmp[i][k]&&tmp[k][j]);
			}
		}
	}
//	printf("  ");
//				for(i = 0; i<n; i++){
//					printf("%c ",elem[i].c);
//				}
//				printf("\n");
//				for(i = 0; i<n; i++){
//					printf("%c ",elem[i].c);
//					for(j=0; j<n;j++){
//					printf("%d ",tmp[i][j]);
//				}
//				printf("\n");
//			}
	for(i = 0; i<n; i++){
		printf("Operacija %c indirektno utice na: ",elem[i].c);
		for(j = 0; j<n; j++){
			if(!graf[i][j] && tmp[i][j]){
				printf("%c ",elem[j].c);
			}
		}
		printf("\n");
	}
	
}

int main(int argc, char *argv[]) {
	int n,i,j;
	int graf[MAX][MAX];
	clan elem[MAX];
	int krit;
	int LST[MAX], EST[MAX], L[MAX], T[MAX];
	int e;
	printf("MENI\n1.Unesi kod\n2.Izracunaj kriticni put\n3.Izracunaj trancitivnost\n4.Izadji\n\n");
	while(1){
		scanf("%d",&e);
		switch(e){
			case 1:
				fflush(stdin);
				upisi(graf, elem, &n);
				printf("  ");
				for(i = 0; i<n; i++){
					printf("%c ",elem[i].c);
				}
				printf("\n");
				for(i = 0; i<n; i++){
					printf("%c ",elem[i].c);
					for(j=0; j<n;j++){
					printf("%d ",graf[i][j]);
				}
				printf("\n");
			}
				break;
			case 2:
				krit = kritput(graf, n, EST, LST, L, T,elem);
				printf("\n");
				printf("OP EST LST L\n");
				for(i = 0; i<n; i++){
				printf("%c %d %d %d\n", elem[i].c, LST[i], EST[i], L[i]);
				}
				printf("Duzina puta je %d\n",krit);
				printf("Kriticni put je: ");
				for(i = 0; i<n; i++){
				if(L[i]==0){
					printf("%c ",elem[i].c);
				}
				}
				printf("\n");
				for(i = 0; i<n; i++){
					if(L[i]!=0){
					printf("Operacija %c moze poceti u taktovima %d - %d\n", elem[i].c,EST[i], LST[i]);
					}
					}
				break;
			case 3:
				marsal(graf,n,elem);
				break;
			case 4:
				return 0;
				break;
			default:
				printf("unesite odgovarajuci broj\n");
				break;
		}
	}
	
	
	
	
	
	return 0;
}
