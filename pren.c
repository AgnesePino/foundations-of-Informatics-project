#include "pren.h"
#include "patologie.h"
#include "lavori.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

lista_prenotazioni crea_prenotazione(){
    return NULL;
}


int inserisci_prenotazione(lista_prenotazioni* lista, char nome[], char cognome[], int eta, char codice_fiscale[],int cap, lista_patologie patologia, lista_lavori lavoro){

    lista_prenotazioni r = *lista;
    lista_prenotazioni q = *lista;
    
    lista_prenotazioni p = (lista_prenotazioni)malloc(sizeof(struct nodo_prenotazione));
    
    if(p == NULL) return 1;
      
    strcpy(p->nome, nome);
    strcpy(p->cognome, cognome);
    strcpy(p->nome, nome);
    p->eta=eta;
    strcpy(p->codice_fiscale, codice_fiscale);
    p->cap=cap;
    lispatologia->patologia=patologia;
    strcpy(lavoro->lavoro, lavoro);

    int X=cerca_prenotazione_per_codicefiscale(lista, codice_fiscale);
    if(X==1)return 2;

    while (q != NULL){
        r = q;
        q = q->next;
    }
    
    if(q==*lista){
        p->next = *lista;
        *lista=p;
    }
    else{
        r->next = p;
        p->next = q;
    }
  return 0;  
}

int cerca_prenotazione_per_codicefiscale(lista_prenotazioni lista, char codice_fiscale){
    while ((lista != NULL) && strcmp(lista->codice_fiscale, codice_fiscale)!=0){
        lista = lista->next;
    }
    if(lista==NULL)return 0;
    else return 1;
}

void stampa_prenotazione(lista_prenotazioni lista){
    printf("Nome:           %s \nCognome:        %s\nEta' :            %d\nCodice fiscale: %s\nCap:            %d\nPatologia:      %d %s\nLavoro:         %d %s\n", lista->nome, lista->cognome, lista->eta, lista->codice_fiscale, lista->cap, lista->patologia, lista->lavoro);
}

void stampa_tutte_prenotazioni(lista_prenotazioni lista){
    while ((lista != NULL)){
        stampa_pren(lista);
        lista = lista->next;
    }
}


