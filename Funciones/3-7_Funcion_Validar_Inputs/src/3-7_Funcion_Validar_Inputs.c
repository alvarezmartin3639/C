/*
 ============================================================================
 Name        : 3-7_Funcion_Validar_Inputs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 Ejercicio 3-7: Realizar un programa que: asigne a las variables numero1 y numero2
 los valores solicitados al usuario, valide los mismos entre 10 y 100, asigne a la
 variable operacion el valor solicitado al usuario, valide el mismo 's'-sumar, 'r'-restar,
 realice la operaciC3n de dichos valores a travC)s de una funciC3n. Mostrar el resultado
 por pantalla.
 */
#include <stdio.h>
#include <stdlib.h>

int validarRangoNumerico (int numero, int minimo, int maximo);
int operacionesMatematicas (char operacion, int numeroUno, int numeroDos);
int ingresarYValidarEntero (int numero, int rangoMinimo, int rangoMaximo);
char convertirAbreviaturaDeOperacionASigno (char abreviaturaDeOperacion);

int
main (void)
{

  setbuf (stdout, NULL);
  int numeroUno;;
  int numeroDos;;
  char operacion;
  char deseaSalir;;

  do
    {

//reseteo los valores por si el usuario quiere hacer otra operación
      numeroUno = 0;
      numeroDos = 0;
      operacion = 'x';
      deseaSalir = 'x';

      while (numeroUno < 11 || numeroUno > 99)
	numeroUno = ingresarYValidarEntero (numeroUno, 10, 100);

      while (numeroDos < 11 || numeroDos > 99)
	numeroDos = ingresarYValidarEntero (numeroDos, 10, 100);

      while (operacion != 'r' && operacion != 's')
	{
	  printf ("\n\n\nQue operacicC3n desea hacer? [suma=s/resta=r]: ");
	  fflush (stdin);
	  scanf (" %c", &operacion);

	  if (operacion != 's' && operacion != 'r')
	    printf ("\n***Error, %c no es una opciC3n valida, "
		    "estas son 's' para la suma o 'r' para la resta***\n",
		    operacion);
	  else
	    printf ("\n%d %c %d = %d", numeroUno,
		    convertirAbreviaturaDeOperacionASigno (operacion),
		    numeroDos, operacionesMatematicas (operacion, numeroUno,
						       numeroDos));
	}


      while (deseaSalir != 'y' && deseaSalir != 'n')
	{
	  printf ("\n\n\nDesea salir?[y/n]");
	  fflush (stdin);
	  scanf (" %c", &deseaSalir);

	  if (deseaSalir != 'y' && deseaSalir != 'n')
	    printf
	      ("\n***Error,'%c' no es una opciC3n valida, esta son 'y' para salir o 'n' para continuar con el programa***\n",
	       deseaSalir);
	}
    }
  while (deseaSalir != 'y');


  printf ("\n");
  return EXIT_SUCCESS;
}

int
validarRangoNumerico (int numero, int minimo, int maximo)
{

  if (numero > minimo && numero < maximo)
    return 1;

  else
    return 0;
}

int
operacionesMatematicas (char operacion, int numeroUno, int numeroDos)
{

  int retorno;

  switch (operacion)
    {
    case 's':
      retorno = numeroUno + numeroDos;
      break;

    case 'r':
      retorno = numeroUno - numeroDos;
      break;
    }

  return retorno;
}

int
ingresarYValidarEntero (int numero, int rangoMinimo, int rangoMaximo)
{

  int retorno = 0;
  printf ("\nIngrese un numero: ");
  fflush (stdin);
  scanf (" %d", &numero);

  if (!validarRangoNumerico (numero, rangoMinimo, rangoMaximo))
    printf ("\n***Error, el numero ingresado no es uno entre 10 y 100\n");
  else
    retorno = numero;

  return retorno;
}

char
convertirAbreviaturaDeOperacionASigno (char abreviaturaDeOperacion)
{

  char retorno;
  switch (abreviaturaDeOperacion)
    {

      //suma
    case 's':
      retorno = '+';
      break;

      //resta
    case 'r':
      retorno = '-';
      break;

      //multiplicaciC3n
    case 'm':
      retorno = '*';
      break;
      //divisiC3n
    case 'd':
      retorno = '/';
      break;
    }

  return retorno;
}
