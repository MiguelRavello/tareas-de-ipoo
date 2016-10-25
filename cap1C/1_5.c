#include<stdio.h>
/* Modifique la conversion de temperatura  del programa para imprimir 
 la tabla en orden inverso */

int main()
{
    int far;
    float cel;
    for(far=300;far >= 0; far-=20){
        cel=(5.0/9.0)*(far-32.0);
        printf("Farenheit: %d y celcius: %g \n",far,cel);
    }

    return 0;
}

