#include "pren.h"
#include "posti.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

lista_posti crea_posto(){
    return NULL; 
}

//verifica se una lista e' vuota
//restituisce 0 se la lista e' vuota, 1 se la lista ha qualche elemento
int is_empty(lista_posti lista){

    if(( p == NULL)&&(q== NULL))
        return 0;
    else
        return 1;
}

int is_full(lista_posti lista){
	//lista c'è ancora spazio
	if(lista->k<N) return 1;	
	//lista è pieno
	return 0;
}	
//inserisce un elemento ordinatamente in lista
//restituisce 0 se tutto va a buon fine, 1 in caso contrario
int (lista_posti* lista, int ora, int giorno, int mese, int anno){
    lista_posti q = *lista;

    lista_posti d = *lista;
    lista_posti p = (lista_posti)malloc(sizeof(struct nodo_posto));

    if(p == NULL) return 1;

    if(is_full(lis)==0) return 2;
    else
    {
        p->ora=ora;
        p->giorno=giorno;
        p->m=mese;
        p->anno=anno;
        strcpy(p->luogo, "nessuno");
        p->prenotazione = crea_prenotazione();
    
        if(is_empty(lis)==0){
		    p->next=NULL;
	    	p->next=NULL;
	    	(lista->head)=p;
	    	(lista->tail)=p;
	    	(p->k)=1;
	    	return 0;	
    	}
	    else
	    {
	    	while ((q!=NULL)&&((q->m)<(p->m))&&((q->giorno)<(p->giorno))&&((q->ora)<(p->ora))){
	       q=q->next;
	        (p->k)++;
    	}
	
    	//elemento posizionato al primo posto
     	if(q==(lista->head)){
	    	(lista->head)=p;
                q->prec=p;
	    	p->next=q;
	    	p->prec=NULL;
       }
    
    	else 
    	{   //elemento posizionato all'ultimo posto
		    if (q==NULL){
		        (lista->tail)->next=p;
                p->prec=(lista->tail);
                p->next=NULL;
		        (lista->tail)=p;
	        }
	         //elemento posizionato ordinatamanete nel corpo della lista
	    else{
	    	    p->next=q;
	         	p->prec=q->prec;
	         	q->prec->next=p;
	        	q->prec=p;
        	}
	   }
	   //tutto è andato a buon fine	
       return 0;
       }
	}
	
}

int associa_posto_a_prenotazione(lista_posti lista, lista_prenotazioni prenotazione){

    lista_prenotazioni r = prenotazione;
    int n=1;
    do {
       
        if (lista->prenotazione == NULL){
            if((r->lavoro!=NULL)||(r->patologia!=NULL)){
            
                    lista->prenotazione=prenotazione;

                    if((r->cap<=98141)&&(r->cap>=98138)){lista->m=1; return 0;}
                    if((r->cap<=98137)&&(r->cap>=98134))strcpy(lista->luogo, "Nizza di Sicilia Via c. todaro");
                    if((r->cap<=98133)&&(r->cap>=98131))strcpy(lista->luogo, "Salita Itala, Scaletta Via salita di Sicilia");
                    if((r->cap<=98128)&&(r->cap>=98125))strcpy(lista->luogo, "Centro Vaccinale Messina Sud S.S. 114 km 5400 - Pistunina");
                    if(((r->cap<=98120)&&(r->cap>=98124))||((r->cap<=98144)&&(r->cap>=98151)))strcpy(lista->luogo, "Centro Vaccinale Centro, Via Giuseppe la Farina,84");
                    if((r->cap==98152)||((r->cap>=98168)&&(r->cap<=98164)))strcpy(lista->luogo, "Centro Vaccinale Nord Via Sant'Elia, 26");
                    if((r->cap<=98153)&&(r->cap>=98163))strcpy(lista->luogo, "Centro Vaccinale, Villafranca Tirrena, Via Principale Villafranca Tirrena");
                    return 0;
           }
          else{
           while(lista->m<4){
                lista=lista->next;
           }
           lista->prenotazione=prenotazione;
           if((r->cap<=98141)&&(r->cap>=98138))lista->m=1; return 0;
           if((r->cap<=98137)&&(r->cap>=98134))strcpy(lista->luogo, "Nizza di Sicilia Via c. todaro");
           if((r->cap<=98133)&&(r->cap>=98131))strcpy(lista->luogo, "Salita Itala, Scaletta Via salita di Sicilia");
           if((r->cap<=98128)&&(r->cap>=98125))strcpy(lista->luogo, "Centro Vaccinale Messina Sud S.S. 114 km 5400 - Pistunina");
           if(((r->cap<=98120)&&(r->cap>=98124))||((r->cap<=98144)&&(r->cap>=98151)))strcpy(lista->luogo, "Centro Vaccinale Centro, Via Giuseppe la Farina,84");
           if((r->cap==98152)||((r->cap>=98168)&&(r->cap<=98164)))strcpy(lista->luogo, "Centro Vaccinale Nord Via Sant'Elia, 26");
           if((r->cap<=98153)&&(r->cap>=98163))strcpy(lista->luogo, "Centro Vaccinale, Villafranca Tirrena, Via Principale Villafranca Tirrena");
           return 0;
          }
        }  
        
       else
       lista=lista->next;
     }while(lista->prenotazione !=NULL);
    return 1;
}


//cancella data
int cancella_posti_per_data (lista_posti lista, int giorno, int mese){
    while((lista->mese!=mese)&&(lista->giorno!=giorno)&&(lista!= NULL))
    {
        lista=lista->next;
    }
    if (lista== NULL){ return 1;}
    else {
        free(lista);
        return 0;
    }
}

int calcolo_numero_vaccini(lista_posti lista){
   int fatti;
   int vac;
   vac=500000;
   fatti=0;
   if(is_full(lista)==0) vac=0;
   else{
   	while ((lista != NULL)){
        if(lista->prenotazione == NULL){
        fatti=fatti+1;
        }
        lista = lista->next;
    }
   vac=fatti-vac;
   }
   return vac;
}

void stampa_posto (lista_posti lista, lista_prenotazioni prenotazione){

    while(lista->prenotazione!= prenotazione)
    {
        lista=lista->next;
    }
    if(lista->prenotazione == prenotazione)
    {
        printf("%d, %d/%d/%d %s\n", lista->ora, lista->giorno, lista->m, lista->anno, lista->luogo);
    }
    else lista=NULL;
    }

//stampa tutte le prenotazioni
void stampa_tutti_posti (lista_posti lista, lista_prenotazioni prenotazione){
    while ((lista != NULL)){
        stampa_posto(lista,prenotazione);
        prenotazione = prenotazione ->next;
        lista = lista->next;}
}
