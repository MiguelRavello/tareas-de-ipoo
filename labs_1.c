#include<stdio.h>

char vacio[]="";
char vacio2[]="";

void copiar(char *xs, char *ys)
{
    int i;
    i=0;
    while((*(xs+i)=*(ys+i))!='\0'){
        i++;
    }
}
/*copea una string a otro de modo recursivo */
void copia_rec(char *xs, char *ys,int tam)
{
    if(*(ys+tam)!='\0'){
        *(xs+tam)=*(ys+tam);
        copia_rec(xs,ys,tam+1);
    }

}

void imprimir(char *xs)
{
    int i;
    int tamano=len(xs);
    for(i=tamano-1;i>=0;--i)
        printf("%c",*(xs+i));
}

/*concatena una string con la cabeza de otro string o con un char */
void concatenar(char *xs, char *ys)
{
    int i, j;
    i=j=0;
    while(*(xs+i)!='\0')
        i++;
    /*while(*(xs+i)=*(ys+j))!='\0'){
        ++i;
        ++j;
    }*/
    *(xs+i)=*(ys+j);
}

/*invierte un string */
void r_imprimir(char *xs,int tamano)
{   
    int i=0;
    if(tamano>=0){
        concatenar(vacio,&xs[tamano-1]);
        r_imprimir(xs,tamano-1);
    }
    else if (tamano<0)
        copia_rec(xs,vacio,i);
}
 
// Devuelve el tamaño del string
int len(char *ys)
{
    int tam=0;
    int i;
    for(i=0;*(ys+i)!='\0';++i)
        ++tam;
    return tam;
}

//convierte de mayusculas a minusculas
int lower(int c){
    return c+'a'-'A';
}
//ubica la ultima letra a buscar en un string
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
//función exponencial
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

//convertidor de String a numero
float conver(char *xs)
{
    int i, m, j, potencia;  

    float base, n, decimal;
    n=0;
    base=10;
    decimal=0;
    potencia=0;
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
        potencia=(-1)*potencia;
        return n*(expo(base,potencia));
    }
    else if(*(xs+i+m+j)!='-'){
        potencia=0;
        if(*(xs+i+m+j)=='+'){
            for(j=2;*(xs+i+m+j)!='\0';++j){
                if(*(xs+i+m+j)>='0'&& *(xs+i+m+j)<='9') 
                    potencia=10*potencia+(*(xs+i+m+j)-'0');
            }              
            return n*(expo(base,potencia));

        }
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
    char num_pos[]="123.456e+9";
    char num_neg[]="123.456e-9";
    printf("numero grande: %g\nnumero pequeño: %g\n", conver(num_pos),conver(num_neg));

    //cuarto ejemplo........
    printf(".......................................\n");
    char palabra[]="abcdefg";
    int t=len(palabra);
    int j;
    char *uni;
    uni=palabra;
    printf("palabra original: ");
    for(j=0;j<t;++j)
        printf("%c",*(uni+j));
    r_imprimir(palabra,t);
    int i;
    char *phi;
    phi=palabra;
    printf("\npalabra invertida: ");
    for(i=0;i<len(palabra);++i)
        printf("%c",*(phi+i));
    return 0;
}
