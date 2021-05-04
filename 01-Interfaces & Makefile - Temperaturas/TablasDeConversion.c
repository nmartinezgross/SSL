#include <stdio.h>
#include "Conversion.h"

int main()
{
        const int LOWER_F = 0;
        const int UPPER_F = 300;
        const int STEP_F = 20;
        const double LOWER_C = -17.8;
        const double UPPER_C = 148.7;
        const double STEP_C = 11.1;

        printf("Tabla de Conversion - Farenheit a Celsius:\n");
        for(int fahr = LOWER_F; fahr <= UPPER_F; fahr = fahr + STEP_F)
        printf("%5d %6.1f\n", fahr, Celsius(fahr) );

        printf("\nTabla de Conversion - Celsius a Farenheit:\n");
        for(double cels = LOWER_C; cels <= UPPER_C; cels = cels + STEP_C)
                printf("%5.1f %6.0f\n", cels, Farenheit(cels));
}        