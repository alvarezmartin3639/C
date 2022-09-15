/*
 * ValidateRange.c
 *
 *  Created on: 3 sept 2022
 *      Author: kenyn
 */
#include "validateRange.h"

#include <stdio.h>
#include <stdlib.h>

float validateFloatRange(float numberToValidate, float minRange, float maxRange){

	int retorno =0;

	if(numberToValidate > minRange || numberToValidate < maxRange)
		retorno = 1;

	return retorno;
}
