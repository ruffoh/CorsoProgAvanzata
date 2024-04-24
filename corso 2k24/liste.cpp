#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
	int n ;
	struct s_nodo* next;
};

typedef struct s_nodo* nodo;
nodo creaNodo( int valoreNuovo);
nodo inserimentoInTesta( nodo lista, nodo nodoDaInserire);


int main() {
	nodo l = NULL;
	return 0;
}

nodo creaNodo( int valoreNuovo) {
	nodo nuovoNodo = (nodo)malloc(sizeof(nodo));  // malloc ritorna void * generico
	nuovoNodo ->n = valoreNuovo;
	nuovoNodo ->next = NULL;
	return nuovoNodo;
}

nodo inserimentoInTesta( nodo lista, nodo nodoDaInserire) {
	nodoDaInserire->next = lista;
	lista = nodoDaInserire;
	return lista;
}

nodo eliminazioneInTesta(nodo lista) {
	if(lista == NULL) return NULL;
	nodo app = lista->next;
	free(lista);
	lista = app;
	return app;
}
void stampaLista(nodo lista){
	nodo p = lista;
	while(lista != NULL){
		printf("%d\t",p->n);
		p = p->next;
	}
	
	if(lista == NULL){
		printf("fine lista\n");
	}
	else{
		printf("%d\n",lista->n);
		stampaLista(lista->next);
	}
	
	nodo inserimentoInCoda(nodo lista, nodo elementoDaInserire){
		nodo p = lista;
		while(p->next != NULL){
			p = p->next;
		}
	}
				
}
