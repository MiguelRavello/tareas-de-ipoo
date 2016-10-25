#include<stdio.h>
#define IN 1 //en la palabra
#define OUT 0 //outside a word

int main(){
    int c, lines, words, caracteres, estado;
    estado=OUT;
    lines=words=caracteres=0;
    while((c=getchar()) != EOF){
        ++caracteres;
        if(c=='\n')
            ++lines;
        if(c==' '||c=='\n'||c=='\t')
            estado=OUT;
        else if(estado==OUT){
            estado=IN;
            ++words;
        }
    }
    printf("%d %d %d\n", lines, words, caracteres);
    //los caracteres tales como ... ,,, []]] bueno diferentes a 
    //las letras, tmb son considerados como palabras, por lo q 
    //seria el unico bug por el momento.
    //excepto cuando se escribe asi: momento, al fin.
    //acompañado de una palabra
    return 0;
}
