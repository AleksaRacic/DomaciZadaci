#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode {
	int info;
	struct listNode *next;
	} ListNode;


typedef struct charNode{
	char c;
	struct charNode* next;
}charNode;


int variables[26];	
int option, i;
char var;
charNode* head;

void destroyList(struct listNode* top){
struct listNode* cur;
	while(top!=NULL){
		cur = top;
		top = top->next;
		cur->next = NULL;
		free(cur);
	}
}

void printList(struct listNode *top){
	struct listNode* cur = top;
	if(top->next!=NULL){
		printf("Stack: ");
	do{
		printf("%d ", cur->info);
		cur = cur->next;
	}while(cur!=top);
}else{
	printf("prazno \n");
}
printf("\n");
}

void printString(struct charNode *head){
	struct charNode* cur = head;
	printf("string: ");
	while(cur!=NULL){
		
		printf("%c ", cur->c);
		cur = cur->next;
	}
	printf("\n");
}

charNode* readString(){
	char c;
	charNode *head, *cur, *last;
	head = NULL;
	
	fflush(stdin);
	
	while ((c = getchar()) != '\n' && c != EOF){
		if(c!='\n'){
			if(head ==NULL){
				head = malloc(sizeof *head);
				head->c = c;
				last = head;
				last->next = NULL;
			}else{
				cur = malloc(sizeof *cur);
				cur->c = c;
				cur->next = NULL;
				last->next = cur;
				last = cur;
			}
		}
	}
	return head;
}

int pop(struct listNode **top, struct listNode *bot){
	struct listNode *cur, *t;
	struct listNode tmp;
	if((**top).next==NULL){
		printf("Error: Underflow (return 0)\n");
		return 0;
	}else{
		tmp = (**top);
		cur = *top;
		if(*top == (**top).next){
			(**top).next = NULL;
			bot->next = NULL;
			bot = *top;
		}else{
		
		*top = (**top).next;
		bot->next = *top;
		cur->next = NULL;
		free(cur);
		}
	}
	printf("pop %d\n", tmp.info);
	return tmp.info;
}

void push(struct listNode **top, struct listNode *bot, int tmp){
	struct listNode* cur;
	if((**top).next == NULL){
		(**top).info = tmp;
		(**top).next = *top;
	}else{
	cur = malloc(sizeof(struct listNode));
	cur->next = *top;
	cur->info = tmp;
	*top = cur;
	bot->next = *top;
}
printf("push %d\n", (**top).info);
}

int main(int argc, char *argv[]) {
	while(1){
		printf("Meni\n1. Unesi izraz\n2. Pridruzi vrednost\n3. Izracunaj\n4. Oslobodi memoriju\n5. Izlaz\n");
		scanf("%d", &option);
		switch(option){
			case 1:
				head = readString();
				break;
			case 2:
				;
				int i;
				printf("Ime varijable: \n");
				fflush(stdin);
				scanf("%c", &var);
				printf("Vrednost varijable: \n");
				fflush(stdin);
				scanf("%d", &variables[(int)var-65]);
				for(i=0; i<26; i++){
					printf("%c %d\n", (char)(65+i), variables[i]);
				}
				break;	
			case 3: ;
				printString(head);
				struct charNode* cur = head;
				int a,b;
				struct listNode *top = malloc(sizeof *top);
				top->next = NULL;
				struct listNode *bot = top;
				
				while(cur!=NULL){
					switch(cur->c){
						case '*':
							a = pop(&top,bot);
							b = pop(&top,bot);
							printf("puta\n");
							push(&top,bot, a*b);
							break;
						case '+':
							a = pop(&top,bot);
							b = pop(&top,bot);
							printf("plus\n");
							push(&top,bot, b+a);
							
							break;
						case '-':
							a = pop(&top,bot);
							b = pop(&top,bot);
							printf("minus\n");
							push(&top,bot, b-a);
							break;
						case '/':
							a = pop(&top,bot);
							b = pop(&top,bot);
							printf("podeljeno\n");
							push(&top,bot, b/a);
							break;	
							
							
							
						default:
							//printf("trying to push %d\n", variables[((int)cur->c)-65]);
							push(&top, bot, variables[((int)cur->c)-65]);
							break;
					}
					cur = cur->next;
					printList(top);
					//printf("top bot %d %d \n", top, bot);
				}
				printf("Rezultat: %d\n", pop(&top,bot));
				break;
			case 4:
				break;
			case 5:
				return 0;
				
				
			default:
				printf("Izaberite broj u granicama 1-5");
		}
	}
	//head = readList();
	
	
	return 0;
}
