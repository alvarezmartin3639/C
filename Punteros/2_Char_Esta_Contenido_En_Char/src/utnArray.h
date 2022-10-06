/*
 * utnArrays.h
 *
 *  Created on: 12 sept 2022
 *      Author: kenyn
 */

#ifndef UTNARRAY_H_
#define UTNARRAY_H_

/**
 * @fn int inicializarArrayInt(int[], int, int)
 * @brief incializa un array int con el valor pasado por parametro
 *
 * @param enteros array de los numeros enteros que se van a inicializar
 * @param tamEnteros tamaño del array
 * @param valor el valor en el cual se va a inicializar el array
 * @return -1 = error , 0 = sin error
 */
int inicializarArrayInt(int enteros[], int tamEnteros, int valor);

/**
 * @fn int inicializarArrayFloat(float[], int, float)
 * @brief inicializa un array float con el valor pasado por parametro
 *
 * @param flotantes array de los numeros enteros que se van a inicializar
 * @param tamFlotantes tamaño del array
 * @param valor el valor en el cual se va a inicializar el array
 * @return  -1 = error , 0 = sin error
 */
int inicializarArrayFloat(float flotantes[], int tamFlotantes, float valor);

/**
 * @fn int inicializarArrayChar(char[], int, char)
 * @brief inicializa un array char con el valor pasado por parametro
 *
 * @param caracteres array con los caracteres que se van a incializar
 * @param tamString tamaño del array
 * @param valor el valor en el cual se va a inicializar el array
 * @return  -1 = error , 0 = sin error
 */
int inicializarArrayChar(char caracteres[], int tamString, char valor);

/**
 * @fn int inicializarArrayString(int, int, char[][], char[])
 * @brief incializa un array string con el valor pasado por parametro
 *
 * @param tamString tamaño del array
 * @param tamMatriz tamaño de la matriz
 * @param string el string el cual se va a incializar con el array
 * @param valor el valor en el cual se va a inicializar el array
 * @return  -1 = error , 0 = sin error
 */
int inicializarArrayString(int tamString, int tamMatriz,
		char string[][tamString], char valor[]);

/**
 * @fn int ordenarEnteros(int[], int, int)
 * @brief ordena el array con el orden pasado por parametro
 *
 * @param numeros array de los numeros enteros que se van a ordenar
 * @param tamNumeros tamaño del array
 * @param orden el orden de ordenamiento 1 = Descendiente (mayor a menor), 0 = Ascendiente (menor a mayor)
 * @return  -1 = error , 0 = sin error
 */
int ordenarEnteros(int numeros[], int tamNumeros, int orden);

/**
 * @fn int ordenarFlotantes(float[], int, int)
 * @brief ordena el array con el orden pasado por parametro
 *
 * @param numeros array de los numeros enteros que se van a ordenar
 * @param tamNumeros tamaño del array
 * @param orden  orden el orden de ordenamiento 1 = Descendiente (mayor a menor), 0 = Ascendiente (menor a mayor)
 * @return  -1 = error , 0 = sin error
 */
int ordenarFlotantes(float numeros[], int tamNumeros, int orden);

/**
 * @fn int ordenarString(char[][], int, int)
 * @brief ordena el array con el orden pasado por parametro
 *
 * @param texto el array que se va a ordenar
 * @param tamMatrizTexto tamaño de la matriz
 * @param orden  orden el orden de ordenamiento 1 = Descendiente (mayor a menor), 0 = Ascendiente (menor a mayor)
 * @return  -1 = error , 0 = sin error
 */
int ordenarString(char texto[][20], int tamMatrizTexto, int orden);

/**
 * @fn int ordenarAlfanumerico(char[][], int, int)
 * @brief ordena el array con el orden pasado por parametro
 *
 * @param texto el texto que se va a ordenar
 * @param tamMatrizTexto tamaño de la matriz
 * @param orden  orden el orden de ordenamiento 1 = Descendiente (mayor a menor), 0 = Ascendiente (menor a mayor)
 * @return  -1 = error , 0 = sin error
 */
int ordenarAlfanumerico(char texto[][20], int tamMatrizTexto, int orden);

/**
 * @fn int buscarMinimoArrayInt(int[], int)
 * @brief Busca el numero minimo del array y lo retorna
 *
 * @param array array de los numeros enteros en donde se van a buscar el minimo
 * @param tam tamaño del array
 * @return  retorna el valor minimo del array
 */
int buscarMinimoArrayInt(int array[], int tam);

/**
 * @fn int buscarMaximoArray(int[], int)
 * @brief Busca el numero maximo del array y lo retorna
 *
 * @param array array de los numeros enteros en los cuales se va a buscar el maximo
 * @param tam tamaño del array
 * @return retorna el valor maximo del array
 */
int buscarMaximoArray(int array[], int tam);

/**
 * @fn int buscarIndiceMaximoArrayInt(int[], int)
 * @brief Busca el numero maximo del array y retorna su indice
 *
 * @param array array de los numeros enteros que se van a buscar el maximo
 * @param tam tamaño del array
 * @return retorna el indice con el valor maximo del array
 */
int buscarIndiceMaximoArrayInt(int array[], int tam);

/**
 * @fn int buscarIndiceMaximoArrayFloat(float[], int)
 * @brief Busca el numero minimo del array y retorna su indice
 *
 * @param array array de los numeros decimal que se van a buscar el maximo
 * @param tam tamaño del array
 * @return retorna el indice con el valor maximo del array
 */
int buscarIndiceMaximoArrayFloat(float array[], int tam);

/**
 * @fn int contarParesArrayInt(int[], int)
 * @brief cuenta la cantidad de pares que hay en el array y lo retorna
 *
 * @param array array de los numeros enteros en los que se va a contar los pares
 * @param tam tamaño del array
 * @return la cantidad de pares que se contaron
 */
int contarParesArrayInt(int array[], int tam);

/**
 * @fn int contarCantDeNumerosEnArrayInt(int[], int, int)
 * @brief cuenta la cantidad de numeros del array que su valor es igual al pasado por parametro numeroParaBuscar
 *
 * @param array array de los numeros enteros que se van contar el numero pasado por parametro
 * @param tam tamaño del array
 * @param numeroParaBuscar el valor que se busca en el array
 * @return la cantidad de numeros que se contaron
 */
int contarCantDeNumerosEnArrayInt(int array[], int tam, int numeroParaBuscar);

/**
 * @fn int acumularArrayInt(int[], int)
 * @brief acumula la cantidad de numeros del array pasado por parametro y lo retorna
 *
 * @param array array de los numeros enteros que se van a acumular
 * @param tam tamaño del array
 * @return la acumulación total del array
 */
int acumularArrayInt(int array[], int tam);

/**
 * @fn float promediarArrayInt(int[], int)
 * @brief promedia el array pasado por parametro y lo retorna
 *
 * @param array array de los numeros enteros que se van a buscar el promedio
 * @param tam tamaño del array
 * @return el promedio total del array
 */
float promediarArrayInt(int array[], int tam);

/**
 * @fn int buscarValorIntEnArray(int[], int, int)
 * @brief busca en el array el valorBuscado pasado por parametro y  retorna el indice que contiene dicho valor
 *
 * @param array array de los numeros enteros en los cuales se va a buscar el valor buscado
 * @param tam tamaño del array
 * @param valorBuscado el valor que se busca en el array
 * @return el indice con el valor buscado por parametro
 */
int buscarValorIntEnArray(int array[], int tam, int valorBuscado);

/**
 * @fn int buscarValorStringEnArray(int, int, char[][], char*)
 * @brief busca en el array el valorBuscado pasado por parametro y  retorna el indice que contiene dicho valor
 *
 * @param tamCaracteres tamaño de los caracteres que tiene arrayString
 * @param tamArrayString tamaño de la matriz de arrayString
 * @param arrayString el array de strings de dos dimensiones
 * @param valorBuscado el valor que se busca dentro de arrayString
 * @return el indice con el valor buscado por parametro
 */
int buscarValorStringEnArray(int tamCaracteres, int tamArrayString,
		char arrayString[][tamCaracteres], char *valorBuscado);
/***
 * \fn int generarNumeroAleatorio(int[], int, int, int)
 * \brief Rellena un array del tipo int con numeros aleatorios, entre el minimo y el maximo pasado por parametro
 *
 * \param arrayInt el array donde se van a guardar los numeros
 * \param tamArray el tamaño del array
 * \param minimo el numero minimo que se va a generar
 * \param maximo el numero maximo que se va a generar
 * \return 0 = no errores, -1 = error
 */
int generarNumeroAleatorio(int arrayInt[], int tamArray, int minimo, int maximo);


/***
 * @fn int buscarIndicesPorValorEnArrayInt*(int*, int, int)
 * @brief Busca en un array pasado por parametro, los indices de dicho array que contengan el valor. (util para buscar posiciones ocupadas)
 *
 * @param array el array con los valores para buscar
 * @param tamArray el tamaño del array
 * @param valor el valor del array
 * @return n>-1 = un array de int que contiene el indice del array (array[0] = 1(indice)), -1 = no se encontró el valor en el array.
 */
int* buscarIndicesPorValorEnArrayInt(int *array, int tamArray, int valor);

#endif /* UTNARRAY_H_ */
