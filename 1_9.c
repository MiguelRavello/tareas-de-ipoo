#include<stdio.h>

//le vamos hacer reduccion de varios espacios en blanco a uno solo
int main()
{
    int c, blank, caracter;
    blank=0;
    caracter=0;
    while((c=getchar())!=EOF){
        if(c!=' '||c!='\t')
            ++caracter;
        if(c==' '|| c=='\t'){
            ++blank;
            caracter=0;
        }
        if(caracter==1 && blank!=0){
            putchar(' ');
            //putchar(c);
            blank=0;
        }
        if(caracter!=0 && blank==0)
            putchar(c);

    }
    return 0;
}
