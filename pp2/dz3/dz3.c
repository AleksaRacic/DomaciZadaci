#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *readWord(){
	char c;
	char* ptr;
	ptr = NULL;
	int i = 1;
	
	while(scanf("%c",&c)!=0 && c!='\n' && c!=' '){
		ptr = realloc(ptr,i*sizeof(char));
		ptr[i-1] = c;
		i+=1;
	}
	ptr = realloc(ptr,i*sizeof(char));
	ptr[i-1] = '\0';
	
	return ptr;
}

int abs(int a){
	return (a>=0)?a:-a;
}

 void rotateSentence(char **sentence, int n, int rotate){
 	int i,k;
 	int move;
 	char *tmp;
 	if(rotate==0){
 		return;
	 }else if(rotate>0){
	 	//kraj na pocetak
	 	for(i = 0; i<abs(rotate);i++){
	 		tmp = sentence[n-1];
	 		for(k = n-1; k>0;k--){
	 			sentence[k] = sentence[k-1];
			 }
			 sentence[0] = tmp;
		 }
	 }else if(rotate < 0){
	 	for(i = 0; i<abs(rotate);i++){
	 		tmp = sentence[0];
	 		for(k = 0; k<n-1;k++){
	 			sentence[k] = sentence[k+1];
			 }
			 sentence[n-1] = tmp;
		 }
	 }
	 
 }

//char **readWords(int *n){
//	char **ptr = NULL;
//	char *p = NULL;
//	int i = 1;
//	do{
//		ptr = realloc(ptr, i * sizeof(*ptr));
//		p = readWord();	
//		if(p){
//			ptr[i-1] = p;
//			(*n)++;
//			i++;
//		}
//	}while(p);
//	
//	return ptr;
//}

//ispraviti
char **readWords(int *n){
	char **ptr = NULL;
	char *p = NULL;
	*n = 0;
	p = readWord();
	while(*p!='\0'){
		ptr = realloc(ptr, ((*n)+1) * sizeof(*ptr));
		ptr[(*n)++] = p;
		p = readWord();
	}
	return ptr;
}

int main(int argc, char *argv[]) {

int n = 0;
int rotate;
char **p;
char *pt;
p = readWords(&n);
scanf("%d",&rotate);
if(p[0]=='\0'){
	printf("GRESKA");
}else{
	rotateSentence(p,n,rotate);
	int i,j;
	for(i = 0; i<n-1; i++){
		j = 0;
		pt = p[i];
		while(pt[j] != '\0'){
			printf("%c", pt[j]);
			j++;
		}
		printf(" ");
	}
		j = 0;
		pt = p[n-1];
	while(pt[j] != '\0'){
		printf("%c", pt[j]);
		j++;
	}
	for(i = 0; i<n; i++){
		free(p[i]);
	}
	free(p);
	}
	

	return 0;
}
