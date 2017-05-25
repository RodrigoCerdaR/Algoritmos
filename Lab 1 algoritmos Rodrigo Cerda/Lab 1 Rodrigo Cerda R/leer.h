#ifndef LEER_H_INCLUDED
#define LEER_H_INCLUDED



#endif // LEER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "auxiliares.h"

/** \brief lee el arreglo dentro del archivo solicitdo, y lo asigna dentro de la estructura apuntada por el puntero
 *         a "Resultado" ingresado como parametro, siempre que el archivo exista
 * \param "arrayfile" nombre del archivo a leer
 * \param "*r" puntero a una estructura resultado, donde se almacenará el array leido.
 * \param "*statusCode" enum para manejo de errores
 */
void leerArray(char arrayfile[100], Resultados * r, code *statusCode){
	int asize, c ;
	FILE *f;
	char filename[100]="arrays/";
	char extension[30]=".dat";
	strcat(filename,arrayfile);
	strcat(filename,extension);
	f= fopen(filename,"r");
	if (f==NULL){
        *statusCode= ERR_FILE_NOT_FOUND;
	}else{
        *statusCode=OK;
        fscanf(f,"%d\n",&asize);
        r->size=asize;
        r->arreglo=(int*)malloc(asize * (sizeof(int)) );
        for (c=0;c<asize;c++){
            fscanf(f,"%d\n",&r->arreglo[c]);
        }

	}

	fclose(f);
}
