#include<stdio.h>

int main(){
     int c, esp_blanco, tab, nline;
     esp_blanco=0;
     tab=0;
     nline=0;
     while((c=getchar())!=EOF){
         if(c==' ')
             ++esp_blanco;
         if(c=='\t')
             ++tab;
         if(c=='\n')
             ++nline;
     }
     printf("espacio en blanco: %d \n",esp_blanco);
     printf("tabulacion: %d \n",tab);
     printf("nueva lineas: %d \n",nline);
     return 0;
}
