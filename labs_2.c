#include<stdio.h>
//funcion q concatena una cadena y un char
void concatenar_1(char *xs,char *ys,int n){
    int m=0;
    if(*(xs+n)!='\0'){
        concatenar_1(xs,ys,n+1);
    }
    else
        *(xs+n)=*(ys+m);
}
//funcion q concatena dos cadenas
void conca(char *xs, char *ys){
    int i, j;
    i=j=0;
    while(*(xs+i)!='\0')
        i++;
    while((*(xs+i)=*(ys+j))!='\0'){
        i++;
        j++;
    }
}

void concatenar_n(char *xs,char *ys, int n, int m)
{
    if(*(xs+n)!='\0')
        concatenar_n(xs,ys,n+1,m);
    else if((*(xs+n)=*(ys+m))!='\0')
        concatenar_n(xs,ys,n+1,m+1);

}  
//cual sera el error q no concatene recursivamente bien
int len(char *xs){
    int i=0;
    while(*(xs+i)!='\0')
       ++i;
    return i;
}
//funcion para si un array es subconjunto de otro array
//si todos sus elementos pertenecen al otro array
int strod(char *xs, char *ys)
{   
    int i, j, val1;
    int tx=len(xs);
    int ty=len(ys);
    for(i=0;i<tx;i++){
        val1=0;
        for(j=0;j<ty;j++){
            if(*(xs+i)==*(ys+j)){
                val1=1;
                break;
            }
        }
        if(val1==0)
            return val1;
    }
    return val1;
}
//funcion q evalua si el final de una cadena es similar a otra cadena
int stlast(char *xs, char *ys)
{
    int i, j, val;
    int tx=len(xs);
    int ty=len(ys);
    for(i=0;i<tx;i++){
        val=0;
        for(j=(ty-tx-1);j<ty;j++){
            if(*(xs+i)==*(ys+j)){
                val=1;
                break;
            }
        }
        if(val==0)
            return val;
    }
    return val;
}

int bitemayus(int a){
    int b;
    b=a-32;
    int rpta= (a&b);
    //a = 1100001;
    //A = 1000001;
    return rpta;
}

void cadenamayus(char *xs){
    int tam=len(xs);
    int i;
    for(i=0;i<tam;i++){
        if(*(xs+i)!=' ')
            *(xs+i)=bitemayus(*(xs+i));
    }
}

int main(){
    printf("\n...........................\n");
    char mol[]="mol";
    char rav[]="ravinof";
    int i=0;
    int j=0;
    concatenar_n(mol,rav,i,j);
    printf("%s",mol);
    printf("\n...........................\n");
    char name[]="abcdef";
    char t[]="abc";
    char f[]="avc";
    int ar=strod(t,name);
    int br=strod(f,name);
    printf("%d %d",ar,br);
    printf("\n...........................\n");
    char gg[]="def";
    int c=stlast(gg,name);
    int d=stlast(t,name);
    printf("%d %d",c,d);
    printf("\n...........................\n");
    char a='a';
    char b=bitemayus(a);
    printf("%c",b);
    printf("\n...........................\n");
    char band[]="radio head";
    cadenamayus(band);
    printf("%s",band);
}
