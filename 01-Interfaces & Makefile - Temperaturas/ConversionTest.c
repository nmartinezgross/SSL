#include <stdio.h>
#include "Conversion.h"
#include <assert.h>
#include <math.h>

int main(){
    
    assert(round(Celsius(0))==-18);
    assert(round(Celsius(120))==49);
    assert(round(Celsius(300))==149);

    assert(round(Farenheit(-17.8))==0);
    assert(round(Farenheit(115.4))==240);
    assert(round(Farenheit(148.7))==300);

}