/* 01-Interfaces&Make - Temperaturas
 * Aplicar el uso de Interfaces y Makefile
 * Martinez Gross Natalia
 * 20210503
 */

#include "Conversion.h"

//Convierte de Farenheit a Celsius.
double Celsius(double f){
    return (5.0/9)*(f-32);
}

//Convierte de Celsius a Farenheit.
double Farenheit(double c){
    return ((9.0/5)*c)+32;
}