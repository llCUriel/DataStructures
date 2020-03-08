#include "BST.h"
#include <stdio.h>
//arbol avl

void rootInsert(Node **root, Node *parent, item val) { //recorrido de arbol entero tradicional para insercion (unica insercion utilizada)
    if (*root == NULL) {
        *root = createNode(val, parent);
    } else {
	//aqui es en donde se mezclan los conceptos de alumno y el arbol avl, en el criterio de comparacion
        if (comparaNom(val->nom, (*root)->val->nom)==0) {
            rootInsert(&(*root)->l, *root, val);
        } else if (comparaNom(val->nom, (*root)->val->nom)==1) {
            rootInsert(&(*root)->r, *root, val);
		} //no se cubre el caso cuando el valor es igual a un nodo, aunque se deberia de poner un return root
    }
    //checar el balance del arbol/subarbol en el que se esta
	//balFactor(*root);
    //y dejar que la funcion de balancear actue
    //balanceTree(root);
}

Node* searchTree(Node* root, NOMBRE* val) { //para que funcione bien conceptualmente como query, deberia de retornar algo la funcion en lugar de imprimirlo
    printf("SEARCHING");
	if (root == NULL) {
        return NULL;
    } else if (comparaNom(val, root->val->nom)==-1) {
    	printf("FOUND NODE");
        return root; //y retorna el valor si es que lo encuentra
    } else if (comparaNom(val, root->val->nom)==0) {
        return searchTree(root->l, val);
    } else if (comparaNom(val, root->val->nom)==1) {
        return searchTree(root->r, val);
    }
}

void replace(Node* root, Node* n) {
	
    if (root->root!=NULL) {
    	printf("ARRIVED AT REPLACE");
        if (comparaNom(root->val->nom, root->root->l->val->nom)==-1) {
        	printf("REPLACING");
            root->root->l = n;
        } else if (comparaNom(root->val->nom, root->root->r->val->nom)==-1) {
        	printf("REPLACING");
            root->root->r = n;
        }
    }
    if (n) {
        n->root = root->root;
    }
}

void deleteNode(Node **delNode){
	printf("DELETING");
	if((*delNode)->l && (*delNode)->r){
		Node *t = min(*delNode);
		(*delNode)->val = t->val;
		*delNode = NULL;
	}else if((*delNode)->l){
		replace((*delNode), (*delNode)->l);
		*delNode = NULL;
	}else if((*delNode)->r){
		replace((*delNode), (*delNode)->r);
		*delNode = NULL;		
	}else{
		replace((*delNode), NULL);
		printf("DELNODE INFO \n");
		printNodeData((*delNode));
		printf("END DELNODE INFO \n");
		*delNode=NULL;
	}
}

void deleteFromTree(Node **root, item val){ //con esta funcion se elimina
	if(*root == NULL){
		return;
	}else if(searchTree(*root, val->nom)){
		printf("FOUND DELNODE");
		Node* aux = searchTree(*root, val->nom);
		deleteNode(&aux);
	}
}

void destroyNode(Node *node) {
	printf("DESTROYING NODE");
    node = NULL;
}

Node* createNode(item val, Node *root) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->l = n->r = NULL;
    n->root = root;
    return n;
}

/*void balanceTree(Node **root){ //se repite codigo pero en realidad esta funcion solamente balancea, entonces se justifica conceptualmente
	if((*root)!=NULL){
		if((*root)->BF<-1){
			if((*root)->r->r >= (*root)->r->l){
				//resulta una rsdd
				*root = rRot(*root);
			}else{
				//resulta una rdrl
				*root = rlRot(*root);
			}
		}else if((*root)->BF>1){
			if((*root)->l->l >= (*root)->l->r){
				*root = lRot(*root);
			}else{
				*root = lrRot(*root);
			}	
		}
	}
}*/

//profundidad de nodo
int depth(Node* n){
	if(n==NULL)
		return 0;
	else
		return max(depth(n->l), depth(n->r)) + 1;
}

//factor de eq de nodo (funcion modifica al nodo, no regresa nada)
void balFactor(Node* n){
	n->BF = depth(n->l) - depth(n->r);	
}

Node *lRot(Node *q){
	Node* p = q->l; 
	q->l = p->r; 
	p->r = q;
	balFactor(q);
	balFactor(p);
	return p;
}

Node *rRot(Node *q){
	Node* p = q->r; 
	q->r = p->l; 
	p->l = q;
	balFactor(q);
	balFactor(p);
	return p;
}

Node *lrRot(Node *q) {
	q->l = rRot(q->l);
	return (lRot(q));
}

Node *rlRot(Node *q) {
	q->r = lRot(q->r);
	return (rRot(q));
}

void printNodeData(Node *n){
	printf("nombre: %s %s %s\n", n->val->nom->primero, n->val->nom->apPaterno, n->val->nom->apMaterno);
	printf("no. de boleta: %d \n ", n->val->noBoleta);
	printf("edad: %d \n ", n->val->edad);
}

int max(int a, int b){
	if (a >= b)
		return a;
	else if (a < b)
		return b;
}
void pre(Node* arbol) {
    if (arbol == NULL) {
    } else {
        printNodeData(arbol);
        pre(arbol->l);
        pre(arbol->r);
        printf(")");
    }
}

void in(Node* arbol) {
    if (arbol != NULL) {
        printf("(");
        in(arbol->l);
        printNodeData(arbol);
        in(arbol->r);
        printf(")");
    }
}

void inCheck(Node* arbol) {
    if (arbol != NULL) {
        printf("(");
        inCheck(arbol->l);
        printf("*");
        inCheck(arbol->r);
        printf(")");
    }
}

void post(Node* arbol) {
    if (arbol == NULL) {
    } else {
        printf("(");
        post(arbol->l);
        post(arbol->r);
        printNodeData(arbol);
        printf(")");
    }
}

Node* min(Node *root){
	if(root->l)
		min(root->l);
	else
		return root;
}
