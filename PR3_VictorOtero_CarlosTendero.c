/* Descripci?n: Curso 2017-2018. Asignatura: Estructuras de datos y algoritmos. Practica 4. Solucion a dicha practica.
* Autor: Carlos Tendero 
*/
/* LIBRER?AS EST?NDAR*/
#include <stdio.h> 
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <locale.h>
#include <time.h>

/* ZONA DE DECLARACIoN DE CONSTANTES*/
#define MAX_CARACTERES 100
#define OPCION_1 1
#define OPCION_2 2
#define OPCION_3 3
#define SALIR 4

/* ZONA DE DECLARACIoN DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

/*ZONA DE DECLARACIoN DE PROTOTIPOS DE FUNCIONES */
/* Funcion: Partir
* Devuelve la nueva posicion del pivote y separa los dos subvectores que son  tratados en las llamadas 
* recursivas a QuickSort.
* Par?metros de entrada: 
* Puntero a puntero que contiene los valores a ordenar.
* Primero: posici?n del primer elemento
* Ultimo: posici?n del ?ltimo elemento
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Nueva posici?n del pivote. Valor devuelto por la funci?n. 
*/
int Partir (int **v, int primero, int ultimo);

/* Funci?n: Menu
* Devuelve la opci?n de men? escogida.
* Par?metros de entrada: 
* no tiene.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Opci?n de men? escogida. Valor devuelto por la funci?n.
*/

int Menu (void);

/* Funci?n: ImprimirNumeros 
* Imprime por la salida standard los n?meros que se le pasan como par?metro. 
* Par?metros de entrada: 
* Puntero a entero.
* N?meros enteros.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void ImprimirNumeros (int N, int *p);

/* Funci?n: Quicksort
* Implementa el algoritmo de ordenaci?n QuickSort.
* Par?metros de entrada: 
* Primera posici?n del vector a ordenar
* ?ltima posici?n del vector a ordenar
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero que contiene los valores a ordenar/ordenados. Valor devuelto por referencia.
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void QuickSort (int **v, int izda, int dcha);

/* Funci?n: TransformarCadenaEnNumeros 
* Devuelve los c?digos ASCII de los car?cteres de la cadena. 
* Par?metros de entrada: 
* Cadena.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void TransformarCadenaEnNumeros (char *Cad, int **pN);

/* Funci?n: TransformarNumerosEnCadena
* Devuelve los car?ctes de los c?digos ASCII que se le pasan como par?metro. 
* Par?metros de entrada: 
* Puntero a entero (c?digos ASCII).
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a caracter. Valor devuelto por la funci?n (car?cteres de los c?digos ASCII). 
*/
void TransformarNumerosEnCadena (char **Cad, int *pN, int N);

/* Funci?n: AsignarMemoria 
* Asigna memoria para guardar los numeros enteros. Devuelve un puntero a un puntero a entero. 
* Par?metros de entrada: 
* Cantidad de n?meros.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
int **AsignarMemoria(int Num);

/* Funci?n: SeleccionDirecta
* Implementa el algoritmo de ordenaci?n de selecci?n directa.
* Par?metros de entrada: 
* Primera posici?n del vector a ordenar
* ?ltima posici?n del vector a ordenar
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero que contiene los valores a ordenar/ordenados. Valor devuelto por referencia.
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void SeleccionDirecta(int **p,int l,int r);
/* Funci?n: Burbuja
* Implementa el algoritmo de ordenaci?n de selecci?n directa.
* Par?metros de entrada: 
* Primera posici?n del vector a ordenar
* ?ltima posici?n del vector a ordenar
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero que contiene los valores a ordenar/ordenados. Valor devuelto por referencia.
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void Burbuja (int **p, int l, int r);

int main(int argc,char *argv[]) 
{   
    int **pNumeros = NULL;   
    char *Cadena = NULL;
    int Opcion;
    tBoolean FlgSalir;
    clock_t start, end;
     double elapsed_time;
    struct timeval tiempo_inicio, tiempo_final;
    double tiempo;
     
    
    setlocale(LC_ALL,"spanish");
    
    //Cadena = malloc(MAX_CARACTERES*sizeof(char));
   
    FlgSalir = FALSE;
    do
    {
        Opcion=Menu();
        switch (Opcion)
        {
            case OPCION_1:  /*Quicksort*/             
                /*reserva de memoria*/
                Cadena = (char*)malloc(MAX_CARACTERES*sizeof(char));
                 printf("Cadena de caracteres: "); 
                fflush(stdin);
                fgets(Cadena, MAX_CARACTERES, stdin);
                //scanf("%s", Cadena);
                fflush(stdin);
                Cadena[strlen(Cadena)-1] = '\0';  
                pNumeros = AsignarMemoria(strlen(Cadena));
                /*Cadena -> numeros*/
                TransformarCadenaEnNumeros(Cadena, pNumeros);
                /*Mostrar los numeros antes de ordenarlos*/
                ImprimirNumeros(strlen(Cadena), *pNumeros);
                /*QuickSort*/
                start = clock();
                QuickSort(pNumeros,0, strlen(Cadena)-1);
                end = clock();
                /*Mostrar los numeros despues de ordenarlos*/
                printf("\nSu cadena ordenada es: \n");
                ImprimirNumeros(strlen(Cadena), *pNumeros);
                if(*pNumeros != NULL)
                    free(*pNumeros);
                free(pNumeros);
                free(Cadena);
            	Cadena = NULL;
                pNumeros = NULL;
                
                /*Tiempo*/
                
                elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
                printf("Tiempo transcurrido: %f",elapsed_time);
                
                break;
            case OPCION_2: /*Seleccion directa*/
                Cadena = (char*)malloc(MAX_CARACTERES*sizeof(char));
                printf("Cadena de caracteres: "); 
                fflush(stdin);
                //scanf("%s", Cadena);
                fgets(Cadena, MAX_CARACTERES, stdin);
                fflush(stdin);
                Cadena[strlen(Cadena)-1] = '\0';   

                pNumeros = AsignarMemoria(strlen(Cadena));
                /*Cadena -> numeros*/
                TransformarCadenaEnNumeros(Cadena, pNumeros);
                /*Mostrar los numeros antes de ordenarlos*/
                ImprimirNumeros(strlen(Cadena), *pNumeros);
                /*Seleccion directa*/
                start = clock();
                SeleccionDirecta(pNumeros, 0, strlen(Cadena));
                end = clock();
                /*Mostrar los numeros despues de ordenarlos*/
                 printf("\nSu cadena ordenada es: \n");
                ImprimirNumeros(strlen(Cadena), *pNumeros);
                /*Libera memoria*/
                if(Cadena!= NULL)   
                    free(Cadena);
                if(pNumeros!=NULL){
                    if(*pNumeros!=NULL)
                        free(*pNumeros);
                    free(pNumeros);
                }
                Cadena = NULL;
                pNumeros = NULL;
                elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
                printf("Tiempo transcurrido: %f",elapsed_time);
                break;

            case OPCION_3: /*Burbuja*/
                Cadena = (char*)malloc(MAX_CARACTERES*sizeof(char));
                printf("Cadena de caracteres: ");   
                fflush(stdin);
                //scanf("%s", Cadena);
                fgets(Cadena, MAX_CARACTERES, stdin);
                fflush(stdin);
                Cadena[strlen(Cadena)-1] = '\0';    /*fin de cadena*/         
              
                pNumeros = AsignarMemoria(strlen(Cadena));
                /*Cadena -> numeros*/
                TransformarCadenaEnNumeros(Cadena, pNumeros);
                /*Mostrar los numeros antes de ordenarlos*/
                ImprimirNumeros(strlen(Cadena), *pNumeros);
                /*metodo burbuja*/
                Burbuja(pNumeros, 0, strlen(Cadena));
                /*Mostrar los numeros despues de ordenarlos*/
                 printf("\nSu cadena ordenada es: \n");
                ImprimirNumeros(strlen(Cadena),*pNumeros);             
                /*Libera memoria*/
                if(Cadena!= NULL)   
                    free(Cadena);
                if(pNumeros!=NULL){
                    if(*pNumeros!=NULL)
                        free(*pNumeros);
                    free(pNumeros);
                }
                
                Cadena = NULL;
                pNumeros = NULL;
                elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
                printf("Tiempo transcurrido: %f",elapsed_time);
                break;

            case SALIR: /*Salir*/ 
                
                FlgSalir=TRUE;             
                if(Cadena!= NULL)   /*si se ha hecho bien, esto no tendria porque darse*/
                    free(Cadena);
                if(pNumeros!=NULL){
                    if(*pNumeros!=NULL)
                        free(*pNumeros);
                    free(pNumeros);
                }
                printf("Adios\n");
                break;

          default: 
              printf("Ha tecleado una opcion incorrecta\n");

        }
        	system("pause");
		system("cls");  	
    } while (Opcion!= SALIR);  
    return 0; 
}

/* Funci?n: AsignarMemoria 
* Asigna memoria para guardar los numeros enteros. Devuelve un puntero a un puntero a entero. 
* Par?metros de entrada: 
* Cantidad de n?meros.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
int **AsignarMemoria(int Num) 
{   
    int **new_int= NULL;
    
    /*reserva memoria doble puntero*/
    new_int = (int**) malloc(sizeof(int*));
    
    /*control de errores*/
    if(new_int == NULL)
        return NULL;
    /*reserva para contenido*/
    *(new_int) = (int*) malloc(Num*sizeof(int));
    
    return new_int;
}


/* Funci?n: TransformarCadenaEnNumeros 
* Devuelve los c?digos ASCII de los car?cteres de la cadena. 
* Par?metros de entrada: 
* Cadena.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void TransformarCadenaEnNumeros (char *Cad, int **pN)
{
    int i=0;
    char *aux;          /* Variable aux*/
    if(Cad == NULL)
        return ;     
    //pN = AsignarMemoria(num);
    aux = Cad;    
    for( i=0; i <  strlen(Cad) && aux != '\0'; i++){
        *(*pN +i) = (int)*aux;   
        //printf("ascii pn: %d", *(*pN));
        aux++;

    }
}

/* Funci?n: TransformarNumerosEnCadena
* Devuelve los car?ctes de los c?digos ASCII que se le pasan como par?metro. 
* Par?metros de entrada: 
* Puntero a entero (c?digos ASCII).
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a caracter. Valor devuelto por la funci?n (car?cteres de los c?digos ASCII). 
*/
void TransformarNumerosEnCadena (char **Cad, int *pN, int N)
{
    int Long, i;
    char *q;
    
    q = Cad[0];
    for(i=0;i<N;i++)
    {
    	q[i] = (char)(*(pN+i));
	}
	printf("\n");
	Cad[0] = q;
}
/* Funci?n: ImprimirNumeros 
* Imprime por la salida standard los n?meros que se le pasan como par?metro. 
* Par?metros de entrada: 
* Puntero a entero.
* N?meros enteros.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void ImprimirNumeros (int N, int *p)
{
    int *aux = NULL; /*variable aux*/
    int i = 0;         
    aux = p;    /*contenido del doble puntero*/
    
    for(i = 0; i < N && aux != NULL; i++, aux++)
        printf("num: %d\tcarac: %c\n", *aux, *aux);
    
}  
/* Funci?n: Quicksort
* Implementa el algoritmo de ordenaci?n QuickSort.
* Par?metros de entrada: 
* Primera posici?n del vector a ordenar
* ?ltima posici?n del vector a ordenar
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero que contiene los valores a ordenar/ordenados. Valor devuelto por referencia.
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void QuickSort (int **v, int izda, int dcha)
{
    int pivote;
  
    if (izda < dcha)
    {
        
        pivote = Partir(v, izda, dcha);
 

        QuickSort(v, izda, pivote - 1);/*por izquierda*/
        QuickSort(v, pivote + 1, dcha);/*por derecha*/
    }
}

/*ZONA DE DECLARACIoN DE PROTOTIPOS DE FUNCIONES */
/* Funcion: Partir
* Devuelve la nueva posicion del pivote y separa los dos subvectores que son  tratados en las llamadas 
* recursivas a QuickSort.
* Par?metros de entrada: 
* Puntero a puntero que contiene los valores a ordenar.
* Primero: posici?n del primer elemento
* Ultimo: posici?n del ?ltimo elemento
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Nueva posici?n del pivote. Valor devuelto por la funci?n. 
*/
int Partir (int **v, int primero, int ultimo)
{
        
    int aux; 
	int j;   
    int pivot = (*v)[ultimo];    /*Pivote*/
    int i = (primero - 1);  // Indice del elemento menor
 
    for ( j = primero; j <= ultimo- 1; j++)
    {
        // Si el elemento actual es menor o igual que el pivote
        if ((*v)[j] <= pivot)
        {
            i++;    // Incremento del indice del elemento menor
            aux = (*v)[j]; // Intercambia los elementos
            (*v)[j] = (*v)[i];
            (*v)[i] = aux;
            
        }
    }
    
    aux = (*v)[ultimo];
    (*v)[ultimo] = (*v)[i+1];
    (*v)[i+1] = aux;
    
    return (i + 1);

}


/* Funci?n: SeleccionDirecta
* Implementa el algoritmo de ordenaci?n de selecci?n directa.
* Par?metros de entrada: 
* Primera posici?n del vector a ordenar
* ?ltima posici?n del vector a ordenar
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero que contiene los valores a ordenar/ordenados. Valor devuelto por referencia.
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void SeleccionDirecta(int **p,int l,int r) 
{
    int i = 0;
    int j = 0;
    int *inicio = NULL;
    int aux = 0;
    if(l>r) /*posicion inicial mas pequenya que posicion final (?)*/
        return ;
    else{
        inicio = *p;
    /*la ordenación de sus caracteres menor a mayor según su código ASCII */
        for(i = l; i < r ; i++)
            for(j = i+1; j < r ; j++){
            
                if( (*p)[i] > (*p)[j] ){
                 aux = (*p)[j];                
                 (*p)[j] = (*p)[i];
                 (*p)[i] = aux;
                }
            
            }
            *p = inicio;/*No haria falta si se hace bien, recuperar el puntero inciial*/
    
    }
    
    
}
/* Funci?n: Burbuja
* Implementa el algoritmo de ordenaci?n de selecci?n directa.
* Par?metros de entrada: 
* Primera posici?n del vector a ordenar
* ?ltima posici?n del vector a ordenar
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Puntero que contiene los valores a ordenar/ordenados. Valor devuelto por referencia.
* Puntero a un puntero a entero. Valor devuelto por la funci?n. 
*/
void Burbuja (int **p, int l, int r)
{
     int i = 0;
    int j = 0;
    int *inicio = NULL;
    int aux = 0;
    if(l>r) /*posicion inicial mas pequenya que posicion final (?)*/
        return ;
    else{
        inicio = *p;
    /*la ordenación de sus caracteres menor a mayor según su código ASCII */
        for(i = r-1; i > l ; i--){
          for(j = l; j < i ; j++){
                if( (*p)[j] > (*p)[j+1] ){
                 aux = (*p)[j+1];                
                 (*p)[j+1] = (*p)[j];
                 (*p)[j] = aux;
                }
            
            }
    
    }
    *p = inicio;/*no hace falta, recupero el puntero inicial*/
    
    
}
   
}
/* Funci?n: Menu
* Devuelve la opci?n de men? escogida.
* Par?metros de entrada: 
* no tiene.
* Precondiciones: 
* no tiene 
* Par?metros de salida: 
* Opci?n de men? escogida. Valor devuelto por la funci?n.
*/

int Menu (void)
{
    int opcion = 0;
	printf("\n**************************************************");
    printf("\n1.\tOrdenar por el metodo de Quicksort.");
    printf("\n2.\tOrdenar por el metodo de Seleccion Directa.");
    printf("\n3.\tOrdenar por el metodo de Burbuja.");
    printf("\n4.\tSalir.");
    printf("\n**************************************************");
    printf("\nIntroduzca una opcion para ordenar su cadena\n");
    scanf("\n%d", &opcion);
    
    return opcion;

} /*fin menu*/


