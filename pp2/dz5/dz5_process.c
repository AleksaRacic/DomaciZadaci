# include "dz5.h"

void addLista(Lista *lista, Elem node){
	
	if(!lista->poslednji && !lista->prvi){
		lista->prvi = node;
		lista->poslednji = node;
		node->next = NULL;
		node->prev = NULL;
	}else{
		lista->poslednji->next=node;
		node->prev = lista->poslednji;
		lista->poslednji = node;
		node->next = NULL;
	}
}

void reverse(Lista *lista){
	Elem tmp,cur;
	cur = lista->poslednji;
	while(cur){
		tmp = cur->next;
		cur->next = cur->prev;
		cur->prev = tmp;
		cur = cur->next;
	}
	tmp = lista->poslednji;
	lista->poslednji = lista->prvi;
	lista->prvi = tmp;
}

void freeList(Lista lista){
	Elem tmp,cur;
	cur = lista.prvi;
	while(cur){
		tmp = cur;
		cur = cur->next;
		free(tmp);
	//	printf("dealokacija\n");
	}
}
