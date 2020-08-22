#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct listNode{
	char info[100];
	struct listNode *next, *prev;
}listNode;

//char deq(listNode *first){
//	char tmp[100];
//	listNode *f;
//	if(first->next){
//		return tmp;
//	}else{
//		if(first->next == first){
//			tmp = first->info;
//			first->next = NULL;
//			first->prev = NULL;
//			return tmp;
//		}else{
//			f = first->prev;
//			first->prev = f->prev;
//			f->prev->next = first;
//			tmp = f->info;
//			free(f);
//			return tmp;
//		}
//	}
//}

void enqueue(listNode *first, char elem[100]){
	if(first->prev){
		listNode *tmp;
		tmp = malloc(sizeof(listNode));
		tmp->next = first;
		tmp->prev = first->prev;
		first->prev->next = tmp;
		first->prev = tmp;
		strcpy(tmp->info, elem);
		
		
	}else{
		strcpy(first->info, elem);
		first->prev = first;
		first->next = first;
	}
}

listNode *izbrisi(listNode *cur){
	listNode *tmp;
	tmp = cur;
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	cur = cur->next;
	free(tmp);
	return cur;
}

listNode *izbaci(listNode *first, int d, int m){
	listNode *cur;
	cur = first;
	int dan, mesec, vreme, status;
	int count = 0;
	int d1 = d;
	int m1 = m;
	do{
		count++;
		cur=cur->next;	
	}while(cur!=first);
	do{
		d = d1;
		m = m1;
		sscanf(cur->info, "%*[^,]%*c%*c%*[^,]%*c %d, %d.%d., %d", &status, &dan, &mesec, &vreme);
		if(status == 1){
			if(cur == first){
				first = cur->next;
			}
			cur = izbrisi(cur);
		}else{
			//strogo vece
			while(vreme>0){
				if(d>=vreme){
				d= d-vreme;
				vreme = 0;
			}else{
				switch(--m){
					case 1:
						d = d+31;
						break;
					case 2:
						d = d + 28;
						break;
					case 3:
						d = d+31;
						break;
					case 4:
						d = d+30;
						break;
					case 5:
						d = d+31;
						break;
					case 6:
						d = d+30;
						break;
					case 7:
						d = d+31;
						break;
					case 8:
						d = d+31;
						break;
					case 9:
						d = d+30;
						break;
					case 10:
						d = d+31;
						break;
					case 11:
						d = d+30;
						break;
					case 12:
						d = d+31;
						break;
					
				}
				
			}
			}
			
			if(mesec > m){
				if(cur == first){
				first = cur->next;
			}
				//
				cur = izbrisi(cur);
			}else if(mesec = m){
				if(dan>d){
					if(cur == first){
				first = cur->next;
			}
				//
					cur = izbrisi(cur);
				}else{
					cur = cur->next;
				}
			}else{
				cur = cur->next;
			}	
		}
	}while(count--);
	return first;
}
listNode *readLine(listNode *prvi){
	char str[100];
	fgets(str,100,stdin);
	if(str[0]!='\n'){
		enqueue(prvi, str);
		return prvi;
	}else{
		return NULL;
	}
}

void sortiraj(listNode **prvi){
	listNode *cur1, *cur2;
	int status1, status2, dan1, dan2, mesec1, mesec2, vreme1, vreme2;
	int d1,d2;
	char tmp[100];
	cur1 = *prvi;
	
	do{
		sscanf(cur1->info, "%*[^,]%*c%*c%*[^,]%*c %d, %d.%d., %d", &status1, &dan1, &mesec1, &vreme1);
		cur2=cur1->next;
		do{
			//swap
			sscanf(cur2->info, "%*[^,]%*c%*c%*[^,]%*c %d, %d.%d., %d", &status2, &dan2, &mesec2, &vreme2);

			if(dan1+vreme1>30){
				d1 = dan1+vreme1-30;
				mesec1++;
			}else{
				d1 = dan1+vreme1;
			}
			
			
				if(dan2+vreme2>30){
				d2 = dan2+vreme2-30;
				mesec2++;
			}else{
				d2 = dan2+vreme2;
			}
			

			
			if(mesec1>mesec2){
				strcpy(tmp, cur2->info);
				strcpy(cur2->info,cur1->info);
				strcpy(cur1->info,tmp);
			}else if(mesec1==mesec2){
				if(d1>d2){
					strcpy(tmp, cur2->info);
					strcpy(cur2->info,cur1->info);
					strcpy(cur1->info,tmp);
				}else if(d1==d2){
					if(status1>status2){
						strcpy(tmp, cur2->info);
						strcpy(cur2->info,cur1->info);
						strcpy(cur1->info,tmp);
					}
				}
			}
			cur2 = cur2->next;
		}while(cur2!=*prvi);
		cur1 = cur1->next;
	}while(cur1!=*prvi);
}

void unisti(listNode *prvi){
	listNode *cur;
	cur = prvi->next;
	prvi->next = NULL;
	while(cur!=NULL){
		prvi = cur;
		free(prvi);
		cur = cur->next;
		
	} 
	
}

listNode *initList(){
	listNode* g;
	g = malloc(sizeof(listNode));
	g->next = NULL;
	g->prev = NULL;
	return g;
}
void printList(listNode *prvi){
	listNode *cur;
	cur=prvi->prev;
	if(!prvi->prev){
		return;
	}
	
	do{
		fputs(cur->info,stdout);
		cur = cur->prev;
	}while(cur!=prvi->prev);
}

int main(int argc, char *argv[]) {
	int dan,mesec;
	listNode *prvi;
	prvi = initList();
	while(readLine(prvi));
	
	
	
	scanf("%d.%d.",&dan,&mesec);
	printList(prvi);
	prvi = izbaci(prvi, dan, mesec);
	sortiraj(&prvi);
	printList(prvi);
	unisti(prvi);
	return 0;
}
