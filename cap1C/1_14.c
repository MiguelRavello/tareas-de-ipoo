#include<stdio.h>
//#include<string.h>

void imprimir(int x){
    int i;
    char leng[x];
    for(i=0;i<x;i++)
        leng[i]='*';
    for(i=0;i<x;i++)
        printf("%c", leng[i]);
}

int main(){
    int c, i, nwhite,nother;
    int nletras[26];
    nwhite = nother =0;
    for(i=0;i<26;++i)
        nletras[i]=0;
    while((c=getchar())!=EOF){
        if (c>='a' && c<='z')
            ++nletras[c-'a'];
        else if(c==' '||c=='\n'||c=='\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("letras \n");
    for(i=0;i<26;++i){
        imprimir(nletras[i]);
        printf("\n");
    }
    //printf(", espacio en blanco: %d, other: %d\n", nwhite, nother);
}

/*int main(){
     int c, nl, nw, nc, state;
     state=OUT;
     int caracter, blank;
     nl=nw=nc=caracter=blank=0;
     while((c=getchar())!=EOF){
         ++nc;
         if(c!=' ' || c!='\t')
             ++caracter;
         if(c=='\n')
             ++nl;
         if(c==' '||c=='\n'||c=='\t'){
             ++blank;
             caracter=0;
             state=OUT;
         }
         else if(state==OUT){
             state=IN;
             ++nw;
         }
         if(caracter==1 && blank!=0){
             putchar('\n');
             ++nl;
             blank=0;
         }
         if(caracter!=0 && blank==0)
             putchar('-');
     }
     printf("\nlineas: %d\npalabras: %d\ncaracteres: %d\n",nl,nw,nc);
     return 0;
}*/

