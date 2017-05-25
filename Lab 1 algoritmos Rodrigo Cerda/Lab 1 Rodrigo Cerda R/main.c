#include <stdio.h>
#include <stdlib.h>
#include "leer.h"
#include "algoritmos.h"
#include "ordenar.h"
#include "generar.h"

/** \brief Funcion que imprime por pantalla el dialogo con el usuario, y recibe la información que este proporciona para
 *  realizar la tarea solicitada
 */
void MenuPrincipal(){
    int eleccion=0;
    char *p, s[100];


    while (eleccion !=3){
        printf("Laboratorio 1 Algoritmos y Estructuras de Datos \n\n");
        printf("Para generar los archivos con los arreglos a ordenar, ingrese 1\n");
        printf("Para ordenar algun arreglo contenido en un archivo, ingrese 2\n");
        printf("Para salir, ingrese 3\n");
        while (fgets(s, sizeof(s), stdin) ){
            eleccion=strtol(s,&p,10);
            if (p == s || *p != '\n' || eleccion < 1 || eleccion > 3) {
                printf("Favor ingresar un entero entre 1 y 3: ");
            } else break;
        }
        if (eleccion==1){
            int size;
            printf("Cantidad de elementos dentro de los arreglos a generar (max: 20000): ");
            while (fgets(s, sizeof(s), stdin) ){
                size=strtol(s,&p,10);
                if (p == s || *p != '\n' || size > 20000) {
                    printf("Favor ingresar un entero (max 20000): ");
                } else break;
            }
            GenerarArchivos(size);
        }
        if (eleccion==2){

            Resultados rInscercion, rBurbuja, rQuicksort, rMergesort;
            char filename[100];
            code statusCode;
            printf("arrayAscendente, arrayDescendente, arrayIntercalado, \narrayMitades, arraySimple1, ..., arraySimple16\n");
            printf("Ingrese el nombre del archivo a evaluar (sin extencion): ");
            scanf("%s",filename);
            printf("\n");
            Ordenar(&rInscercion, &rBurbuja, &rQuicksort, &rMergesort, filename, &statusCode);

        }
        if (eleccion==3){
            return 0;
        }



    }
}

int main(){
    MenuPrincipal();


    return 0;
}
