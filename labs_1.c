#include<stdio.h>


void imprimir(char *xs)
{
    int i;
    int tamano=len(xs);
    for(i=tamano-1;i>=0;--i)
        printf("%c",*(xs+i));
}

int len(char *ys)
{
    int tam=0;
    int i;
    for(i=0;*(ys+i)!='\0';++i)
        ++tam;
    return tam;
}

int lower(int c){
    return c+'a'-'A';
}
int strindex(char *xs, char letra){
    int i;
    int posicion=0;
    int tamano=len(xs);
    for(i=0;i<tamano;i++){
        if(*(xs+i)==letra)
            posicion=i;
    }
    if(posicion>0)
        return posicion;
    else if(posicion==0)
        return -1;
}
int expo(int x, int y)
{
    if(y==1)
        return x;
    return x*expo(x,y-1);
}

float conver(char *xs)
{
    int i, b, m;
    b=10;
    float n,  decimal;
    n=0;
    decimal=0;
    m=1;
    for(i=0;*(xs+i)!='.';++i){
        if(*(xs+i)>='0'&& *(xs+i)<'9')
            n=10*n+(*(xs+i)-'0');
    }
    while(*(xs+i+m)!='\0'){
        decimal=1.0*(*(xs+i+m)-'0')/(expo(b,m));   
        n+=decimal;
        m++;
    }
    return n;
}

int main(){
    //primer ejemplo.....
    /*int letra;
    letra=getchar();
    printf("%c",lower(letra));*/
    //
    //segundo ejemplo....
   /* 
    char l='e';
    char cs[]="ciencia de la computacion";
    printf("%d",strindex(cs,l));
    */
    //tercer ejermplo....
    char a='a';
    char b='b';
    char num[]="123.456";
    char palabra[]="science";
    printf("%f \n", conver(num));
    imprimir(palabra);
    //printf("%c",++,"%c",a,b);
    return 0;
}
