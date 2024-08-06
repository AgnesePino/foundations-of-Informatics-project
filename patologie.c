#include "patologie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//crea una lista vuota
lista_patologie crea_patologia(){
	return NULL;
}

//inserisce nuova patologia
int inserisci_patologia (lista_patologie* lista, char patologia[])
{
    lista_patologie r = *lista;
    lista_patologie q = *lista;
    
    lista_patologie p = (lista_patologie)malloc(sizeof(struct nodo_patologia));

    if(p == NULL) return 1;
    strcpy(p->patologia, patologia);
    int n=1;
    
    int X=cerca_patologia(*lista, patologia);
    if(X==1) return 2;
    
    while (q!= NULL){
       r = q;
       q = q->next;
       n=n+1;
        
    }

    if(q==*lista){
      p->next = *lista;
      *lista=p;
      p->n=n;
    }
    else{
      r->next = p;
      p->next = q;
      p->n=n;
    }  
    return 0;
}

int cerca_patologia (lista_patologie lista, char patologia[]) {
    while ((lista != NULL) && strcmp(lista->patologia, patologia)!=0){
        lista = lista->next;
    }
    if (lista == NULL)return 0;
        else return 1; 
}

char associa_patologia_a_paziente(lista_patologie lista, int n){
    while ((lista != NULL) && (lista->n!=n)){
        lista = lista->next;
    }
    if (lista == NULL)return NULL;
    else {
    char pat= lista->;
      return pat;
    } 
}

//cancella patologia
int cancella_patologia(lista_patologie* lista, int n){
    lista_patologie r = *lista; 
    lista_patologie q = *lista; 
    lista_patologie p = *lista;
    int c=1; 
    while ((q != NULL) && (q->n!=n)){
        r = q;
        q = q->next;
    }
    if (q == NULL)  
        return 1;
    if (q==*lista)
        (*lista) = (*lista)->next;
    else
        r->next = q->next;
    free(q);
    
     while ((p!= NULL)&&(p->n<=c)){
       p = p->next;
       c=c+1;
    }
    
    while(p!=NULL){
    p->n=c;
    p=p->next;
    }
    return 0; 
}

//stampa singola patologia
void stampa_patologia (lista_patologie lista){
    printf("(%d) %s \n", lista->n, lista->patologia);
}

//stampa lista di patologie
void stampa_lista_patologie (lista_patologie lista){
	while (lista != NULL){
        stampa_patologia (lista);      
        lista = lista->next;
    }
}
