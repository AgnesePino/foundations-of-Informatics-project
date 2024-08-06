#include <stdio.h>
#include "pren.h"
#include "patologie.h"
#include "lavori.h"
#include "posti.h"
#include "utente.h"
#include <unistd.h>

#define BOLD_WHITE "\033[1m"
#define STANDARD_WHITE "\033[0m"
#define BOLD_RED "\033[1;31m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_PURPLE "\033[1;35m"
#define BOLD_MAGENTA "\033[1:30m"
#define BOLD_CYAN "\033[1;36m"


int main(){
  int d, v;
  v=5000.000;
  printf("\n\n\n\t\t"BOLD_WHITE"-- PRENOTAZIONE VACCINI -- "STANDARD_WHITE"\n\n");
  printf("Numero prenotazioni disponibili: "BOLD_WHITE" %d "STANDARD_WHITE"\n\n", v);
  lista_utenti utente=crea_utente();
  lista_prenotazioni pren = crea_prenotazione();
  lista_lavori lav= crea_lavoro();
  lista_patologie pat= crea_patologia();
  lista_posti pos= crea_posto();
  do{
    printf("\n\n\t\t\t"BOLD_WHITE"-HOME- "STANDARD_WHITE" \n\n"BOLD_WHITE"Scegli l'operazione da eseguire:"STANDARD_WHITE"\n(1) Prenota     (2) Login personale\n(3) Registrazione personale     (0) Esci\nSCelta:");
    scanf("%d", &d);
    
    if(d==1){
    int s;
    do{
      
      char nome[29], cognome[30], codfisc[30];
      int eta, cap,p, l;
      printf("\n\n\n\t"BOLD_WHITE"-COMPILAZIONE MODULO PER SOMMINISTRAZIONE VACCINO-"STANDARD_WHITE"\n\n\n");
      printf(""BOLD_WHITE"Nome:           "STANDARD_WHITE"");
      scanf("%s", nome);
    
      printf(""BOLD_WHITE"Cognome:        "STANDARD_WHITE"");
      scanf("%s", cognome);
    
      printf(""BOLD_WHITE"Eta':           "STANDARD_WHITE"");
      scanf("%d", &eta);
    
      printf(""BOLD_WHITE"Codice fiscale: "STANDARD_WHITE"");
      scanf("%s", codfisc);
    
      printf(""BOLD_WHITE"CAP:            "STANDARD_WHITE"");
      scanf("%d", &cap);
      
      printf(""BOLD_WHITE"\nQuale delle seguenti patologia presenta: \n"STANDARD_WHITE"");
      stampa_lista_patologie(pat);
      printf("\n(0) Nessuno\nScelta: ");
      scanf("%d", &p);
            
      printf(""BOLD_WHITE"\nProfessione: \n"STANDARD_WHITE"");
      stampa_lista_lavori(lav);
      printf("\n(0) Nessuna\nScelta:");
      scanf("%d", &l);
    
      lista_patologie patologia = associa_patologia_a_paziente(pat,p);
      lista_lavori lavoro = associa_lavoro_a_paziente(lav, l);
      
      printf(""BOLD_WHITE"\n\n\nModulo inserito correttamente:"STANDARD_WHITE" \n (1) Si   (0)No\nScelta:");
      scanf("%d", &s);
     
      
      if(s==1){
      inserisci_prenotazione(&pren, nome, cognome, eta, codfisc, cap, patologia, lavoro);
      
      printf("\n\n\n"BOLD_WHITE"-RISULTATO ANALISI MODULO DI PRENOTAZIONE VACCINO\n"STANDARD_WHITE"");
        
      int x=associa_posto_a_prenotazione(pos, pren);
      if(x==1){
    	printf(""BOLD_RED"cap non presente"STANDARD_WHITE"");
        printf("\n\n\nImpostazioni: \n (1) Home (0) Altra prenotazione\nScelta: ");
        scanf("%d", &s);
      } 
      if(x==2){
    	printf(""BOLD_RED"non ci sono posti"STANDARD_WHITE"");
    	printf("\n\n\nImpostazioni: \n (1) Home (0) Altra prenotazione\nScelta: ");
        scanf("%d", &s);
      } 
      else{
    	stampa_posto (pos, pren);
        printf("\n\n\nImpostazioni: \n (1) Home (2)Stanpa modulo completo (0) Altra prenotazione\nScelta: ");
        scanf("%d", &s);
        if(s==2){printf("\n\n\n"BOLD_WHITE"MODULO COMPLETO: "STANDARD_WHITE"\n\n");
          stampa_prenotazione(pren);
          stampa_posto (pos, pren);
        }
	   }   
      } 
    }while(s==0);
  }
    
    if(d==2)
    {
      int x,e;
      do
      {
        char email[30], password[30];
        printf("\n\n\n\t"BOLD_WHITE" -LOGIN PERSONALE- "STANDARD_WHITE" ");
        printf("\nInserisci email:   ");
        scanf("%s",email);
         
        printf("Inserisci password:");
        scanf("%s", password);
        x=cerca_utente_per_email_password(&utente, email, password);
        
        if(x!=1){
          printf("\n "BOLD_RED"!!Password sbagliata o utente non trovato!!"STANDARD_WHITE"\n(1)Riprovare   (0)Esci");
          printf("\nScegli: ");
          scanf("%d", &e);}
          else e=0;
       }while(e==1);
       
       if(x==1){ int c; do{
printf("\n\n\nScegli l'operazione da fare\n(1) Aggiungi lavoro    (2) Elimina lavoro \n(3) Aggiungi patologia    (4) Elimina patologia \n(5) Aggiungi data    (6) Elimina data\n       (0) Esci\nScelta:");
          scanf("%d", &c);
         
            if(c==1) { int s=0;;
            do{
                char lavoro[30];
                printf("\nLavoro da aggiungere: ");
                scanf("%s", lavoro);
                int o=inserisci_lavoro (&lav, lavoro);
                if(o==2)printf("\n"BOLD_RED"Lavoro già presente"STANDARD_WHITE"\n");
                if(o==1)printf(""BOLD_RED"\nErrore\n"STANDARD_WHITE"");
                stampa_lista_lavori(lav);
                printf("\nAggiungere un altro lavoro:\n(1)Si    (0)No\nScelta:");
                scanf("%d", &s);
                }while(s==1);
             }
             
            if(c==2){int s=0;; 
              do{
                int n;
                  printf("\nIndica la posizione tra i seguenti lavori da eliminare: \n");
                  stampa_lista_lavori(lav);
                  printf("(0)Nessuna\nScelta: "); scanf("%d", &n);
                  if(n!=0){
                  int o=cancella_lavoro(&lav, n);
                  if(o==1)printf(""BOLD_RED"\nErrore\n"STANDARD_WHITE"");}
                  stampa_lista_lavori(lav);
                  printf("\nEliminare un altro lavoro?\n(1)Si    (0)No");
                  printf("\nScelta:");
                  scanf("%d", &s);            
                 }while(s==1);
               }
               
            if(c==3){int s=0; 
              do{
                char patologia[30];
                printf("\nPatologia da aggiungere: ");
                scanf("%s", patologia);
                int o=inserisci_patologia(&pat, patologia);
                if(o==2)printf(""BOLD_RED"\n!!Patologia già presente!!"STANDARD_WHITE"\n");
                if(o==1)printf(""BOLD_RED"\nErrore\n"STANDARD_WHITE"");
                stampa_lista_patologie(pat);
                printf("\nAggiungere un altra patologia?\n(1)Si    (0)No\nScelta:");
                scanf("%d", &s);
              }while(s==1);
            }
            
            if(c==4){int s=0; 
              do{
                 int n;
                  printf("\nIndica la posizione tra le seguenti patologie da eliminare: \n");
                  stampa_lista_patologie(pat);
                  printf("(0)Nessuna\nScelta: "); scanf("%d", &n);
                  if(n!=0){int o=cancella_patologia(&pat, n);
                  if(o==1)printf(""BOLD_RED"\nErrore\n"STANDARD_WHITE"");}
                  
                  stampa_lista_patologie(pat);
                  printf("\nEliminare un'altra patologia?\n(1)Si    (0)No");
                  printf("\nScelta:");
                  scanf("%d", &s);            
                 }while(s==1);
                }
             
             if(c==5){int s=0; 
               do{
                 int ora;
                 int giorno;
                 mese m;
                 int anno;
                 printf("\nData da aggiungere: ");
                 scanf("%d %d %d", &ora, &giorno, &anno);
                 int x=inserisci_ordinatamente_posto (&pos, ora, giorno, m, anno);
                 if(x==2) printf(""BOLD_RED"vaccini non pi� disponibili per nuove somministrazioni\n"STANDARD_WHITE"");
                 if(x==1) printf(""BOLD_RED"Errore \n"STANDARD_WHITE"");
                 stampa_tutti_posti (pos,pren);
                 printf("\nAggiungere un altra data?\n(1)Si    (0)No");
                 printf("\nScelta:");
                 scanf("%d\n", &s);
               }while(s==1);
             }
             
            if(c==6){int s=0; 
              do{
                int giorno;
                mese m;
                printf("\nData da eliminare, inserire giorno e mese: ");
                scanf("%d", &giorno);
                int x=cancella_posti_per_data (pos, giorno, m);
                if(x==1) printf(""BOLD_RED"Data non trovata o Errore\n"STANDARD_WHITE"");
                stampa_tutti_posti (pos,pren);
                printf("\nEliminare un altra data?\n(1)Si    (0)No");
                printf("\nScelta:");
                scanf("%d\n", &s);
              }while(s=1);
             }
          
         }while(c!=0);
      }
    }
      if(d==3){
        int x,s;
        char email[30], password[30];
        printf("\n\n\t\t\t"BOLD_WHITE"-REGISTRAZIONE UTENTE- "STANDARD_WHITE"\n");
        do{
          printf("\nInserisci email:    ");
          scanf("%s", email);
          printf("Inserisci password: ");
          scanf("%s", password);
          
          x=registrazione(&utente, email, password);
          if(x==2){printf("\n"BOLD_RED"!!!Email già presente!!!"STANDARD_WHITE" \n(1)Riprovare (0)Esci \nScelta: ");
          scanf("%d", &x);}
          if(x==1){printf(""BOLD_RED"\nErrore\n"STANDARD_WHITE" (1)Riprovare (0)Esci \nScelta: ");
          scanf("%d", &x);}
          if(x==0){printf("\n"BOLD_GREEN"Registrazione avvenuta correttamente\n"STANDARD_WHITE""); }
        }while(x !=0);
      }
 
 }while(d!=0);
    printf("Grazie per aver usufruito della piattaforma di prenotazione\n              arrivederci e grazie!\n");
}
