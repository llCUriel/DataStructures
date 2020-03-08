/*
        INSTITUTO POLITÉCNICO NACIONAL
        ESCUELA SUPERIOR DE CÓMPUTO
        ESTRUCTURAS DE DATOS
        GRUPO: 1CV7
        ALUMNOS: 
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL
                MARTÍNEZ ISLAS MAURICO JOEL
        PROFESOR: BENJAMÍN LUNA BENOSO 
        IMPLEMENTACIÓN DE LAS FUNCIONES DE CHECKER	
        FECHA: 18/2/17
 */
 
#include "Checker.h"

#include "PILA.c"

void errCheck() {
	
    PILA pila;
    
    CrearPila(&pila);
    
    //lcounter cuenta saltos de linea.
    
    int lcounter = 1, flag = 1, pcounter;
    
    char actChar;
    
    //el archivo esta hardcodeado
    
    FILE *f;
    
    f = fopen("ejemplo.txt", "r");
    
    //de nuevo, esto es hardcode pero pues es para la simulacion de la salida completa
    
    printf("nombre: ejemplo.txt \n\n");
    
    while (!feof(f) && flag == 1) {
    	
        actChar = fgetc(f);
        
        printf("%c", actChar);
        
        //primero, ver si es salto de linea
        
        if (actChar == '\n') {
        	
            lcounter++;
            
        }
        
        //si es de los simbolos que abren, van a la pila
        
        if (actChar == '(' || actChar == '[' || actChar == '{' || actChar == '<') {
        	
            InsertarPila(&pila, actChar);
            
            pcounter = lcounter;
            
        } else if (actChar == ')' || actChar == ']' || actChar == '}' || actChar == '>') {
        	
            //validar con la pila
            
            if (!PilaVacia(pila)) {
            	
                if (validate(CimaPila(pila), actChar) == 0) {
                	
                    printf("\nposible linea de error: %d, \n", lcounter);
                    
                    flag = 0;
                    
                } else {
                	
                    QuitarPila(&pila);
                    
                }
                
            } else {
            	
                printf("\nposible linea de error: %d, \n", lcounter);
                
                printf("\nposible error: sobra un %c\n", actChar);
                
                flag = 0; //se topo con un simbolo que cierra con pila vacia	
					
            }
            
        }
        
    }
    
    //si todavia hay elementos en la pila
    
    if (!PilaVacia(pila) && flag == 1) {
    	
        printf("\nposible linea de error: %d,\n ", pcounter);
        
        validate(CimaPila(pila), actChar);
        
    } else if (PilaVacia(pila) && flag == 1) {
    	
        printf("\nbien hecho\n");
        
    }
    
}

int validate(char l, char r) {
	
    int flag = 0;
    
    //nada mas compara a ver si tiene su simbolo correspondiente
    
    if (l == '(')
    
        flag = (r == ')') ? 1 : 0;
        
    else if (l == '[')
    
        flag = (r == ']') ? 1 : 0;
        
    else if (l == '{')
    
        flag = (r == '}') ? 1 : 0;
        
    else if (l == '<')
    
        flag = (r == '>') ? 1 : 0;

    //imprimir que es el posible error
    
    if (flag == 0) {
    	
        if (l == '(')
        
            printf("\nposible error: falta un )\n");
            
        else if (l == '[')
        
            printf("\nposible error: falta un ]\n");
            
        else if (l == '{')
        
            printf("\nposible error: falta un }\n");
            
        else if (l == '<')
        
            printf("\nposible error: falta un >\n");
            
    }
    
    return flag;
    
}




