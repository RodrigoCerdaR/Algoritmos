#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED



#endif // AUXILIARES_H_INCLUDED
/**< Estructura inferior. En ella se almacenan los datos de rendimiento de cada algoritmo */
typedef struct{
    double  contadorTiempo;
    int     contadorComparaciones;
    int     contadorIntercambios;

}Datos;

/**< Estructura superior. En ella se almacena el arreglo y los datos de rendimiento  */
typedef struct{
    int     *arreglo;
    Datos   datos;
    int     size;
}Resultados;

/**< Enum para manejar errores */
typedef enum code {OK, ERR_FILE_NOT_FOUND, ERR_BAD_FILE} code;



/** \brief Intercambia elementos de un arreglo
 *
 * \param "a", "b", punteros a int
 */
void intercambio(int * a, int * b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


