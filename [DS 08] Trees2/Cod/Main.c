#include "BST.c"

int main(){
	//main
	
	Node* root = NULL;
	
	item alumno = NULL;
	
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesar";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellanos";
	printf("here");
	rootInsert(&root, NULL, alumno);
	
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesar";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellana";
		printf("insert 2");

	rootInsert(&root, NULL, alumno);
	
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesar";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellanp";
		printf("insert 3");

	rootInsert(&root, NULL, alumno);
		
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesar";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellanz";
	
	rootInsert(&root, NULL, alumno);
	
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesar";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellanj";
	
	rootInsert(&root, NULL, alumno);
	
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesare";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellane";
	
	rootInsert(&root, NULL, alumno);
	
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesarin";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellanj";
	
	rootInsert(&root, NULL, alumno);
	
	alumno = (ALUMNO*)malloc(sizeof(ALUMNO));
	alumno->edad = 23;
	alumno->noBoleta = 2014090412;
	alumno->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	alumno->nom->primero = "cesarzz";
	alumno->nom->apMaterno = "hernandez";
	alumno->nom->apPaterno = "castellanj";
	
	rootInsert(&root, NULL, alumno);
	
	inCheck(root); 
	
	item val;
	val = (ALUMNO*)malloc(sizeof(ALUMNO));
	val->nom = (NOMBRE*)malloc(sizeof(NOMBRE));
	val->nom->primero = "cesar";
	val->nom->apMaterno = "hernandez";
	val->nom->apPaterno = "castellanj";
	
	//printNodeData(searchTree(root, val->nom));
	printf("BEFORE DEL\n");
	inCheck(root);
	printf("\n");
	deleteFromTree(&root, val);
	printf("AFTER DEL\n");
	inCheck(root);
	printf("\n");
	
	
	in(root);
	
	
	return 0;
}
