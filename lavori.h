#ifndef LAVORI_H
#define LAVORI_H

typedef struct nodo_lavoro* lista_lavori;

struct nodo_lavoro{
    char lavoro[30];
    int n;
    lista_lavori next;
};

lista_lavori crea_lavoro();

int inserisci_lavoro (lista_lavori* lista, char lavoro[]);

int cerca_lavoro (lista_lavori lista, char lavoro[]);

lista_lavori associa_lavoro_a_paziente (lista_lavori lista, int n);

int cancella_lavoro(lista_lavori* lista, int n);

void stampa_lavoro(lista_lavori lista);

void stampa_lista_lavori (lista_lavori lista);

#endif

