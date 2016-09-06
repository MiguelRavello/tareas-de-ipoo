#include<stdio.h>

int main(){
    int c;
    char a = '/';
    char t = 't'; //tab
    char b = 'b'; //backspace
    char n = 'n'; //newline
    while((c=getchar())!=EOF){
        if(c==' '){
            c=b;
            putchar(a);
           // putchar(c);
        }
        if(c=='\t'){
            c=t;
            putchar(a);
           // putchar(c);
        }
        if(c=='\n'){
            putchar(a);
            putchar(a);
            putchar('\n');
        }
        //if(c!=' ' || c!='\t' || c!='\n')
        putchar(c);
    }
    return 0;
}
