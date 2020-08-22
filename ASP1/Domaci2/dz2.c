#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 50
#include <math.h>

typedef enum {false = 0, true = 1} bool;

typedef struct Node{
	int tpr, ipr;
	char symbol[4];
	struct Node *left; 
	struct Node *right; 
	struct Node *parent;
	bool unary;
}Node;

typedef struct sNode{
	Node *info;
	struct sNode *next;
}sNode;



typedef struct qNode{
	Node *info;
	struct qNode *next;
}qNode;

typedef struct queue{
	qNode *first, *last;
}queue;

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

void enqueue(queue *que, Node *node){
	qNode *new = malloc(sizeof(qNode));
	new->info = node;
	if(!(que->first)){
		que->first = new;
		que->last = new;
		new->next = NULL;
	}else{
		que->last->next = new;
		que->last = new;
	}
}

Node *dequeue(queue *que){
	Node *node;
	if(que->first == NULL){
		node = NULL;
		return node;
	}
	if(que->first == que->last){
		node = que->first->info;
		free(que->first);
		que->first = NULL;
		que->last = NULL;
	}else{
		node = que->first->info;
		que->first = que->first->next;
	}
	return node;
}




sNode **stackInit(){
	sNode *(*top); 
	top = malloc(sizeof(top));
	*top = NULL;
	return top;
}

typedef struct sfNode{
	float info;
	struct sfNode *next;
}sfNode;


sfNode **fStackInit(){
	sfNode *(*top); 
	top = malloc(sizeof(top));
	*top = NULL;
	return top;
}



void pushfloat(sfNode **top, float val){
	sfNode *new = malloc(sizeof(sfNode));
	new->info = val;
	if(*top){
		new->next = *top;
		}else{
			new->next = NULL;
		}
	*top = new;
}

float popfloat(sfNode **top){
	sfNode *tmp;
	float val;
	if(!(*top)){
		printf("floatStack_full\n");
	}else{
		tmp = *top;
		*top = (*top)->next;
		val = tmp->info;
		free(tmp);
	}
	return val;
}





void push(sNode **top, Node *node){
	sNode *new = malloc(sizeof(sNode));
	new->info = node;
	if(*top){

		new->next = *top;
		}else{

			new->next = NULL;
		}

		
	*top = new;

}

Node *pop(sNode **top){
	sNode *tmp;
	Node *node;
	if(!(*top)){
		return NULL;
	}else{
		tmp = *top;
		*top = (*top)->next;
		node = tmp->info;
		free(tmp);
	}
	return node;
}


int treeDepth(Node *root){
	int left = -1;
	int right = -1;
	if(root->left){
		left = treeDepth(root->left)+1;
	}else{
		left = 1;
	}
	if(root->right){
		right = treeDepth(root->right)+1;
	}else{
		right = 1;
	}
	return max(left,right);
}


/*
                         
 23               .    a
                  .
                  .

            jos 11 redova                   
11         a----------23-----------a
10        / \       21            /
9        /   \      19           /
8       /     \   17            /  
7	   /       \  15           /
6     /---------\       13    /
5    a           a      11   a  
4   / \         / \     9   / \ 
3  /   \       /   \    7  /   \
2 a-----a     a     a   5 a     a   
1/ \   / \   / \   / \  3/ \   / \     
a   b a   a a   a a   a1a   a a   a
*/

//dodati inicijalisanje reda preko funkcije
int pHigh(int n){
	int i;
	int visina = 2;
	if(n == 1){
		visina = 1;
	}
	
	for(i = 2; i<n; i++){
		visina = 2*visina + 1;
	}
	return visina;
}



void printTree(Node *root){
	int i, j,k,broj,prethodni;
	int brCvorova=1;
	Node *node;
	queue *que = malloc(sizeof(queue));
	que->first = NULL;
	que->last = NULL;
	enqueue(que,root);
	int depth = treeDepth(root)+1;
	broj = pHigh(depth);

	for(i = broj; i>1; i--){
		if(i == broj){
			broj = (broj+1)/2-1;
			
			if(!que->first){
			break;
			}
			for(k=0; k<brCvorova; k++){
				for(j = 0; j<i; j++){
					printf(" ");
				}
				node = dequeue(que);
				if(node){
				if(node->left){
					enqueue(que,node->left);
				}else{
					enqueue(que, NULL);
				}
				if(node->right){
					enqueue(que,node->right);
				}else{
					enqueue(que, NULL);
				}
				fputs(node->symbol,stdout);
				}else{
					printf(" ");
					enqueue(que, NULL);
					enqueue(que, NULL);
				}
				
				for(j = 0; j<=i; j++){
					printf(" ");
				}
				
			}
			
			brCvorova = brCvorova*2;
			prethodni = i;
		}else{
			for(k=0; k<brCvorova/2; k++){
				node = dequeue(que);
				if(node){
					for(j = 0; j<i; j++){
					printf(" ");
					}
					printf("/ ");
					for(j = 0; j < 2*(prethodni - i-1); j++){
					printf(" ");
					}
				
				
				}else{
					for(j = 0; j<2*prethodni - i; j++){
					printf(" ");
					}
				}
				enqueue(que,node);
				node = dequeue(que);
				if(node){
					printf("\\");
				for(j = 0; j<=i; j++){
					printf(" ");
				}
				}else{
					for(j = 0; j<=i+1; j++){
					printf(" ");
					}
				}
				enqueue(que,node);
			}
			
				
		}
		printf("\n");
	}
	
	printf("\n\n");
}




void addNode(Node **cur, Node node, Node **root){
	if(!(*cur)){
		**root = node;
		*cur = *root;
	}else{
		Node *newNode  = malloc(sizeof(Node));
		*newNode = node;
		if(node.ipr <= (*cur)->tpr && node.ipr!=0){
			//idi na gore do mesta ubacivanja
			while((*cur)->parent){
				if((*cur)->parent->tpr >= node.ipr){
					(*cur)= (*cur)->parent;
				}else{
					break;
				}
			}
			if((*cur)->parent){
				if((*cur)->parent->left == (*cur)){
					//levi
					(*cur)->parent->left = newNode;
					
				}else{
					//desni
					(*cur)->parent->right = newNode;
				}
				
			}else{
				*root = newNode;
			}
			newNode->parent = (*cur)->parent;
			(*cur)->parent = newNode;
			newNode->left = (*cur);
			(*cur) = newNode;	
			
		}else if(node.ipr==0){
			while(node.ipr!=(*cur)->tpr){
				(*cur) = (*cur)->parent;
			}
			
			if((*cur)->parent){
				if((*cur)->parent->left == (*cur)){
					//levi
					(*cur)->parent->left = (*cur)->right;
					(*cur)->right->parent = (*cur)->parent;
					
				}else{
					//desni
					(*cur)->parent->right = (*cur)->right;
					(*cur)->right->parent = (*cur)->parent;
				}
				
			}else{
				*root = (*cur)->right;
			}
			newNode = *cur;
			*cur = (*cur)->right;
			free(newNode);
		}else{
			while((*cur)->tpr < newNode->ipr){
				if((*cur)->unary){
					if((*cur)->left){
						(*cur)=(*cur)->left;
					}else{
						(*cur)->left = newNode;
						newNode->parent = (*cur);
						(*cur) = newNode;
						break;
					}
				}else{
					if((*cur)->right){
						(*cur)=(*cur)->right;
					}else{
						(*cur)->right = newNode;
						newNode->parent = (*cur);
						(*cur) = newNode;
						break;
					}
				}
			}
			if(*cur!=newNode){
				if((*cur)->unary){
					(*cur)->left = newNode;
					(*cur) = newNode;
				}else{
					(*cur)->right = newNode;
					(*cur) = newNode;
				}
			}
		}
			
			
			
		}
	}


Node *parse_expression(char expression[]){
	Node *root = malloc(sizeof(Node));
	
	Node **curNode = malloc(sizeof(root));
	*curNode = NULL;
	int cur;
	char c;

	cur = 0;
	while(expression[cur]!='\0'){
		Node trenutni = {10,10,"t",NULL,NULL,NULL,false};
		c = expression[cur++];
		if(c==' '||c=='\n') continue;
		
		if(c==')'){
			trenutni.ipr = 0;
			trenutni.tpr = 10;
			trenutni.symbol[0] = c;
		}else if(c=='('){
			trenutni.ipr = 8;
			trenutni.tpr = 0;
			trenutni.symbol[0] = c;
		}else if(c=='-'){
			if(expression[cur-2]!='('){
				trenutni.ipr = 2;
				trenutni.tpr = 2;
				trenutni.symbol[0] = c;
			}else{
				trenutni.ipr = 6;
				trenutni.tpr = 6;
				trenutni.unary = true;
				strcpy(trenutni.symbol,"(-)");
			}
		}else if(c=='+'){
			trenutni.ipr = 2;
			trenutni.tpr = 2;
			trenutni.symbol[0] = c;
		}else if(c=='*'){
			trenutni.ipr = 4;
			trenutni.tpr = 4;
			trenutni.symbol[0] = c;
		}else if(c =='/'){
			trenutni.ipr = 4;
			trenutni.tpr = 4;
			trenutni.symbol[0] = c;
		}else if(c =='^'){
			trenutni.ipr = 6;
			trenutni.tpr = 5;
			trenutni.symbol[0] = c;
		}else if(isupper(c)){
			trenutni.ipr = 7;
			trenutni.tpr = 7;
			trenutni.symbol[0] = c;
		}else if(c=='s' && expression[cur]== 'i' && expression[cur+1]=='n'){
			cur = cur+2;
			trenutni.ipr = 7;
			trenutni.tpr = 7;
			trenutni.unary = true;
			strcpy(trenutni.symbol,"sin");
		}
		else if(c=='c' && expression[cur] == 'o' && expression[cur+1]=='s'){
			cur = cur+2;
			trenutni.ipr = 7;
			trenutni.unary = true;
			trenutni.tpr = 7;
			strcpy(trenutni.symbol,"cos");
		}
		else if(c=='l' && expression[cur] == 'n'){
			cur = cur+1;
			trenutni.ipr = 7;
			trenutni.tpr = 7;
			trenutni.unary = true;
			strcpy(trenutni.symbol,"ln");
		}else{
			printf("Nedozvoljen karakter %c",c);
			return NULL;
			break;
		}
		
		addNode(curNode,trenutni,&root);
		
	}
	
	return root;
}


void printPostorder(Node *root){ 
    if (root == NULL) 
        return; 
      
    sNode **top = stackInit(); 
    
    do{ 
        while(root) 
        { 
            if (root->right) 
                push(top, root->right); 
            push(top, root); 
  
            root = root->left; 
        } 
       
        root = pop(top); 
  
        if(root->right && (*top) && (*top)-> info == root->right) { 
        		pop(top);
            	push(top, root);
           		root = root->right; 
        }else{ 
            fputs(root->symbol,stdout);
            root = NULL; 
        } 
    }while(*top); 
    printf("\n\n");
} 

void evaluate(Node *root){ 
	float tmp, tmp1;
	bool flag = true;
	char kar[12];
	float fl[12];
	int i;
	int number = 0;
	sfNode **stack = fStackInit();
    if (root == NULL) 
        return; 
      
    sNode **top = stackInit(); 
    
    do{ 
        while(root) 
        { 
            if (root->right) 
                push(top, root->right); 
            push(top, root); 
  
            root = root->left; 
        } 
       
        root = pop(top); 
  
        if(root->right && (*top) && (*top)-> info == root->right) { 
        		pop(top);
            	push(top, root);
           		root = root->right; 
        }else{ 
            if(isupper(root->symbol[0])){
            	for(i = 0; i < number; i++){
            		if(kar[i] == root->symbol[0]){
            			tmp = fl[i];
            			flag = false;
					}
				}
				if(flag){
					printf("Upisite vrednost za %c: ",root->symbol[0]);
            		scanf("%f",&tmp);
            		kar[number] = root->symbol[0];
            		fl[number++] = tmp;
				}
				flag = true;
            	pushfloat(stack, tmp);
			}else if(root->unary){
				tmp = popfloat(stack);
				if(root->symbol[0] == '('){
					pushfloat(stack, -tmp);
				}else if(root->symbol[0] == 'l'){
					pushfloat(stack, log(tmp));
				}else if(root->symbol[0] == 's'){
					pushfloat(stack, sin(tmp));
				}else if(root->symbol[0] == 'c'){
					pushfloat(stack, cos(tmp));
				}
			}else{
				tmp = popfloat(stack);
				tmp1 = popfloat(stack);
				if(root->symbol[0] == '-'){
					pushfloat(stack, tmp1-tmp);
				}else if(root->symbol[0] == '+'){
					pushfloat(stack, tmp1+tmp);
				}else if(root->symbol[0] == '*'){
					pushfloat(stack, tmp1*tmp);
				}else if(root->symbol[0] == '/'){
					pushfloat(stack, tmp1/tmp);
				}else if(root->symbol[0] == '^'){
					pushfloat(stack, pow(tmp1,tmp));
				}
			}
			root = NULL;
        } 
    }while(*top); 
    printf("%f\n",popfloat(stack));
    printf("\n\n");
    free(top);
    free(stack);
} 

printStack(sNode **stack){
	sNode *cur = *stack;
	while(cur!=NULL){
		printTree(cur->info);
		printf("\n\n\n");
		cur = cur->next;
	}
	printf("\n\n");
}
Node *differentiate(Node *root){ 
	Node *tmp1,*tmp2,*pomocna,*pomocna2, *pomocna3, *pomocna4;
	char c;
	Node *new;
    if (root == NULL) 
        return; 
    sNode **stack = stackInit();  
    sNode **top = stackInit(); 
    
    char x;
    printf("Upisite promenljivu po kojoj se izvodi:\n");
    fflush(stdin);
    scanf("%c", &x);
    
    do{ 
        while(root) 
        { 
            if (root->right) 
                push(top, root->right); 
            push(top, root); 
  
            root = root->left; 
        } 
       
        root = pop(top); 
  
        if(root->right && (*top) && (*top)-> info == root->right) { 
        		pop(top);
            	push(top, root);
           		root = root->right; 
        }else{ 
        	new = malloc(sizeof(Node));
        	new->right = NULL;
        	new->left = NULL;
        	new->parent = NULL;
            if(isupper(root->symbol[0])){
            	if(root->symbol[0] == x){
            		strncpy(new->symbol, "1",sizeof(new->symbol));
				}else{
					strncpy(new->symbol, "0",sizeof(new->symbol));
				}
            	push(stack, new);
				
			}else if(root->unary){
				
				tmp1 = pop(stack);
				c = tmp1->symbol[0];
				if(root->symbol[0] == '('){
					//dodati unary
					strncpy(new->symbol,"(-)",sizeof(new->symbol));
					if(c=='1'){
						new->left = tmp1;
						push(stack, new);
					}else if(c=='0'){
						free(tmp1);
					}else{
						new->left = tmp1;
						push(stack, new);
					}
				}else if(root->symbol[0] == 'l'){
					strncpy(new->symbol, "/",sizeof(new->symbol));
					new->right = root->left;
					if(c!='0'){
						new->left = tmp1;
					}else{
						strncpy(new->symbol,"0",sizeof(new->symbol));
						new->right = NULL;
						new->left = NULL;
					}
					push(stack, new);
					
				}else if(root->symbol[0] == 's'){
					if(c=='0'){
						strncpy(new->symbol,"0",sizeof(new->symbol));
						new->right = NULL;
						new->left = NULL;
					}else if(c=='1'){
						strncpy(new->symbol,"cos",sizeof(new->symbol));
						new->left = root->left;
						new->right = NULL;
					}else{
						pomocna = malloc(sizeof(Node));
						strncpy(new->symbol, "*",sizeof(new->symbol));
						new->left = tmp1;
						pomocna ->parent = new;
						strncpy(pomocna->symbol,"cos",sizeof(new->symbol));
						pomocna->left = root->left;
						pomocna->right = NULL;
						new->right = pomocna;
						
					}
					push(stack,new);
				}else if(root->symbol[0] == 'c'){
					if(c=='0'){
						strncpy(new->symbol,"0",sizeof(new->symbol));
						new->right = NULL;
						new->left = NULL;
					}else if(c=='1'){
						pomocna2 = malloc(sizeof(Node));
						strncpy(new->symbol,"(-)",sizeof(new->symbol));
						new->right = NULL;
						new->left = pomocna2;
						strncpy(pomocna2->symbol,"sin",sizeof(new->symbol));
						pomocna2->parent = new;
						pomocna2->right = NULL;
						pomocna2->left = root->left;
					}else{
						//srediti dodatne nule i jedinice
						pomocna = malloc(sizeof(Node));
						pomocna2 = malloc(sizeof(Node));
						strncpy(new->symbol, "*",sizeof(new->symbol));;
						strncpy(pomocna->symbol,"sin",sizeof(new->symbol));
						pomocna->left = root->left;
						pomocna ->right = NULL;
						pomocna->parent = pomocna2;
						strncpy(pomocna2->symbol,"(-)",sizeof(new->symbol));
						pomocna2->right = NULL;
						pomocna2->left = pomocna;
						pomocna2->parent = new;
						new->right = pomocna2;
						new->left = tmp1;
					
					}
					push(stack, new);
				}
				}else{
				tmp1 = pop(stack);
				tmp2 = pop(stack);
				if(root->symbol[0] == '-'){
					if((tmp1->symbol[0]=='0' && tmp2->symbol[0] == '0')||(tmp1->symbol[0]=='1' && tmp2->symbol[0] == '1')){
						strncpy(new->symbol, "0",sizeof(new->symbol));;
						new->left = NULL;
						new->right = NULL;
						free(tmp1);
						free(tmp2);
					}else if(tmp1->symbol[0]=='0'){
						new = tmp2;
						free(tmp1);
					}else if(tmp2->symbol[0]=='0'){
						pomocna = malloc(sizeof(Node));
						pomocna = tmp1;
						pomocna->parent = new;
						strncpy(new->symbol,"(-)",sizeof(new->symbol));
						new->left = pomocna;
						new->right = NULL;
						free(tmp2);
					}else{
						strncpy(new->symbol, "-",sizeof(new->symbol));;
						new->left = tmp2;
						new->right = tmp1;
					}
					push(stack,new);
				}else if(root->symbol[0] == '+'){
					if(tmp1->symbol[0]=='0' && tmp2->symbol[0] == '0'){
						strncpy(new->symbol, "0",sizeof(new->symbol));;
						new->left = NULL;
						new->right = NULL;
						free(tmp1);
						free(tmp2);
					}else if(tmp1->symbol[0]=='0'){
						new = tmp2;
						free(tmp1);
					}else if(tmp2->symbol[0]=='0'){
						new = tmp1;
						free(tmp2);
					}else{
						strncpy(new->symbol, "+",sizeof(new->symbol));;
						new->left = tmp2;
						new->right = tmp1;
					}
					push(stack,new);
				
				}else if(root->symbol[0] == '*'){
					if(tmp1->symbol[0]=='0' && tmp2->symbol[0] == '0'){
						strncpy(new->symbol, "0",sizeof(new->symbol));
						new->left = NULL;
						new->right = NULL;
					}else if(tmp1->symbol[0]=='0'){
						if(tmp2->symbol[0]=='1'){
							if(root->right){
								new = root->right;
							}else{
								printf("greska 786\n");
							}
							
						}else{
							strncpy(new->symbol, "*",sizeof(new->symbol));
							if(root->right){
								new->right = root->right;
							}else{
								printf("greska 786\n");
							}
							if(tmp2){
								new->left = tmp2; 
							}else{
								printf("greska 799\n");
							}
							
						}
					}else if(tmp2->symbol[0]=='0'){
						if(tmp1->symbol[0]=='1'){
							char ghg[4];
							if(root){
									if(root->left){
								strcpy(ghg,root->left->symbol);
								
							}else{
								printf("greska808\n");
							}
							}
						
							strncpy(new->symbol, ghg,4);
							new->left = NULL;
							new->right = NULL;
						}else{
							strncpy(new->symbol, "*",sizeof(new->symbol));
							if(root->right){
								new->left = root->right;
							}else{
								printf("greska 786\n");
							}
							
							new->right = tmp1; 
						}
						
					}else{
						pomocna = malloc(sizeof(Node));
						pomocna2 = malloc(sizeof(Node));
						pomocna->left = NULL;
						pomocna->right = NULL;
						pomocna2->left = NULL;
						pomocna2->right = NULL;
						strncpy(new->symbol, "+",sizeof(new->symbol));
						new->left = pomocna;
						new->right = pomocna2;
						pomocna->parent = new;
						pomocna2->parent = new;
						pomocna->left = tmp2;
						if(root->right){
								pomocna->right = root->right;
							}else{
								printf("greska 786\n");
							}
						
						pomocna2->left = tmp1;
						if(root->left){
								pomocna2->right = root->left;
							}else{
								printf("greska 786\n");
							}
						
						strncpy(pomocna->symbol,"*",4);
						strncpy(pomocna2->symbol,"*",4);
					}
				
					push(stack,new);
					
				}else if(root->symbol[0] == '/'){
					if(tmp2->symbol[0]=='0' && tmp1->symbol[0]=='0'){
						strncpy(new->symbol, "0",sizeof(new->symbol));
						new->left = NULL;
						new->right = NULL;
					}else if(tmp1->symbol[0] == '0'){
						strncpy(new->symbol, "/",sizeof(new->symbol));
						new->left = tmp2;
						new->right = root->right;
						
					}else if(tmp2->symbol[0]=='0'){
						pomocna = malloc(sizeof(Node));
						pomocna2 = malloc(sizeof(Node));
						pomocna3 = malloc(sizeof(Node));
						strncpy(new->symbol, "/",sizeof(new->symbol));
						new->left = pomocna;
						new->right = pomocna2;
						pomocna->parent = new;
						pomocna2->parent = new;
						pomocna->left = pomocna3;
						pomocna->right = NULL;
						pomocna2->left = root->right;
						pomocna2->right = root->right;
						strncpy(pomocna->symbol,"(-)",sizeof(new->symbol));
						strncpy(pomocna2->symbol,"*",sizeof(new->symbol));
						pomocna3->parent = pomocna;
						strncpy(pomocna3->symbol,"*",sizeof(new->symbol));
						pomocna3->left = tmp1;
						pomocna3->right = root->left;
					}else{
						pomocna = malloc(sizeof(Node));
						pomocna2 = malloc(sizeof(Node));
						pomocna3 = malloc(sizeof(Node));
						pomocna4 = malloc(sizeof(Node));
						strncpy(new->symbol, "/",sizeof(new->symbol));
						new->left = pomocna;
						new->right = pomocna2;
						pomocna->parent = new;
						pomocna2->parent = new;
						pomocna->right = pomocna3;
						pomocna->left = pomocna4;
						pomocna2->left = root->right;
						pomocna2->right = root->right;
						strncpy(pomocna->symbol,"-",sizeof(new->symbol));
						strncpy(pomocna2->symbol,"*",sizeof(new->symbol));
						pomocna3->parent = pomocna;
						strncpy(pomocna3->symbol,"*",sizeof(new->symbol));
						pomocna3->left = tmp1;
						pomocna3->right = root->left;
						pomocna4->parent = pomocna;
						strncpy(pomocna4->symbol,"*",sizeof(new->symbol));
						pomocna4->left = tmp2;
						pomocna4->right = root->right;
					}
					push(stack,new);
				}else if(root->symbol[0] == '^'){
					if(tmp2->symbol[0]=='0' && tmp1->symbol[0]=='0'){
						strncpy(new->symbol, "0",sizeof(new->symbol));
						new->left = NULL;
						new->right = NULL;
					}else if(tmp1->symbol[0] == '0'){
						strncpy(new->symbol, "*",sizeof(new->symbol));
						pomocna = NULL;
						pomocna = malloc(sizeof(Node));
						pomocna2 = NULL;
						pomocna2 = malloc(sizeof(Node));
						pomocna3 = NULL;
						pomocna3 = malloc(sizeof(Node));
						if(!(pomocna && pomocna2 &&pomocna3)){
							printf("greska u alokaciji");
							return NULL;
						}
						
					
						strncpy(pomocna->symbol,"-",sizeof(new->symbol));
						strncpy(pomocna2->symbol,"^",sizeof(new->symbol));
						if(root->right){
							new->left = root->right;
						}else{
							printf("Nema roota\n");
						}
						
						

						if(tmp2->symbol[0]=='1'){
							new->right = pomocna2;
							pomocna2->parent = new;
						
						}else{
							pomocna4 = malloc(sizeof(Node));
							strncpy(pomocna4->symbol,"*",sizeof(new->symbol));
							new->right = pomocna4;
							pomocna4->right = pomocna2;
							pomocna4->left = tmp2;
							pomocna2->parent = pomocna4;
							pomocna4->parent = new;
				
							
						}
				
						pomocna2->right = pomocna;
						pomocna2->left = root->left;
						
						pomocna->parent = pomocna2;
					
						
						pomocna->left = root->right;
						pomocna->right = pomocna3;
				
						pomocna3->parent = pomocna;
						pomocna3->left = NULL;
						pomocna3->right = NULL;
						strncpy(pomocna3->symbol,"1",sizeof(new->symbol));
				
					}else if(tmp2->symbol[0]=='0'){
						//nije nua nego ln
						if(tmp1->symbol[0]=='1'){
								pomocna2 = malloc(sizeof(Node));
								if(!(pomocna2)){
									printf("greska u alokaciji");
									return NULL;
								}
								strncpy(new->symbol, "*",sizeof(new->symbol));
								strncpy(pomocna2->symbol, "ln",sizeof(new->symbol));
								new->right = root;
								new->left = pomocna2;
								pomocna2->right = NULL;
								if(root->left){
									pomocna2->left = root->left;
								}else{
									printf("nema leve^\n");
									return NULL;
								}
								
								pomocna2->parent = new;
						}else{
							pomocna = malloc(sizeof(Node));
							pomocna2 = malloc(sizeof(Node));
							pomocna3 = malloc(sizeof(Node));
							if(!(pomocna && pomocna2 &&pomocna3)){
								printf("greska u alokaciji959\n");
								return NULL;
							}
							strncpy(new->symbol, "*",sizeof(pomocna2->symbol));
							strncpy(pomocna->symbol, "*",sizeof(pomocna2->symbol));
							strncpy(pomocna2->symbol, "ln",sizeof(pomocna2->symbol));
							new->left = tmp1;
							new->right = pomocna;
							pomocna->parent = new;
							pomocna->left = pomocna2;
							pomocna->right = root;
							pomocna2->right = NULL;
							if(root->left){
								pomocna2->left = root->left;
							}else{
								printf("greska974\n");
								return NULL;
							}
							
							pomocna2->parent = pomocna;
						}
						}else{
							//nema x^x
							new->right = NULL;
							new->left = NULL;
							strncpy(new->symbol, "0",sizeof(new->symbol));
						}
					push(stack,new);

				}else{
				
				}
		
			}
		
			root = NULL;
		
			//printStack(stack);
			//printf("\n\n");
        } //kraj elsa
    }while(*top); 

    Node *tmp;

    tmp = pop(stack);
  
 
    return tmp;
} 
const char *meni = "\
Izaberite zeljenu opciju:\n\n\
\
1.Unesi izraz i formiraj stablo\n\
2.Isprintaj stablo\n\
3.Ispisi u postfiksnoj notaciji\n\
4.Izracunaj vrednost izraza\n\
5.Nadji prvi izvod\n\
6.Izadji\n\n";


int main(int argc, char *argv[]) {
printf("Aleksa Racic 0728/19. Prefiksna notacija, dodatne funkcije: ln, sin, cos\n\nProsirite ekran kako bi stalo stablo\n\n\n");
int n;
Node *root, *dRoot;

char expression[MAX_STR];
while(1){
	printf("%s",meni);
	scanf("%d", &n);
	
	switch(n){
		case 1:
			printf("Unesite izraz\n\n");
			fflush(stdin);
			fgets(expression,MAX_STR,stdin);
			root = parse_expression(expression);
			break;
		case 2:
			printTree(root);
			break;
		case 3:
			printPostorder(root);
			break;
		case 4:
			evaluate(root);
			break;
		case 5:
			dRoot = differentiate(root);
			printTree(dRoot);
			
			break;
		case 6:
			return 0;
			break;
		
		default:
			printf("\nUnesite broj 1-6\n\n");
			break;
	}
}
	return 0;
}
