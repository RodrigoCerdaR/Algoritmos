#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED



#endif // ALGORITMOS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/** \brief Algoritmo de ordenamiento de tipo Insercion. ordena el arreglo contenido dentro de la estructura "resultados"
 *         junto con los datos del rendimiento del algoritmo en dicha tarea
 * \param "*r" puntero a estructura "resultados" donde se almacena el arreglo y los datos de rendimiento
 */
void Insercion(Resultados *r){
    r->datos.contadorComparaciones=0;
    r->datos.contadorIntercambios=0;
    r->datos.contadorTiempo=0;
    clock_t tiempoini, tiempofin;
    tiempoini = clock();
    int a;
	int i,j;
	for(i=1;i<r->size;i++){
		j=i;
		r->datos.contadorComparaciones++;
		while( (r->arreglo[j]<r->arreglo[j-1]) & j>0){
			r->datos.contadorComparaciones++;
			intercambio(&r->arreglo[j],&r->arreglo[j-1]);
			r->datos.contadorIntercambios++;
            j--;
		}
	}
	tiempofin=clock();
	r->datos.contadorTiempo=(double)tiempofin-tiempoini;
}

/** \brief
 *  Algoritmo de ordenamiento "burbuja" (iterativo)ordena el arreglo contenido dentro de la estructura "resultados"
 *  junto con los datos del rendimiento del algoritmo en dicha tarea
 * \param "*r" puntero a estructura "resultados" donde se almacena el arreglo y los datos de rendimiento
 */
void Burbuja(Resultados *r){
	r->datos.contadorComparaciones=0;
    r->datos.contadorIntercambios=0;
    r->datos.contadorTiempo=0;
    clock_t tiempoini, tiempofin;
	tiempoini= clock();
	int i,j;
	for (i=0;i<r->size;i++){
		for(j=r->size-1;j>=i+1;j--){
            r->datos.contadorComparaciones++;
			if(r->arreglo[j]<r->arreglo[j-1]){
                r->datos.contadorIntercambios++;
				intercambio(&r->arreglo[j],&r->arreglo[j-1]);
			}
		}
	}
	tiempofin=clock();
	r->datos.contadorTiempo=(double)tiempofin-tiempoini;
}


/** \brief llama a la funcion quicksortaux, encargada de ordenar el arreglo contenido en la estructura "resultado",
 *         ademas de inicializar las variables de datos de rendimiento del algoritmo.
 * \param  "*r" puntero a estructura "resultados"
 */
void Quicksort(Resultados *r){

    r->datos.contadorComparaciones=0;
    r->datos.contadorIntercambios=0;
    r->datos.contadorTiempo=0;
    clock_t tiempoini, tiempofin;
    tiempoini= clock();
    QuicksortAux(0, r->size-1, r);
    tiempofin=clock();
    r->datos.contadorTiempo=(double)tiempofin-tiempoini;

}


/** \brief
 *  Algoritmo  quicksort que particiona el arreglo para ordenarlo, tomando el primer elemento de la partición como
 *  pivote para comparar.
 * \param "prim", "ult" indice del primer y ultimo elemento del arreglo
 * \param "*r" puntero a estructura "resultados" donde se almacena el arreglo y los datos de rendimiento
 * \return "corte", int que devuelve la posición en la que quedó el elemento pivote
 */
int particion(int prim, int ult, Resultados *r){
    int pivote, corte, k;
	pivote = r->arreglo[prim];
	corte=prim;
    for (k=prim +1;k<=ult;k++){
        r->datos.contadorComparaciones++;
        if (r->arreglo[k]< pivote){
			corte=corte+1;
			intercambio(&r->arreglo[corte],&r->arreglo[k]);
			r->datos.contadorIntercambios++;
		}
    }
	r->datos.contadorIntercambios++;
	intercambio(&r->arreglo[prim],&r->arreglo[corte]);
	return corte;
}


/** \brief
 *  (recursiva) Funcion que calcula los indices de las particiones, llegando a una particion de 1 elemento
 *  gracias a la recursividad. Luego llama a la función "particion", que a traves del algoritmo quicksort,
 *  ordena el array contenido dentro de la estructura "resultados"
 * \param "prim","ult", int, indices del primer y ultimo elemento que analiza la función
 * \param "*r" puntero a estructura "resultados" donde se almacena el arreglo y los datos de rendimiento
 */
void QuicksortAux(int prim, int ult, Resultados *r){
    int corte;
	if (ult - prim>=1){
        corte= particion(prim,ult,r);
		QuicksortAux(prim,corte - 1,r);
		QuicksortAux(corte +1, ult,r);
	}
}




/** \brief llama a la funcion Mergesortaux, encargada de ordenar el arreglo contenido en la estructura "resultado",
 *         ademas de inicializar las variables de datos de rendimiento del algoritmo.
 * \param  "*r" puntero a estructura "resultados"
 */
 void Mergesort(Resultados *r){

    r->datos.contadorComparaciones=0;
    r->datos.contadorIntercambios=0;
    r->datos.contadorTiempo=0;
    clock_t tiempoini, tiempofin;
    tiempoini= clock();
    MergesortAux(r, 0, r->size-1);
    tiempofin=clock();
    r->datos.contadorTiempo=(double)tiempofin-tiempoini;

}


/** \brief
 *  Función que, por medio del algoritmo mergesort, ordena el arreglo, separandolo recursivamente en mitades de
 *  arreglos mas pequeños, con el fin de ordenarlos por separado y luego entrelazarlos.
 * \param "inicio","medio", "fin", int de indices del elemento inicial, medio, y final del arreglo a ordenar.
 * \param "*r" puntero a estructura "resultados" donde se almacena el arreglo y los datos de rendimiento
 */
void Merge(Resultados *r,int inicio, int medio, int fin){
    int h,i,j,k,l;
	int arrayAux[fin-inicio+1];
	h = 0;
	i = inicio;
	j = medio + 1;
	while (  (i<=medio)&&(j <= fin)  )  {
        r->datos.contadorComparaciones++;
		if (r->arreglo[i]<r->arreglo[j]){
            arrayAux[h]=r->arreglo[i];
			i++;
		}else{
			r->datos.contadorIntercambios++;
			arrayAux[h]=r->arreglo[j];
			j++;
		}
		h++;
	}
	if (i> medio){
		for (k=j;k<=fin;k++){
			arrayAux[h]=r->arreglo[k];
			h++;
		}
	}else{
		for(k=i;k<=medio;k++){
			arrayAux[h]=r->arreglo[k];
			h++;
		}
	}
	l=0;
	for (k=inicio;k<=fin;k++){
		r->arreglo[k]=arrayAux[l];
		l++;
	}
}

/** \brief
 *  (recursiva)Función que divide el array de la estructura "resultados" en arrays mas pequeños, con el fin de comenzar a ordenarlos una vez
 *  se llegue a la división mas pequeña.
 * \param "*r" puntero a estructura "resultados" donde se almacena el arreglo y los datos de rendimiento
 * \param "ini", "fi", int. indices del primer y ultimo elemento del array a ordenar.
 */
void MergesortAux(Resultados *r,int ini, int fi){
	int med;
	if(ini < fi){
        med=(ini+fi) / 2;
		MergesortAux(r,ini,med);
		MergesortAux(r,(med+1),fi);
		Merge(r,ini,med,fi);
	}
}
