#include "utente.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

lista_utente crea_utente(){
    return NULL;
}

int registrazione(lista_utente* lista, char email[], char password[]){
    
    lista_utente q = *lista;
    lista_utente r = *lista;
    lista_utente p = (lista_utente)malloc(sizeof(struct nodo_utente)); 
    
    if(p == NULL) return 1;

    strcpy(p->email, email);
    strcpy(p->password, password);
    
    //int X=cerca_utente_per_email(&lista, email);
    //if(X==1) return 2;
    //else{
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

// 1 se trova email e passeord utente già esistente, 0 se esiste già l'utente ma password diversa password sbagliata, 0 sennò utente non trovato
int cerca_utante_per_email_password(lista_utente* lista, char email[], char password[]){
    lista_utente p= *lista;
    if(p==NULL) return 0;
    //int X=cerca_utente_per_email(&p, email);
    //if(X==1) 
    //{
        if(strcmp(p->password, password)==0) return 1;
        return 0;
    //}
    //else 
    return 2;
}

//restituisce 1 quando trova la password
int cerca_utente_per_email(lista_utente* lista, char email[]){
     lista_utente p= *lista;
     while ((p != NULL) && strcmp(p->email, email)!=0){
      p = p->next;
    }
    if(p==NULL)return 0;
    else return 1;
}


/*int cancella_utente(lista_utente* lista, char email[]){
//due puntatori di appoggio che faccio puntare inizialmente alla testa
    lista_utente r = *lista; //precedente (rosso)
    lista_utente q = *lista; //successivo (blu)
    //cerco l'elemento (al piu' arrivo alla fine della lista)
    while ((q != NULL) && (q->email != email)){
        //r raggiunge q
        r = q;
        //q va avanti di uno
        q = q->next;
    }
    //se sono arrivato alla fine della lista l'elemento non c'e'
    if (q == NULL)  
        return 1;
    //se sono ancora in testa alla lista devo spostare la testa
    if (q==*lista)
        (*lista) = (*lista)->next;
    //se sono in una posizione intermedia il precedente deve puntare al successivo di q
    //nota: q punta all'elemento che voglio cancellare
    else
        r->next = q->next;
    //dealloco l'elemento
    free(q);
    //tutto e' andato a buon fine
    return 0; 
}*/

