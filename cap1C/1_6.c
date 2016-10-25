#include<stdio.h>

int main()
{
    int c;    
    while((c=getchar())!=EOF){
        putchar(c); //imprime el texto recivido 
        printf("verificacion: %d \n", c!=EOF); //print 1 pq no ha finalizado el archivo
    }
    printf("new verification: %d \n", c!=EOF); //print 0 pq ya finalizo el archivo
    printf("EOF value: %d ",EOF);
    return 0;
}
