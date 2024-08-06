#ifndef PREN_H
#define PREN_H

#include "patologie.h"
#include "lavori.h"

typedef struct nodo_prenotazione* lista_prenotazioni;

struct nodo_prenotazione{
    char nome[30];
    char cognome[30];
    int eta;
    char codice_fiscale [17];
    int cap;
    int n;
    lista_lavori lavoro;
    lista_prenotazioni next;
};


lista_prenotazioni crea_prenotazione();

int inserisci_prenotazione(lista_prenotazioni* lista, char nome[], char cognome[], int eta, char codice_fiscale[],int cap, lista_patologie lispatologia, lista_lavori lislavoro);

int cerca_prenotazione_per_codicefiscale(lista_prenotazioni lista, char codice_fiscale);

void stampa_prenotazione(lista_prenotazioni lista);

void stampa_tutte_prenotazioni(lista_prenotazioni lista);

#endif

