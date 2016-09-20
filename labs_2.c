#include<stdio.h>
int len(char *xs){
    int i=0;
    while(*(xs+i)!='\0')
       ++i;
    return i;
}
//funcion para si un array es subconjunto de otro array
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

int bitemayus(int a){
    int b;
    b=a-32;
    int rpta= (a&b);
    //a = 1100001;
    //A = 1000001;
    return rpta;
}
/*void cadenamayus(char *xs){
    int tam=len(xs);
    int i;
    for(i=0;i<tam;i++){
        
    }
}*/



int main(){
   /* char name[]="abcdef";
    char t[]="abc";
    char f[]="avc";
    int a=strod(t,name);
    int b=strod(f,name);
    printf("%d %d",a,b);*/
    char a='a';
    char b=bitemayus(a);
    printf("%c",b);
}
