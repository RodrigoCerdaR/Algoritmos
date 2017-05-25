#ifndef GENERAR_H_INCLUDED
#define GENERAR_H_INCLUDED



#endif // GENERAR_H_INCLUDED

#include <time.h>
#include <math.h>
#include <dirent.h>
/** \brief genera "c" elementos en orden ascendente y los almacena en la direccion donde apunta
           el puntero a int ingresado como parametro
 *  \param "*array", puntero a int
 *  \param "c" tamaño del arreglo al que se le añadiran elementos
 */
void arrayAscendente(int *array, int c){
	int i;
	array[0]=rand();
    for(i=1;i<c;i++){
        array[i]=array[i-1]+rand() %40 +1;
    }
}

/** \brief genera "c" elementos en orden descendente y los almacena en la direccion donde apunta
           el puntero a int ingresado como parametro
 *  \param "*array", puntero a int
 *  \param "c" tamaño del arreglo al que se le añadiran elementos
 */
void arrayDescendente(int *array,int c){
	int i;
	array[0]=rand();
    for(i=1;i<c;i++){
        array[i]=array[i-1]-rand() % 30 - 1;
    }
}

/** \brief genera "c" elementos ordenados de manera intercalada (los pares ascendentes y los impares descendentes)
 *         y los almacena en la direccion donde apunta el puntero a int ingresado como parametro
 *  \param "*array", puntero a int
 *  \param "c" tamaño del arreglo al que se le añadiran elementos
 */
void arrayIntercalado(int *array,int c){
	int i;
	array[0]=100;
	array[1]=array[0]-rand();
	for(i=2;i<c;i++){
        if (i%2==0){
        	array[i]=array[i-2]+2;
		}else{
			array[i]=array[i-2]-2;
		}
    }
}

/** \brief Genera "c elementos" eligiendo un numero inicial y dividiendo el arreglo en dos mitades, la primera
 *         que el y la segunda  que el. Luego se almacenan en la direccion donde apunta el puntero ingresado como
 *         parametro
 *  \param "*array", puntero a int
 *  \param "c" tamaño del arreglo al que se le añadiran elementos
 */
void arrayMitades(int *array,int c){
	int i,o, numeroInicial, acum,cont;
    numeroInicial= rand();
    for (i=0;i<c;i++){
    	cont=0;
    	if(i<c/2){
			acum=numeroInicial-rand();
			for (o=0;o<=i;o++){
				if (array[o]==acum) //para revisar que el numero no este repetido
					cont=1;
			}
			if (cont!=1){
				array[i]=	acum;
			}else{
				i--;
			}
		}else{
			acum=numeroInicial+rand();
			for (o=(c/2);o<=i;o++){
				if (array[o]==acum)//para revisar que el numero no este repetido
					cont=1;
			}
			if (cont!=1){
				array[i]=	acum;
			}else{
				i--;
			}
		}
	}
}


/** \brief Genera "c" elementos de manera aleatoria para asignarlos en la direccion donde apunta el puntero a int
 *   ingresado como parametro
 *
 *  \param "*array", puntero a int
 *  \param "c" tamaño del arreglo al que se le añadiran elementos
 */

void arraySimple(int *array,int c){
	int i,o, numeroInicial, acum,cont,signo;
    for (i=0; i < c; i++){
    	cont=0;
		numeroInicial= rand();
		signo= rand()%2;
		if (signo==1){
            numeroInicial=numeroInicial*(-1);
		}
        for (o=0;o<=i;o++){
    		if(array[o]==numeroInicial)
    		cont=1;
		}
		if (cont!=1){
			array[i]=numeroInicial;
		}else{
			i--;
		}
	}
}

/** \brief almacena el arreglo de tamaño "c" al que apunta el primer parametro,
 *   en un archivo de extencion.dat, cuyo nombre es ingresado como parametro
 *
 * \param "*arreglo" puntero a un arreglo de int, "c" tamaño del arreglo apuntado por el primer parametro
 * \param  "filename" cadena de caracteres con el nombre del archivo a guardar
 *
 */

void guardarArreglo (int *arreglo,char filename[100],int c){
	FILE *f;
	DIR *dir;
	int i;
	dir = opendir("arrays");
	if (dir==NULL){
        mkdir("arrays");
	}
	char folder[100] = "arrays/";
	char extension[30] = ".dat";
	strcat(folder,filename);
	strcat(folder,extension);
	f= fopen(folder,"w");
	fprintf(f,"%d\n",c);
	for (i=0;i<c;i++){
		fprintf(f,"%d\n",arreglo[i]);
	}
	fclose(f);
	closedir(dir);
}


/** \brief Nivel superior de las funciones para generar los archivos de arreglos.
 *   Esta función es en la cual el usuario actúa directamente.
 *
 * \param "c" int con el tamaño de los arreglos que se desean generar
 * \param
 *
 */

void GenerarArchivos(int c){
    int i,  array1[c],array2[c],array3[c],array4[c],array5[c];
    char filename[100];
    srand(time(NULL));

    arrayAscendente(&array1,c);
    guardarArreglo(&array1,"arrayAscendente",c);

    arrayDescendente(&array2,c);
    guardarArreglo(&array2,"arrayDescendente",c);

    arrayIntercalado(&array3,c);
    guardarArreglo(&array3,"arrayIntercalado",c);

    arrayMitades(&array4,c);
    guardarArreglo(&array4,"arrayMitades",c);

    for (i=1;i<=16;i++){
        arraySimple(&array5,c);
		sprintf(filename,"arraySimple%d",i);
		guardarArreglo(&array5,filename,c);
	}
    printf("Archivos generados en la carpeta \"arrays\" \n");

}
