#ifndef ORDENAR_H_INCLUDED
#define ORDENAR_H_INCLUDED



#endif // ORDENAR_H_INCLUDED
#include <dirent.h>

/** \brief asigna a cada una de las estructuras "resultado" ingresadas el array que se desea analizar, para luego enviar
 *         dichas estructuras a cada algoritmo de ordenamiento. almacena el resultado y los imprime en pantalla
 * \param "*a","*b","*c","*d" punteros a estructuras "resultado".
 * \param "filename" char con nombre del arreglo que se desea ordenar
 * \param "*statusCode" enum para manejo de errores
 *
 */
void Ordenar(Resultados *a,Resultados *b,Resultados *c,Resultados *d,char filename[100],code *statusCode){
    int id;
    leerArray(filename, a, statusCode);
    leerArray(filename, b, statusCode);
    leerArray(filename, c, statusCode);
    leerArray(filename, d, statusCode);
    if (*statusCode == OK){
        Insercion(a);
        Burbuja(b);
        Quicksort(c);
        Mergesort(d);
        GuardarResultado(a,b,c,d,&id);
        printf("\nGuardado en registros/registro%d.txt \n\n", id);
    }
    if (*statusCode == ERR_FILE_NOT_FOUND){
        printf("No se ha encontrado el archivo\n");
    }

}

/** \brief
 *  Lee el archivo contador.dat, donde se almacena la cantidad de registros grabados por el programa, para asi generar
 *  una cuenta de estos, dando un numero a cada registro guardado.
 * \return  "contador", int que entrega la cantidad de regitros almacenados, incluyendo el generado en la llamada a esta función
 *
 */
int IncrementoContador(){
	FILE *f1;
	int  contador=0;
	char scan[30];
	char nombreArchivo[] = "contador.dat";
	char cantidad[]= "<cantidad>%d</cantidad>";
	f1=fopen(nombreArchivo,"r");
	if (f1==NULL){
		f1=fopen(nombreArchivo,"a+");
		contador = 1;
		fprintf(f1,cantidad,contador);
		fclose(f1);
	}else{
		rewind(f1);
		fscanf(f1,cantidad,&contador);
		contador++;
		fclose(f1);
		f1=fopen(nombreArchivo,"w");
		fprintf(f1,cantidad,contador);
		fclose(f1);
    }
	return contador;
}



/** \brief
 *  Guarda en un archivo.txt unico, los resultados de la ejecución de los algoritmos de ordenamiento
 * \param  "*a","*b","*c","*d", puntero a estructuras tipo "Resultados" Los resultados para cada algoritmo.
 * \param "*id" puntero a int, en la memoria apuntada se almacena el identificador del archivo guardado.
 *
 */
void GuardarResultado(Resultados *a,Resultados *b,Resultados *c,Resultados *d,int *id){
    FILE *f;
    DIR *dir;
    dir = opendir("registros");
    if (dir ==NULL){
        mkdir("registros");
    }
    int i, newId;
    newId = IncrementoContador();
    *id = newId;
    char nombreArchivo[]= "registros/registro";
    char num[3];
	char ext[]=".txt";
	sprintf(num,"%d",newId);
	strcat(nombreArchivo,num);
	strcat(nombreArchivo,ext);
    f= fopen(nombreArchivo,"w");
    for (i=0;i<a->size;i++){
        fprintf(f,"%d ", a->arreglo[i]);
    }
    fprintf(f,"%s","\nInsercion:\n");
    fprintf(f,"Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",a->datos.contadorTiempo,a->datos.contadorComparaciones,a->datos.contadorIntercambios);
    fprintf(f,"Burbuja:\n");
    fprintf(f,"Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",b->datos.contadorTiempo,b->datos.contadorComparaciones,b->datos.contadorIntercambios);
    fprintf(f,"Quicksort:\n");
    fprintf(f,"Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",c->datos.contadorTiempo,c->datos.contadorComparaciones,c->datos.contadorIntercambios);
    fprintf(f,"Mergesort:\n");
    fprintf(f,"Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",d->datos.contadorTiempo,d->datos.contadorComparaciones,d->datos.contadorIntercambios);

    fclose(f);
    closedir(dir);
    PrintResultados(a,b,c,d);
}

/** \brief Imprime por pantalla los resultados almacenados en las direcciones que apuntan
 *   los 4 punteros a estructuras "resultados"
 *
 "*a","*b","*c","*d", puntero a estructuras tipo "Resultados" Los resultados para cada algoritmo.
 */

void PrintResultados(Resultados *a, Resultados *b, Resultados *c, Resultados *d){
    int i;
    for (i=0;i<a->size;i++){
        printf("%d ", a->arreglo[i]);
    }

    printf("\n\nInsercion:\n");
    printf("Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",a->datos.contadorTiempo,a->datos.contadorComparaciones,a->datos.contadorIntercambios);
    printf("\nBurbuja:\n");
    printf("Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",b->datos.contadorTiempo,b->datos.contadorComparaciones,b->datos.contadorIntercambios);
    printf("\nQuicksort:\n");
    printf("Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",c->datos.contadorTiempo,c->datos.contadorComparaciones,c->datos.contadorIntercambios);
    printf("\nMergesort:\n");
    printf("Tiempo: %f (mseg) \nComparaciones: %d \nIntercambios: %d \n",d->datos.contadorTiempo,d->datos.contadorComparaciones,d->datos.contadorIntercambios);

}
