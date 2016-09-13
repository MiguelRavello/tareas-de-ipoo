#include<stdio.h>

void imprimir(char *xs)
{
    int i;
    int tamano=len(xs);
    for(i=tamano-1;i>=0;--i)
        printf("%c",*(xs+i));
}

void concatenar(char *xs, char *ys)
{
    int i, j;
    i=j=0;
    while(*(xs+i)!='\0')
        i++;
    while((*(xs+i)=*(ys+j))!='\0'){
        ++i;
        ++j;
    }
}

void r_imprimir(char *xs)
{
    int i;
    int tamano=len(xs);
    i=tamano;
   // if(i>0) 
   //     concatenar()
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
float expo(float x, int y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;
    else if(y>0)
        return x*expo(x,y-1);
    else if(y<0)
        return (1/x)*expo(x,y+1);
}

float conver(char *xs)
{
    int i, m, j, potencia;  

    float base, n, decimal;
    n=0;
    base=10;
    decimal=0; 
    for(i=0;*(xs+i)!='.';++i){
        if(*(xs+i)>='0'&& *(xs+i)<='9')
            n=10*n+1.0*(*(xs+i)-'0');
    }
    for(m=1;*(xs+i+m)!='e';m++){
        decimal=(*(xs+i+m)-'0')/(expo(base,m));   
        n+=decimal;
        if(*(xs+i+m)=='\0')
            return n;
    }
    j=1;
    if(*(xs+i+m+j)=='-'){
        for(j=2;*(xs+i+m+j)!='\0';++j){
            if(*(xs+i+m+j)>='0'&& *(xs+i+m+j)<='9') 
                potencia=10*potencia+(*(xs+i+m+j)-'0');
        }
        //potencia=(-1)*potencia;
        return n*(expo(base,potencia));
    }
    else if(*(xs+i+m+j)!='-'){
        potencia=0;
        for(j=1;*(xs+i+m+j)!='\0';++j){
            if(*(xs+i+m+j)>='0'&& *(xs+i+m+j)<='9') 
                potencia=10*potencia+(*(xs+i+m+j)-'0');
        }              
        return n*(expo(base,potencia));
    }
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
    char num[]="123.456e-3";
    char palabra[]="abcdefg";
    char con[]="hijklm";
    printf("%g  \n", conver(num));
    //imprimir(palabra);
    concatenar(palabra,con);
    int i;
    for(i=0;i<len(palabra);++i)
        printf("%c",palabra[i]);
    //printf("%c",++,"%c",a,b);
    return 0;
}
