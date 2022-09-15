/*
 * ConvertCelsiusAndFahrenheit.c
 *
 *  Created on: 3 sept 2022
 *      Author: kenyn
 */

#include "convertTemperatures.h"

float celsiusToFahrenheit(float celsius){
	return (celsius * 1.8) + 32;
}

float fahrenheitToCelsius(float fahrenheit){
	return (fahrenheit - 32) /1.8;
}
