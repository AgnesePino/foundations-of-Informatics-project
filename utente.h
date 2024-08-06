#ifndef UTENTE_H
#define UTENTE_H

typedef struct nodo_utente* lista_utenti;

struct nodo_utente{
    char email[30];
    char password[30];
    lista_utenti next;
};


//crea una utente
lista_utenti crea_utente();

int registrazione(lista_utenti* lista, char email[], char password[]);

int cerca_utente_per_email_password(lista_utenti* lista, char email[], char password[]);

int cerca_utente_per_email(lista_utenti* lista, char email[]);

#endif

