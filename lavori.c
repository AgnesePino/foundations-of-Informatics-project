#include "lavori.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//crea una lista vuota
lista_lavori crea_lavoro(){
	return NULL;
}

//inserisce nuovo lavoro
int inserisci_lavoro (lista_lavori* lista, char lavoro[])
{
    lista_lavori r = *lista;
    lista_lavori q = *lista;
    
    lista_lavori p = (lista_lavori)malloc(sizeof(struct nodo_lavoro));

    if(p == NULL) return 1;
    int n=1;
    strcpy(p->lavoro, lavoro);
    
    int X=cerca_lavoro(*lista, lavoro);
    if(X==1) return 2;
    
    while (q != NULL){
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

//cerca una lavoro
int cerca_lavoro(lista_lavori lista, char lavoro[]){
  while ((lista != NULL) && strcmp(lista->lavoro, lavoro)!=0){
    lista = lista->next;
  }
  if (lista == NULL) return 0;
  else return 1;
}

lista_lavori associa_lavoro_a_paziente(lista_lavori lista, int n){
    while ((lista != NULL) && (lista->n!=n)){
        lista = lista->next;
    }
    if (lista == NULL)return NULL;
        else return lista; 
}
//cancella lavoro
int cancella_lavoro(lista_lavori* lista, int n){
    lista_lavori r = *lista; 
    lista_lavori q = *lista; 
    lista_lavori p = *lista;
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
void stampa_lavoro(lista_lavori lista){
    printf("(%d) %s \n", lista->n, lista->lavoro);
}

//stampa lista di patologie
void stampa_lista_lavori (lista_lavori lista){
	while ((lista != NULL)){
        stampa_lavoro(lista);
        lista = lista->next;
    }
}
