#ifndef PATOLOGIE_H
#define PATOLOGIE_H

typedef struct nodo_patologia* lista_patologie;

struct nodo_patologia{
    char patologia[20];
    int n;
    lista_patologie next;
};


lista_patologie crea_patologia();

int inserisci_patologia (lista_patologie* lista, char patologia[]);

int cerca_patologia (lista_patologie lista, char patologia[]);

char associa_patologia_a_paziente(lista_patologie lista, int n);

int cancella_patologia( lista_patologie* lista, int n);

void stampa_patologia (lista_patologie lista);

void stampa_lista_patologie (lista_patologie lista);

#endif

