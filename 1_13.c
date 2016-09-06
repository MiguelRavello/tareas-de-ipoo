#include<stdio.h>
#define IN 1
#define OUT 0

int main(){      
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
}
