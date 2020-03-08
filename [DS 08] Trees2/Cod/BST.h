#include "Alumno.c"

//arbol avl

typedef ALUMNO* item;

typedef struct node{
	item val;
	struct node *l, *r, *root;
	int BF;
}Node;

Node* createNode(item val, Node *root);
void rootInsert(Node **root, Node *parent, item val);
void balanceTree(Node **root);
int depth(Node *n);
void balFactor(Node *n);
Node* lRot(Node* q);
Node* rRot(Node* q);
Node* lrRot(Node* q);
Node* rlRot(Node* q);
void avlInsert(Node **root, item val);
int max(int a, int b);
Node* min(Node *root);
void destroyNode(Node *node);
