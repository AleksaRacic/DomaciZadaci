#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

int generateRand(int mini, int max);
int min(int a, int b);
int max(int a, int b);



class Matrica {

private:
	

public:
	int** matrica;
	int broj_vrsta, broj_kolona;

	Matrica() {

	};

	Matrica(int br_vrsta, int br_kolona) {
		broj_vrsta = br_vrsta;
		broj_kolona = br_kolona;

		matrica = new int*[broj_vrsta];
		for (int i = 0; i < broj_vrsta; i++) {
			matrica[i] = new int[broj_kolona];
		}

	}
	~Matrica() {
		//unisti();
		//delete matrica;
		//cout << "Matrica izbrisana\n";
	}
	void unisti() {
		if (matrica) {
			for (int i = 0; i < broj_vrsta; i++) {
				delete matrica[i];
			}
		}
		
	}

	void resize(int br_vrsta, int br_kolona) {

		unisti();

		broj_vrsta = br_vrsta;
		broj_kolona = br_kolona;

		matrica = new int*[broj_vrsta];
		for (int i = 0; i < broj_vrsta; i++) {
			matrica[i] = new int[broj_kolona];
		}

	}

	void ispisi() {
		for (int i = 0; i < broj_vrsta; i++) {
			for (int j = 0; j < broj_kolona; j++) {
				cout << matrica[i][j] << " ";
			}
			cout << endl;
		}
	}

	void generisi(int min_broj, int max_broj) {
		for (int i = 0; i < broj_vrsta; i++) {
			for (int j = 0; j < broj_kolona; j++) {
				if (i == 0 && j == 0) {
					matrica[i][j] = generateRand(max_broj-10, max_broj);

				}
				else if (i == 0) {
					matrica[i][j] = generateRand(min_broj, matrica[i][j - 1]);
				}
				else if (j == 0) {
					matrica[i][j] = generateRand(min_broj, matrica[i - 1][j]);
				}
				else {
					matrica[i][j] = generateRand(min_broj, min(matrica[i - 1][j], matrica[i][j - 1]));
				}

			}
		}
	}

	void unesi() {
		for (int i = 0; i < broj_vrsta; i++) {
			for (int j = 0; j < broj_kolona; j++) {
				cin >> matrica[i][j];
			}
		}

	}

	int find(int key) {
		int br_provera=0;

		for (int i = 0; i < broj_vrsta; i++) {
			br_provera++;
			if (matrica[i][0] < key) {
				break;
			}
			br_provera--;
			for (int j = 0; j < broj_kolona; j++) {
				br_provera++;
				if (matrica[i][j] >= key) {
					if (matrica[i][j] == key) {
						cout << "Pronadjeno na poziciji " << i << "," << j << endl;
						return br_provera;
					}

				}
				else {
					break;
				}
			}

		}
		return 0;
	}
};

typedef struct node1{
	int key;
	int balance;
	struct node1 *left, *right;
}Node;

Node *initNode(int key) {
	Node *nod = new Node;
	nod->key = key;
	nod->left = nullptr;
	nod->right = nullptr;
	nod->balance = 0;
	return nod;
}

int treeDepth(Node *root) {
	int left = -1;
	int right = -1;
	if (root->left!=nullptr) {
		left = treeDepth(root->left) + 1;
	}
	else {
		left = 1;
	}
	if (root->right!=nullptr) {
		right = treeDepth(root->right) + 1;
	}
	else {
		right = 1;
	}
	return max(left, right);
}

int brojback(int n) {
	int brojac = 0;
	while (n) {
		n = n / 10;
		brojac++;
	}
	return brojac / 2;
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

class AVLtree {
private:
	Node *AVL;
public:
	AVLtree() {
		AVL = nullptr;
	}
	void rotateRight(Node *x) {
		Node *y = x->left;
		Node *temp = y->right;
		y->right = x;
		x->left = temp;
		//cout << "\n rotated right \n";
	}
	
	void rotateLeft(Node *x) {
		Node *y = x->right;
		Node *temp = y->left;
		y->left = x;
		x->right = temp;
		//cout << "\n rotated left \n";

	}
	void ispisi() {
		Node *root = AVL;
		Node *node;
		int i, j, k, broj, prethodni;
		int brCvorova = 1;
		queue<Node*> red;
		red.push(root);
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
						printf(" ");
					}
					node = red.front();
					red.pop();
					if (node) {
						if (node->left) {

							red.push(node->left);
						}
						else {
							red.push(nullptr);
						}
						if (node->right) {
							red.push(node->right);
						}
						else {
							red.push(nullptr);
						}
						int back = brojback(node->key);
						for (int i = 0; i < back; i++) {
							cout << "\b";
						}
						cout << node->key;
						//cout << "(" << node->balance;
					}
					else {
						printf(" ");
						red.push(nullptr);
						red.push(nullptr);
					}

					for (j = 0; j <= i; j++) {
						printf(" ");
					}

				}

				brCvorova = brCvorova * 2;
				prethodni = i;
			}
			else {
				for (k = 0; k<brCvorova / 2; k++) {
					node = red.front();
					red.pop();
					if (node) {
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
					red.push(node);
					node = red.front();
					red.pop();
					if (node) {
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
					red.push(node);
				}


			}
			printf("\n");
		}

		printf("\n\n");
	}



	void insert(int key) {
		if (AVL==nullptr) {
			AVL = initNode(key);
		}
		else {
			Node *prethodni_p = nullptr, *prethodni_x = nullptr;
			Node *p = AVL;
			Node *x = p;
			Node *q, *y;
			int imbal;
			while (p != nullptr) {
				if (key < p->key) {
					q = p->left;
				}
				else {
					q = p->right;
				}
				if (q != nullptr) {
					if (q->balance != 0) {
						prethodni_x = p;
						x = q;
					}
				}
				prethodni_p = p;
				p = q;
			}
			q = initNode(key);
			if (key < prethodni_p->key) {
				prethodni_p->left = q;
			}
			else {
				prethodni_p->right = q;
			}

			if (key < x->key) {
				p = x->left;
			}
			else {
				p = x->right;
			}
			y = p;
			//cout << "\n\n pre rotacije\n";
			//ispisi();
			while (p != q) {
				if (key < p->key) {
					p->balance = 1;
					p = p->left;
				}
				else {
					p->balance = -1;
					p = p->right;
				}
			}

			if (key < x->key) {
				imbal = 1;
			}
			else {
				imbal = -1;
			}

			if (x->balance == 0) {
				x->balance = imbal;
				return;
			}
			if (x->balance != imbal) {
				x->balance = 0;
				return;
			}

			if (y->balance == imbal) {
				p = y;
				if (imbal == 1) {
					rotateRight(x);
				}
				else {
					rotateLeft(x);
				}
				x->balance = y->balance = 0;
			}
			else {
				if (imbal == 1) {
					p = y->right;
					rotateLeft(y);
					x->left = p;
					rotateRight(x);
				}
				else {
					p = y->left;
					x->right = p;
					rotateRight(y);
					rotateLeft(x);
				}
				if (p->balance == 0) {
					x->balance = y->balance = 0; 
				}
				else {
					if (p->balance == imbal) {
						x->balance = -imbal;
						y->balance = 0;
					}
					else {
						x->balance = 0;
						y->balance = imbal;
					}
					p->balance = 0;
				}
			}
			if (prethodni_x == nullptr) {
				AVL = p;
			}
			else {
				if (x == prethodni_x->right) {
					prethodni_x->right = p;
				}
				else {
					prethodni_x->left = p;
				}
			}
		}
	}

	void ucitajMatrcu(Matrica matrica) {
		//izbrisati prethodno drvo
		for (int i = 0; i < matrica.broj_vrsta; i++) {
			for (int j = 0; j < matrica.broj_kolona; j++) {
				insert(matrica.matrica[i][j]);
				//cout << " \nposle rotacije \n";
				//ispisi();
			}
		}
	}
	void del() {
		AVL = nullptr;
	}

	int find(int key) {
		Node *p = AVL;
		int broj = 0;
		while (p != nullptr) {
			broj++;
			if (key == p->key) {
				cout << "pronadjen kljuc " << key<<endl;
				return broj;
			}
			if (key < p->key) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		cout << "kljuc nije pronadjen" << endl;
		return 0;
	}
};

int max(int a, int b) {
	return a>b ? a:b;
}

void meni() {
	cout << "Aleksa Racic 19/0728 \n \
1. Unos matrice \n \
2. Generisanje matrice\n \
3. Pretraga matrice\n \
4. Evaluacija performansi\n \
5. Pretvoriti matricu u AVL stablo \n \
6. Pretraga stabla \n \
7. Umetanje kljuca \n \
8. Ispis stabla \n \
9. Poredjenje performansi \n \
10. Izlaz\n";
}

int min(int a, int b) {
	return a < b ? a : b;
}

int generateRand(int mini, int max) {
	if (mini == max)
		return 1;
	int b = rand();
	int c = b % (max-mini);
	int a = c + mini;
	
	return a;
}

int *generateArray(int min_, int max_) {
	int *array_ = new int[max_ - min_+1];
	for (int i = min_-1; i < max_; i++) {
		array_[i] = i;
	}
	return array_;
}

int main() {
	int min_, max_, tmp;
	int* niz;
	int ulaz;
	int broj_vrsta, broj_kolona;
	srand(2345123453);
	int broj_nalazenja;
	double prosek;
	Matrica matrica;
	AVLtree AVL;
	meni();
	int broj_nalazenjaMat = 0;
	int broj_nalazenjaAVL = 0;

	double prosekMat;
	double prosekAVL;

	int nalazenjaMat = 0;
	int nalazenjaAVL = 0;
	int key;
	int nalazenja = 0;
	do {
		cin >> ulaz;
		switch (ulaz) {
		case 1:
			
			cout << "Unesi broj kolona i broj vrsta\n";
			cin >> broj_vrsta >> broj_kolona;
			matrica.resize(broj_vrsta, broj_kolona);
			matrica.unesi();
			matrica.ispisi();
			break;
		case 2:
			cout << "Unesi broj kolona i broj vrsta\n";
			cin >> broj_vrsta >> broj_kolona;
			int maxbroj;
			cout << "Unesi maksimalan broj\n";
			cin >> maxbroj;
			matrica.resize(broj_vrsta, broj_kolona);
			
			matrica.generisi(1, maxbroj);
			matrica.ispisi();

			
			

			break;
		case 3:
			int key;
			cout << "Unesi kljuc" << endl;
			cin >> key;
			matrica.find(key);

			break;
		case 4:
			cout << "Unesite opseg, min max\n";
			cin >> min_ >> max_;
			broj_nalazenja = 0;
			niz = generateArray(min_,max_);

			nalazenja = 0;
			for (int i = 0; i < max_ - min_; i++) {
				tmp = matrica.find(niz[i]);
				if (tmp) {
					broj_nalazenja += tmp;
					nalazenja++;
				}
			}
			prosek = (double)broj_nalazenja / (double)(nalazenja);
			cout << "prosek je " << prosek;
			break;
		case 5:
			AVL.del();
			AVL.ucitajMatrcu(matrica);
			//AVL.ispisi();
			cout << "Stablo je formirano\n";
			break;
		case 6:
			cout << "Unesite kljuc" << endl;
			cin >> key;
			AVL.find(key);
			break;
		case 7:
			cout << "Unesite kljuc" << endl;
			cin >> key;
			AVL.insert(key);
			break;
		case 8:
			AVL.ispisi();
			break;
		case 9:

			cout << "Unesite opseg, min max\n";
			cin >> min_ >> max_;
			broj_nalazenjaMat = 0;
			broj_nalazenjaAVL = 0;

			prosekMat;
			prosekAVL;

			nalazenjaMat = 0;
			nalazenjaAVL = 0;
			niz = generateArray(min_, max_);

			
			for (int i = 0; i < max_ - min_; i++) {
				tmp = matrica.find(niz[i]);
				if (tmp) {
					broj_nalazenjaMat += tmp;
					nalazenjaMat++;
				}
				tmp = AVL.find(niz[i]);
				if (tmp) {
					broj_nalazenjaAVL += tmp;
					nalazenjaAVL++;
				}
			}
			prosekMat = (double)broj_nalazenjaMat / (double)(nalazenjaMat);
			prosekAVL = (double)broj_nalazenjaAVL / (double)(nalazenjaAVL);

			cout << "prosek za matricu:  " << prosekMat<<endl;
			cout << "prosek za AVL: " << prosekAVL << endl;
			break;
		case 10:
			break;
		default:
			cout << "\nUnesite broj u opsegu 1-6 \n";
		}
	} while (ulaz != 10);

	return 0;
}