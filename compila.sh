gcc -c utente.c -o utente.o
gcc -c lavori.c -o lavori.o
gcc -c patologie.c -o patologie.o
gcc -c pren.c -o pren.o
gcc -c posti.c -o posti.o
gcc -c main.c -o main.o
gcc -o main utente.o lavori.o patologie.o pren.o posti.o main.o
rm  utente.o lavori.o patologie.o pren.o posti.o main.o
