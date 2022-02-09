make up -> crea una rete docker composta da 1 server e 4 clients

ACCESSO e SWITCH ON al serverIRC:
atts	->	si attacca al container server
server	->	compila ed esegue il server corripondente al prerequisito della regola run nel Makefile

ACCESSO E SWITCH ON client:
attc[1-4]	->	si attacca al container client1
client[1-4]	->	esegue il programma nc con l'indirizzo del server e porta predefinita 6667

