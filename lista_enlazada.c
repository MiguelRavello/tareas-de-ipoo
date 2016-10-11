#include<stdio.h>
#include<stdlib.h>

typedef struct node nodo_t;
struct node{
    int val;
    nodo_t *next;
};

void crear(nodo_t *head,int v1,int lim){
    //head=malloc(sizeof(struct node));
    //pq no usar el malloc dentro de la funcion;
    //cual es la causa de q al ser usado no haga ningun efecto
    head->val=v1;
    nodo_t *prev,*cur;
    int i=v1+1;
    prev=head;
    while(i<=lim){
        cur=malloc(sizeof(nodo_t));
        cur->val=i;
        prev->next=cur;
        prev=cur;
        i++;
    }
    prev->next=NULL;
    //free(cur);
    //pq cuando libero a cur 
    //sucede un bucle infinito **1
}
void concatenar(nodo_t *hx,nodo_t *hy){
    nodo_t *prev, *cur;
    prev=hx;
    cur=hx->next;
    while(1){
        if(cur==NULL){
            prev->next=hy;
            free(cur);
            break;
        }
        prev=cur;
        cur=cur->next;
    }
}

void inicio(nodo_t *head, nodo_t *xs){
    xs->next=head;
}

void middle(nodo_t *head, nodo_t *xs){
    nodo_t *prev, *cur;
    prev=head;
    cur=head->next;
    int lim=len(head)/2;
    int i=1;
    while(cur!=NULL){
        if(i==lim){
            prev->next=xs;
            xs->next=cur;
            break;
        }
        prev=cur;
        cur=cur->next;
        i++;
    }
}

void insertar(nodo_t *head, nodo_t *xs,int posicion){
    nodo_t *prev, *cur;
    prev=head;
    cur=head->next;
    int i=0;
    while(cur!=NULL){
        if(i==posicion){
            prev->next=xs;
            xs->next=cur;
            break;
        }
        prev=cur;
        cur=cur->next;
        i++;
    }
}

int len(nodo_t *head){
    nodo_t *t;
    t=head;
    int conta=0;
    while(t!=NULL){
        conta++;
        t=t->next;
    }
    free(t);
    return conta;
}

void imprimir(nodo_t *head){
    nodo_t *t;
    t=head;
    while(t!=NULL){
        printf("%d->",t->val);
        t=t->next;
    }
    free(t);
}

int main(){
    nodo_t *head_1;
    head_1=malloc(sizeof(nodo_t));
    int a=1;
    int b=4;
    crear(head_1,a,b);       
    imprimir(head_1);
    printf("\n..............................\n");
    nodo_t *head_2;
    head_2=malloc(sizeof(nodo_t));
    int x=8;
    int y=13;
    crear(head_2,x,y);
    imprimir(head_2);
    printf("\n..............................\n");
    concatenar(head_1,head_2);
    imprimir(head_1);
    printf("\n..............................\n");
    nodo_t *ini;
    ini=malloc(sizeof(nodo_t));
    ini->val=0;
    inicio(head_1,ini);
    int tam=len(ini);
    printf("%d \n",tam);
    imprimir(ini);
    printf("\n..............................\n");
    nodo_t *medio;
    medio=malloc(sizeof(nodo_t));
    medio->val=5;
    middle(ini,medio);
    imprimir(ini);
    printf("\n..............................\n");
    nodo_t *pos;
    pos=malloc(sizeof(nodo_t));
    pos->val=6;
    int z=5;
    insertar(ini,pos,z);
    imprimir(ini);

    return 0;
}
