#include<stdio.h>

/*cuenta las lineas de entrada
 1.8

int main()
{
    int c, nl;
    nl=0;
    while((c=getchar())!=EOF){
        if(c=='\n')
            nl++;
    }
    printf("%d\n",nl);
    return 0;

}*/
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
    printf("tab: %d \n",tab);
    printf("nueva lineas: %d \n",nline);
    return 0;
}


