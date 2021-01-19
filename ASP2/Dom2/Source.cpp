#include <stack>
#include <iostream>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

const string RED = "\033[31m";
const string RESET = "\033[0m";
const string WHITE = "\033[37m";

typedef struct key {
	char action[256];
	int priority;
}*Key;


typedef struct node{ 
	Key keys[4];
	struct node  *pointers[5];
	int m = 0; //broj cvorova ne grananje
	node() {
		for (int i = 0; i < 5; i++) {
			pointers[i] = nullptr;
		}
	}
}*Node;


typedef struct binNode {
	Node node;
	int index;
	string color;
	struct binNode* left;
	struct binNode* right;
}*BinNode;

void del(Node nod) {
	delete nod;
}

void preorder(Node root, void(*funct)(Node)) {
	stack<Node> st;
	Node tmp;
	st.push(root);
	while (!st.empty()) {
		tmp = st.top();
		st.pop();
		for (int i = 0; i < tmp->m; i++) {
			if (tmp->pointers[i]) {
				st.push(tmp->pointers[i]);
			}
		}
		funct(tmp);
	}
	
}
struct ret {
	Node node;
	Key key;
};
class Tree {
private:
	Node root;
	ret insert_key(Key, Node, Node);
	int find_left(Node, Node);
	int find_right(Node, Node);
	int height_234;
	//int height_bin;
public:
	bool print_bin = false;
	Tree();
	~Tree();
	void find_priority(int);
	void insert(Key);
	void del_priority(int);
	void fix_tree(stack<Node>);
	void del_max();
	friend ostream &operator<<(ostream&, const Tree&);
	void printBin()const;
	void print234()const;
	void findAndReplace(int, char*, int);
	int findNumOfPr(int);
};

Tree::Tree() {
	root = nullptr;
}

Tree::~Tree() {
	preorder(root, del);
	cout << "Izbrisano stablo\n";
}

void Tree::find_priority(int n) {
	Node cur = root;
	while (cur != nullptr) {
		for (int i = 0; i < cur->m; i++) {
			if (cur->keys[i]->priority == n) {
				cout << cur->keys[i]->priority << " " << cur->keys[i]->action << endl;
				return;
			}
			if (cur->keys[i]->priority > n) {
				cur = cur->pointers[i];
				break;
			}
		}
		cur = cur->pointers[cur->m];
	}
	cout << "Nema akcije sa zadatim prioritetom\n";
}

ret Tree::insert_key(Key key, Node node, Node pok) {
	ret tmp;
	tmp.node = nullptr;
	int n = node-> m;
	int i;
	for (i = 0; i < node->m; i++) {
		if (key->priority < node->keys[i]->priority || (key->priority == node->keys[i]->priority && strcmp(node->keys[i]->action, key->action)>0)) {
			node->pointers[n+1] = node->pointers[n];
			node->m++;
			for (int j = n; j > i; j--) {
				node->keys[j] = node->keys[j-1];
				node->pointers[j] = node->pointers[j - 1];

			}
			//desni splitovan cvor
			node->keys[i] = key;
			node->pointers[i+1] = pok;
			//skontati sta se ovde desava
			break;
		}
		
	}
	if (n == node->m) {
		node->keys[n] = key;
		node->m++;
		node->pointers[node->m] = pok;
	}
	if (node->m > 3) {
		if (key->priority < node->keys[2]->priority || (key->priority == node->keys[2]->priority && strcmp(node->keys[2]->action, key->action)>0)) {
			tmp.key = node->keys[2];
			Node node2 = new struct node;
			node2->keys[0] = node->keys[3];
			node2->pointers[0] = node->pointers[3];
			node2->pointers[1] = node->pointers[4];
			node2->m = 1;
			node->m = 2;
			tmp.node = node2;
		}
		else {
			tmp.key = node->keys[1];
			Node node2 = new struct node;
			node2->keys[0] = node->keys[2];
			node2->keys[1] = node->keys[3];
			node2->pointers[0] = node->pointers[2];
			node2->pointers[1] = node->pointers[3];
			node2->pointers[2] = node->pointers[4];
			node2->m = 2;
			node->m = 1;
			tmp.node = node2;
		}
		
	}
	return tmp;
}

void Tree::insert(Key key) {
	ret tmp;
	Node cur = root;
	stack<Node> st;
	bool odradjeno = false;
	if (root == nullptr) {
		root = new struct node;
		root->m++;
		root->keys[0] = key;
		height_234 = 1;
		return;
	}
	while (cur != nullptr) {
		st.push(cur);
		odradjeno = false;
		for (int i = 0; i < cur->m; i++) {
			if (cur->keys[i]->priority > key->priority ||(cur->keys[i]->priority == key->priority && strcmp(cur->keys[i]->action, key->action)>0)) {
				odradjeno = true;
				cur = cur->pointers[i];
				break;
			}
		}
		if (!odradjeno) {
			cur = cur->pointers[cur->m];
		}
		

	}

	cur = st.top();

	st.pop();
	tmp = insert_key(key, cur,nullptr);
	while (tmp.node != nullptr) {
		if (!st.empty()) {
			cur = st.top();
			st.pop();
			tmp = insert_key(tmp.key, cur, tmp.node);
		}
		else {
			Node root2 = new struct node;
			root2->m = 1;
			root2->keys[0] = tmp.key;
			root2->pointers[0] = root;
			root2->pointers[1] = tmp.node;
			root = root2;
			height_234++;
			tmp.node = nullptr;
			//height_bin++;
			//proveriti ovo
		}
	}
	//print234();
}

int Tree::find_left(Node cur, Node par) {
	int tmp;
	for (int i = 1; i < par->m+1; i++) {
		if (par->pointers[i] == cur) {
			tmp = i - 1;
			return tmp;
		}
	}
	return -1;
}

int Tree::find_right(Node cur, Node par) {
	for (int i = 0; i < par->m; i++) {
		if (par->pointers[i] == cur) {
			return i + 1;
		}
	}
	return -1;
}

void Tree::fix_tree(stack<Node> st) {
	Node cur;
	Node parent;
	Node left;
	Node right;
	int tmp;
	if (st.empty()) {
		return;
	}
	cur = st.top();
	st.pop();
	while (cur->m == 0) {
		if (st.empty()) {
			delete root;
			height_234--;
			root = cur;
		}
		else {
			parent = st.top();
			st.pop();
			tmp = find_right(cur, parent); // ukljucuje m
			if (tmp != -1) {
				if ((right = parent->pointers[tmp]) != nullptr && right->m > 1) {
					cur->keys[0] = parent->keys[tmp - 1];
					cur->pointers[0] = cur->pointers[1];
					cur->pointers[1] = right->pointers[0];
					cur->m++;
					parent->keys[tmp - 1] = right->keys[0];
					for (int i = 0; i < right->m - 1; i++) {
						right->keys[i] = right->keys[i + 1];
					}
					right->m--;
					return;
				}
				
			
			}
			//left rotation
			if ((tmp = find_left(cur, parent)) != -1) {
				if ((left = parent->pointers[tmp]) != nullptr && left->m > 1) {
					cur->keys[0] = parent->keys[tmp];
					cur->pointers[1] = cur->pointers[0];
					cur->pointers[0] = left->pointers[left->m];
					cur->m++;
					parent->keys[tmp] = left->keys[left->m - 1];
					left->m--;
					return;
					
				}
				

			}
			
			//merge
			if ((tmp = find_right(cur, parent)) != -1) {
				right = parent->pointers[tmp];
				cur->keys[0] = parent->keys[tmp - 1];
				cur->keys[1] = right->keys[0];
				cur->pointers[1] = right->pointers[0];
				cur->pointers[2] = right->pointers[1];
				for (int i = tmp - 1; i < parent->m-1; i++) {
					parent->keys[i] = parent->keys[i + 1];
					parent->pointers[i + 1] = parent->pointers[i + 2];
				}
				parent->m--;
				cur->m += 2;
				delete right;
			}
			else {
				parent->pointers[tmp - 1] = nullptr;
				delete cur;
			}

			

			//priprema za sledeci korak
			cur = parent;
		}
	}
}

void Tree::del_priority(int p) {
	stack <Node> st;
	Node cur = root;
	bool uradio;
	while (cur != nullptr) {
		uradio = false;
		st.push(cur); // pratimo put do cvora
		for (int i = 0; i < cur->m; i++) {
			if (cur->keys[i]->priority == p) {
				//////////
				delete cur->keys[i];
				///////////
				if (cur->pointers[i+1] == nullptr) {
					for (int j = i; j < cur->m - 1; j++) {
						cur->keys[j] = cur->keys[j + 1];
						cur->pointers[j + 1] = cur->pointers[j + 2];
					}
					cur->m = cur->m - 1;
				}
				else {
					Node tmp_Node = cur;
					int tmp_i = i;
					cur = cur->pointers[i + 1];
					while (cur != nullptr) {
						st.push(cur);
						cur = cur->pointers[0];
						
					}
					cur = st.top();
					tmp_Node->keys[i] = cur->keys[0];
					for (int ij = 0; ij < cur->m-1; ij++) {
						cur->keys[ij] = cur->keys[ij + 1];
						cur->pointers[ij] = cur->pointers[ij + 1];
					}
					cur->pointers[cur->m - 1] = cur->pointers[cur->m];
					cur->m--;
				}
				//print234();
				fix_tree(st);
				cout << "Izbrisano\n";
				return;
			}
			else if (cur->keys[i]->priority > p) {
				cur = cur->pointers[i];
				uradio = true;
				break;
			}
		}
		if (!uradio) {
			cur = cur->pointers[cur->m];
		}
		
	}
	cout << "Ne postoji prioritet\n";
}

void Tree::del_max() {
	stack<Node> st;
	Node cur = root;
	while (cur != nullptr) {
		st.push(cur);
		cur = cur->pointers[cur->m];
	}
	cur = st.top();
	delete cur->keys[cur->m - 1];
	cur->m--;
	fix_tree(st);
}
int maxi(int a, int b) {
	return (a > b ? a : b);
}
int treeDepth(Node root) {
	if (root == nullptr) return 1;
	int prev = 1;
	for (int i = 0; i < root->m + 1; i++) {
		prev = maxi(prev, treeDepth(root->pointers[i]));
	}
	if (root->m > 1) {
		return prev + 2;
	}
	else {
		return prev + 1;
	}
}
int brojback (string n) {
	return ((((int)n.length()) + 2) / 2);
}

int pHigh(int n) {
	int i;
	int visina = 2;
	if (n == 1) {
		visina = 1;
	}

	for (i = 2; i<n; i++) {
		visina = 2 * visina + 1;
	}
	return visina;
}




void Tree::printBin() const {
	
	int i, j, k, broj, prethodni,back;
	int brCvorova = 1;

	queue<BinNode> red;

	BinNode bNode = new struct binNode;
	BinNode tmp;
	BinNode tmpNode = new struct binNode;
	BinNode realNode;

	bNode->node = root;
	bNode->color = WHITE;
	
	if (root->m == 3) {
		bNode->index = 1;
		tmp = new binNode;
		tmp->node = root;
		tmp->index = 0;
		tmp->color = RED;
		bNode->left = tmp;

		tmp = new binNode;
		tmp->node = root;
		tmp->index = 2;
		tmp->color = RED;
		bNode->right = tmp;
	}
	else if (root->m == 2) {
		bNode->index = 1;
		tmp = new binNode;
		tmp->node = root;
		tmp->index = 0;
		tmp->color = RED;
		bNode->left = tmp;
		if (bNode->node->pointers[bNode->node->m] != nullptr) {
			bNode->right = new struct binNode;
			bNode->right->node = bNode->node->pointers[bNode->node->m];
			bNode->right->color = WHITE;
			bNode->right->index = bNode->right->node->m > 1 ? 1 : 0;
		}
		else {
			bNode->right = nullptr;
		}
		

	}
	else {
		bNode->index = 0;
		if (bNode->node->pointers[0] != nullptr) {
			bNode->left = new binNode;
			bNode->left->node = bNode->node->pointers[0];
			bNode->left->index = (bNode->left->node->m > 1 ? 1 : 0);
			bNode->left->color = WHITE;

		}
		else {
			bNode->left = nullptr;
		}

		if (bNode->node->pointers[1] != nullptr) {
			bNode->right = new binNode;
			bNode->right->node = bNode->node->pointers[1];
			bNode->right->index = (bNode->right->node->m > 1 ? 1 : 0);
			bNode->right->color = WHITE;

		}
		else {
			bNode->right = nullptr;
		}
	}

	red.push(bNode);
	int depth = treeDepth(root) + 1;
	broj = pHigh(depth);

	for (i = broj; i>1; i--) {
		if (i == broj) {
			broj = (broj + 1) / 2 - 1;

			if (red.empty()) {
				break;
			}
			for (k = 0; k<brCvorova; k++) {
				for (j = 0; j<i; j++) {
					cout<<" ";
				}
				bNode = red.front();
				red.pop();
				if (bNode!=nullptr) {
					if (bNode->left!=nullptr) {
						realNode = bNode->left;//ovo izmeniti za right
						
						if (realNode->color.compare(RED)==0) {
							if (realNode->node->pointers[realNode->index] != nullptr) {
								realNode->left = new struct binNode;
								realNode->left->node = realNode->node->pointers[realNode->index];
								if (realNode->left->node->m > 1) {
									realNode->left->index = 1;
									realNode->left->color = WHITE;
								}
								else {
									realNode->left->index = 0;
									realNode->left->color = WHITE;
								}
							}
							else {
								realNode->left = nullptr;
							}

							if (realNode->node->pointers[realNode->index+1] != nullptr) {
								realNode->right = new struct binNode;
								realNode->right->node = realNode->node->pointers[realNode->index+1];
								if (realNode->right->node->m > 1) {
									realNode->right->index = 1;
									realNode->right->color = WHITE;
								}
								else {
									realNode->right->index = 0;
									realNode->right->color = WHITE;
								}
							}
							else {
								realNode->right = nullptr;
							}

							
						}
						else {
							if (realNode->node->m == 1) {
								if (realNode->node->pointers[0] != nullptr) {
									realNode->left = new struct binNode;
									realNode->left->node = realNode->node->pointers[0];
									realNode->left->index = (realNode->left->node->m > 1 ? 1 : 0);
									realNode->left->color = WHITE;

								}
								else {
									realNode->left = nullptr;
								}

								if (realNode->node->pointers[1] != nullptr) {
									realNode->right = new struct binNode;
									realNode->right->node = realNode->node->pointers[0];
									realNode->right->index = (realNode->right->node->m > 1 ? 1 : 0);
									realNode->right->color = WHITE;

								}
								else {
									realNode->right = nullptr;
								}
							}
							else if (realNode->node->m > 1) {
								realNode->left = new struct binNode;
								realNode->left->node = realNode->node;
								realNode->left->index = 0;
								realNode->left->color = RED;
								if (realNode->node->m == 3) {
									realNode->right = new struct binNode;
									realNode->right->node = realNode->node;
									realNode->right->index = 2;
									realNode->right->color = RED;
								}
								else {
									if (realNode->node->pointers[2] != nullptr) {
										realNode->right = new binNode;
										realNode->right->node = realNode->node->pointers[2];
										realNode->right->index = (realNode->right->node->m > 1 ? 1 : 0);
										realNode->right->color = WHITE;

									}
									else {
										realNode->right = nullptr;
									}
								}
							}
						}
						red.push(realNode);
					}
					else {
						red.push(nullptr);
					}
					if (bNode->right != nullptr) {
						realNode = bNode->right;
						if (realNode->color == RED) {
							if (realNode->node->pointers[realNode->index] != nullptr) {
								realNode->left = new binNode;
								realNode->left->node = realNode->node->pointers[realNode->index];
								if (realNode->left->node->m > 1) {
									realNode->left->index = 1;
									realNode->left->color = WHITE;
								}
								else {
									realNode->left->index = 0;
									realNode->left->color = WHITE;
								}
							}
							else {
								realNode->left = nullptr;
							}

							if (realNode->node->pointers[realNode->index + 1] != nullptr) {
								realNode->right = new binNode;
								realNode->right->node = realNode->node->pointers[realNode->index + 1];
								if (realNode->right->node->m > 1) {
									realNode->right->index = 1;
									realNode->right->color = WHITE;
								}
								else {
									realNode->right->index = 0;
									realNode->right->color = WHITE;
								}
							}
							else {
								realNode->right = nullptr;
							}


						}
						else {
							//black
							if (realNode->node->m == 1) {
								if (realNode->node->pointers[0] != nullptr) {
									realNode->left = new binNode;
									realNode->left->node = realNode->node->pointers[0];
									realNode->left->index = (realNode->left->node->m > 1 ? 1 : 0);
									realNode->left->color = WHITE;

								}
								else {
									realNode->left = nullptr;
								}

								if (realNode->node->pointers[1] != nullptr) {
									realNode->right = new binNode;
									realNode->right->node = realNode->node->pointers[0];
									realNode->right->index = (realNode->right->node->m > 1 ? 1 : 0);
									realNode->right->color = WHITE;

								}
								else {
									realNode->right = nullptr;
								}
							}
							else if (realNode->node->m > 1) {
								realNode->left = new struct binNode;
								realNode->left->node = realNode->node;
								realNode->left->index = 0;
								realNode->left->color = RED;
								if (realNode->node->m == 3) {
									realNode->right = new struct binNode;
									realNode->right->node = realNode->node;
									realNode->right->index = 2;
									realNode->right->color = RED;
								}
								else {
									if (realNode->node->pointers[2] != nullptr) {
										realNode->right = new binNode;
										realNode->right->node = realNode->node->pointers[2];
										realNode->right->index = (realNode->right->node->m > 1 ? 1 : 0);
										realNode->right->color = WHITE;

									}
									else {
										realNode->right = nullptr;
									}
								}
							}
						}
						red.push(realNode);
					}
					else {
						red.push(nullptr);
					}

					back = brojback(bNode->node->keys[bNode->index]->action);
					for (int i = 0; i < back; i++) {
						cout << "\b";
					}
					
					cout << bNode->color;
					cout << bNode->node->keys[bNode->index]->priority << " " << bNode->node->keys[bNode->index]->action;
					//cout << "(" << node->balance;
					cout << RESET;
					delete bNode;
				}
				else {
					printf(" ");
					back = 0;
					red.push(nullptr);
					red.push(nullptr);
				}

				for (j = 0; j <= i-back; j++) {
					printf(" ");
				}

			}

			brCvorova = brCvorova * 2;
			prethodni = i;
		}
		else {
			for (k = 0; k<brCvorova / 2; k++) {
				bNode = red.front();
				red.pop();
				if (bNode) {
					for (j = 0; j<i; j++) {
						printf(" ");
					}
					printf("/ ");
					for (j = 0; j < 2 * (prethodni - i - 1); j++) {
						printf(" ");
					}


				}
				else {
					for (j = 0; j<2 * prethodni - i; j++) {
						printf(" ");
					}
				}
				red.push(bNode);
				bNode = red.front();
				red.pop();
				if (bNode) {
					printf("\\");
					for (j = 0; j <= i; j++) {
						printf(" ");
					}
				}
				else {
					for (j = 0; j <= i + 1; j++) {
						printf(" ");
					}
				}
				red.push(bNode);
			}


		}
		printf("\n");
	}

	printf("\n\n");
}


void Tree::print234() const{
	queue<Node> q;
	Node spaceNode = new struct node;
	Node boarder = new struct node;
	Node tmpNode;

	q.push(root);
	q.push(boarder);
	int counter = 0;
	for (int i = 0; i < (height_234 - counter-1) * 35; i++) {
		cout << " ";
	}
	while (counter < height_234) {
		tmpNode = q.front();
		q.pop();

		if (tmpNode == boarder) {
			counter++;
			q.push(boarder);
			cout << endl << endl;
			for (int i = 0; i < (height_234 - counter-1) * 35; i ++ ) {
				cout << " ";
			}
		}
		else if (tmpNode == nullptr) {
			cout << "|";
			for (int i = 0; i < 3; i++) {
				cout << "xxxx|";
			}
			cout << "  ";
			//ovde ce isto kasnije custom razmak
		}
		else if (tmpNode == spaceNode) {
			cout << "      ";
		}
		else {
			cout << "|";
			for (int i = 0; i < tmpNode->m; i++) {
				cout << tmpNode->keys[i]->priority << " " << tmpNode->keys[i]->action << "|";
				q.push(tmpNode->pointers[i]);
			}
			q.push(tmpNode->pointers[tmpNode->m]);
			for (int i = tmpNode->m; i < 3; i++) {
				cout << "xxxx|";
			}
			cout << "   ";
			q.push(spaceNode);
			//ovde ce kasnije custom razmak
		}
	}
}
ostream& operator<<(ostream& os, const Tree &obj) {
	if (obj.print_bin) {
		obj.printBin();
	}
	else {
		obj.print234();
	}
	return os;
}

void Tree::findAndReplace(int p, char *action, int newP) {
	stack <Node> st;
	Key ubaci;
	Node cur = root;
	bool uradio;
	while (cur != nullptr) {
		uradio = false;
		st.push(cur); // pratimo put do cvora
		for (int i = 0; i < cur->m; i++) {
			if (cur->keys[i]->priority == p && strcmp(action, cur->keys[i]->action)==0) {
				//////////
				delete cur->keys[i];
				///////////
				if (cur->pointers[i + 1] == nullptr) {
					for (int j = i; j < cur->m - 1; j++) {
						cur->keys[j] = cur->keys[j + 1];
						cur->pointers[j + 1] = cur->pointers[j + 2];
					}
					cur->m = cur->m - 1;
				}
				else {
					Node tmp_Node = cur;
					int tmp_i = i;
					cur = cur->pointers[i + 1];
					while (cur != nullptr) {
						st.push(cur);
						cur = cur->pointers[0];

					}
					cur = st.top();
					tmp_Node->keys[i] = cur->keys[0];
					for (int ij = 0; ij < cur->m - 1; ij++) {
						cur->keys[ij] = cur->keys[ij + 1];
						cur->pointers[ij] = cur->pointers[ij + 1];
					}
					cur->pointers[cur->m - 1] = cur->pointers[cur->m];
					cur->m--;
				}
				//print234();
				fix_tree(st);
				ubaci = new struct key;
				ubaci->priority = newP;
				strcpy_s(ubaci->action, action);
				insert(ubaci);
				cout << "Promenjeno\n";
				return;
			}
			else if (cur->keys[i]->priority > p || (p == cur->keys[i]->priority && strcmp(cur->keys[i]->action, action)>0)) {
				cur = cur->pointers[i];
				uradio = true;
				break;
			}
		}
		if (!uradio) {
			cur = cur->pointers[cur->m];
		}

	}
	cout << "Ne postoji akcija\n";
}

int Tree::findNumOfPr(int priority) {
	int counter = 0;
	stack<Node> st;
	Node tmp;
	st.push(root);
	while (!st.empty()) {
		tmp = st.top();
		st.pop();
		for (int i = 0; i < tmp->m+1; i++) {
			if (tmp->pointers[i]) {
				st.push(tmp->pointers[i]);
			}
		}
		for (int i = 0; i < tmp->m; i++) {
			if (tmp->keys[i]->priority == priority) {
				counter++;
			}
		}
	}
	return counter;
}

string meni = "meni\n1. Ubaci kljuc sa std ulaza\n2. Ispisi stablo\n3. Uneti kljuceve iz datoteke\n4. Izbrisati prioritet\n5. Izbrisati kljuc sa najvecim prioritetom\n\
6. Ispisi crveno-crno stablo\n7. Izmena prioriteta\n8. Broj kljuceva sa datim prioritetom\n9. Izlaz\n\n";

int main() {
	system("color");
	cout << meni;
	string datoteka;
	ifstream dat;
	char action[256];
	int opcija, prioritet, noviPrioritet;
	Tree drvo;
	struct key tmpKey;
	Key keyPointer;

	while (1) {
		cout << "Unesi opciju\n\n";
		cin >> opcija;
		switch(opcija) {
			case 1:
				keyPointer = new struct key;
				cout << "Unesite prioritet i akciju\n";
				cin >> keyPointer->priority >> keyPointer->action;
				

				drvo.insert(keyPointer);
				cout << "Kjuc unet\n";
			break;
			case 2:
				cout << drvo;
			break;
			case 3:
				cout << "Unsei ime datoteke\n";
				cin >> datoteka;
				dat.open(datoteka);
				if (!dat.is_open()) { cout << "Greska u citanju\n"; }
				else {
					while (!dat.eof()) {
						keyPointer = new struct key;
						dat >> keyPointer->priority >> keyPointer->action;
						drvo.insert(keyPointer);

					}
					cout << "Kljucevi uneti \n";
					dat.close();
				}
				
				
				break;

			case 4:
				cout << "Izaberi prioritet\n";
				cin >> prioritet;
				drvo.del_priority(prioritet);
				break;

			case 5:
				drvo.del_max();
				break;
			case 6:
				drvo.print_bin = true;
				cout << drvo;
				drvo.print_bin = false;
				break;
			case 7:
				cout << "Unesite kljuc koji treba izmeniti\n";
				cin >> prioritet >> action;
				cout << "Uneti novi prioritet\n";
				cin >> noviPrioritet;
				drvo.findAndReplace(prioritet, action, noviPrioritet);
				break;
			case 8:
				cout << "Uneti prioritet\n";
				cin >> prioritet;
				cout << drvo.findNumOfPr(prioritet)<<endl;
				break;
			case 9:
				return 0;
				break;
			default:
				cout << "Unesite 1-9\n";
				break;


		}
	}

}