#include "dz5.h"


void ascanf(int num, char str[],...){
	int i,j,k;
	char tmp[50];
	va_list arguments;
	va_start(arguments, str);
	k = 0;
	for(i = 0; i<num; i++){
		j = 0;
		while(str[k]!=',' && str[k]!='\0'&&str[k]!='\n'){
			if(str[k]=='"'){
				k++;
				while(str[k]!='"'){
					tmp[j] = str[k];
					j++;
					k++;
				}
				k++;
			}else{
				tmp[j] = str[k];
				j++;
				k++;
			}
			
		}
		tmp[j] = '\0';
		strcpy((char*)va_arg(arguments, char*),tmp);
		if(str[k]=='\0') break;
		k++;
		
		
		
	}
	va_end(arguments);
}

Lista readFile(const char ime[]){
	Lista lista;
	lista.poslednji = NULL;
	lista.prvi = NULL;
	FILE *fp;
	Elem tmpNode;
	
	fp = fopen(ime, "r"); 
   	if(fp == NULL){
		DATERR
   	}
   	tmpNode = readLine(fp);
   	free(tmpNode);
   	while(tmpNode = readLine(fp)){
   		addLista(&lista,tmpNode);
   	}
   fclose(fp);
   return lista;
}

Elem readLine(FILE *fp){
	char custom1[2],custom2[2],custom3[2],custom4[2];
	int i,j;
	char str[1500];
	Elem tmp = NULL;
	//uradi ovo karakter po karakter
	if(fgets(str,1000,fp)){
		tmp = malloc(sizeof(struct elem));
		//printf("alokacija\n");
		ascanf(37,str,&(tmp->firstname),&(tmp->lastname),&(tmp->displayname),&(tmp->nickname),&(tmp->primaryemail),&(tmp->secondaryemail),&(tmp->screenname),&(tmp->workphone),&(tmp->homephone),&(tmp->faxnumber),&(tmp->pagernumber),&(tmp->mobilenumber),&(tmp->homeadress), &(tmp->homeadress2),&(tmp->homecity),&(tmp->homestate),&(tmp->homezipcode),&(tmp->homecountry),\
		&(tmp->workadress),&(tmp->workadress2),&(tmp->workcity),&(tmp->workstate),&(tmp->workzipcode),&(tmp->workcountry),&(tmp->jobtitle),&(tmp->department),&(tmp->organizaton),&(tmp->webpage1),&(tmp->webpage2),&(tmp->birthyear),&(tmp->birthmonth),\
		&(tmp->birthday),&custom1,&custom2,&custom3,&custom4,&(tmp->notes));
		//printf("%c %c %c %c %c %c\n",tmp->firstname[0],tmp->lastname[0],tmp->displayname[0],tmp->displayname[10],tmp->primaryemail[2],tmp->organizaton[0]);
	}
	
	return tmp;
}
