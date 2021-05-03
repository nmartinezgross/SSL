#include <stdio.h>
#include "Conversion.h"
#include <assert.h>
#include <math.h>

int main(){
    double resultado_celsius = Celsius(0);
    assert(resultado_celsius == -17.8);
    
    resultado_celsius = Celsius(20);
    assert(resultado_celsius == -6.7);

    resultado_celsius = Celsius(120);
    assert(resultado_celsius == 48.9);

    resultado_celsius = Celsius(300);
    assert(resultado_celsius == 148.9);

    int resultado_farh = Farenheit(-17.8);
    assert(resultado_farh == 0);

    resultado_farh = Farenheit(-6.7);
    assert(resultado_farh == 20);

    resultado_farh = Farenheit(115.4);
    assert(resultado_farh == 240);

    resultado_farh = Farenheit(148.7);
    assert(resultado_farh == 300);

    assert(round(Celsius(0))==-18);
    assert(round(Celsius(120)==49));
    assert(round(Celsius(300))==149);

    assert(Farenheit(-17.8)==0);
    assert(Farenheit(115.4)==240);
    assert(Farenheit(148.7)==300);

}