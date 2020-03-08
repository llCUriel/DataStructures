#include "Alumno.h"
void altaAlumno(char* nombre, char*apMat, char*apPat, int edad, int noBoleta){
	//insercion de arbol avl
}

//funcion para comparar strings (o sea ver si es menor o mayor)
int biggerStr(char* s1, char* s2){ //-1 igual 0 menor 1 mayor 
	int i=0, flag=-1;
	while(flag==-1&&i<strlen(s1)&&i<strlen(s2)){
		if(s1[i]<s2[i]){
			flag=1;	
		}else if(s1[i]>s2[i]){
			flag=0;
		}
		i++;	
	}
	if(strlen(s1)>strlen(s2) && flag==-1)
		flag = 1;//el error es visible
	return flag;
}

int comparaNom(NOMBRE *nom1, NOMBRE *nom2){ // -1 igual 0 menor 1 mayor
	printf("comparando %s %s %s \n", nom1->primero, nom1->apPaterno, nom1->apMaterno);
	printf("con %s %s %s \n", nom2->primero, nom2->apPaterno, nom2->apMaterno);
	if(biggerStr(nom1->primero, nom2->primero)==-1){
		
		if(biggerStr(nom1->apPaterno, nom2->apPaterno)==-1){
			if(biggerStr(nom1->apMaterno, nom2->apMaterno)==-1){
				return -1;
			}else{		
				return biggerStr(nom1->apMaterno, nom2->apMaterno);
			}
		}else{
			return biggerStr(nom1->apPaterno, nom2->apPaterno);
		}
	}else{
		return biggerStr(nom1->primero, nom2->primero);
	}
}
