#ifndef POSTI_H
#define POSTI_H

#include "pren.h"

#define N 500000
typedef struct nodo_posto* lista_posti;

struct nodo_posto{
    int ora;
    int giorno;
    int mese;
    int anno;
    char luogo[80];
    lista_prenotazioni prenotazione;
    int k;
    lista_posti next;
    lista_posti prec;
};

struct lista{
    lista_posti head;
    lista_posti tail;
};
lista_posti crea_posto();

int is_empty(lista_posti lista);

int is_full(lista_posti lista);

int inserisci_ordinatamente_posto (lista_posti* lista, int ora, int giorno, int mese, int anno);

int associa_posto_a_prenotazione(lista_posti lista, lista_prenotazioni prenotazione);

int cancella_posti_per_data (lista_posti lista, int giorno, int mese);

int calcolo_numero_vaccini(lista_posti lista);

void stampa_posto (lista_posti lista, lista_prenotazioni prenotazione);

void stampa_tutti_posti (lista_posti lista, lista_prenotazioni prenotazione);
#endif


