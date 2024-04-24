#include <iostream>
#include <stdlib.h>
#include <climits> // Aggiunto per INT_MAX
#include <ctime>   // Aggiunto per srand
#include <unistd.h>   // Aggiunto per srand

using namespace std;

// Definizione della struttura del nodo
struct st_nodo {
    int info;           // Informazione del nodo
    int peso;           // Peso dell'arco
    struct st_nodo *next; // Puntatore al prossimo nodo
};
typedef struct st_nodo *nodo; // Definizione di un puntatore a un nodo

const int DIM = 100; // Dimensione massima del grafo
int n = 0;           // Numero di nodi nel grafo
int m = 0;           // Numero di archi nel grafo

nodo L[DIM];         // Lista di adiacenza
int V[DIM];          // Array di flag per i nodi visitati

int f[DIM];          // Array delle distanze minime
int P[DIM];          // Array dei predecessori
nodo S = NULL;       // Lista dei nodi già visitati
nodo T = NULL;       // Lista dei nodi da visitare

nodo pila = NULL;    // Pila per operazioni ausiliarie

// Prototipi delle funzioni
void leggiGrafo();
void generaGrafoCasuale(int, int);
void Dijkstra(int);
bool nodiDaVisitare();
bool verificaF();
nodo creaNodo(int, int);
nodo inserimentoInCoda(nodo, nodo);
nodo inserimentoInTesta(nodo, nodo);
nodo rimuoviElemento(nodo, int);
int minimoF(nodo);
void stampaLista(nodo);
void stampaTutto();
bool cerca(nodo, int);
void stampaGrafo();

int main() {
    srand(time(NULL));

    do {
        cout << "Inserisci il numero di nodi: ";
        cin >> n;
    } while(n <= 0);
    do {
        cout << "Inserisci il numero di archi: ";
        cin >> m;
    } while(m <= 0);
    cout << "Genera grafo";
    generaGrafoCasuale(6,10);
    /*
    // 6, 10
    L[0] = inserimentoInCoda(L[0], creaNodo(2, 4));
    L[2] = inserimentoInCoda(L[2], creaNodo(1, 2));
    L[1] = inserimentoInCoda(L[1], creaNodo(3, 2));
    L[3] = inserimentoInCoda(L[3], creaNodo(5, 3));
    L[5] = inserimentoInCoda(L[5], creaNodo(3, 4));
    L[4] = inserimentoInCoda(L[4], creaNodo(1, 1));
    L[4] = inserimentoInCoda(L[4], creaNodo(5, 2));
    L[5] = inserimentoInCoda(L[5], creaNodo(4, 2));
    L[5] = inserimentoInCoda(L[5], creaNodo(2, 2));
    L[5] = inserimentoInCoda(L[5], creaNodo(0, 5));*/
    
    stampaGrafo();
    pila = NULL;              // Inizializza la pila a NULL
    cout << "Dijkstra";
    Dijkstra(0);              // Esegue l'algoritmo di Dijkstra partendo dal nodo 0
    
    //Stampa le distanze minime e i predecessori
    for(int i = 0 ; i < n ; i++) cout << f[i] << " ";
    cout << endl;
    for(int i = 0 ; i < n ; i++) cout << P[i] << " ";


    return 0;
}

// Funzione per leggere il grafo da input
void leggiGrafo() {
    // Inizializza la lista di adiacenza e il vettore di flag
    for(int i = 0 ; i < n ; i++) {
        L[i] = NULL;
        V[i] = 0;
    }

    // Legge gli archi del grafo
    for(int i = 0 ; i < m ; i++) {
        int s, d, p;
        cout << "(Arco " << i << ")" << endl;

        do {
            cout << "Inserisci il nodo sorgente: ";
            cin >> s;
        } while(s < 0 || s >= n);

        do {
            cout << "Inserisci il nodo destinazione: ";
            cin >> d;
        } while(d < 0 || d >= n);
        
        do {
            cout << "Inserisci il peso di (" << s << "," << d << "): ";
            cin >> p;
        } while(d < 0);
        
        // Inserisce l'arco nella lista di adiacenza del nodo sorgente
        L[s] = inserimentoInCoda(L[s], creaNodo(d, p));
    }
}

// Funzione per generare un grafo casuale
void generaGrafoCasuale(int pesoMin, int pesoMax) {
    // Inizializza la lista di adiacenza
    for (int i = 0; i < n; ++i) {
        L[i] = NULL;
    }

    // Genera m archi casuali
    for (int i = 0; i < m; ++i) {
        int s, d, peso;
        do {
            s = rand() % n;      // Nodo sorgente casuale
            d = rand() % n;      // Nodo destinazione casuale
        } while (s == d || cerca(L[s], d));  // Controlla che non ci sia già un arco tra la coppia di nodi o che non sia lo stesso nodo

        peso = rand() % (pesoMax - pesoMin + 1) + pesoMin;  // Peso casuale tra pesoMin e pesoMax

        // Inserisce l'arco nella lista di adiacenza del nodo sorgente
        L[s] = inserimentoInCoda(L[s], creaNodo(d, peso));
    }
}

// Implementazione dell'algoritmo di Dijkstra
void Dijkstra(int r) {
     
}

// Funzione ausiliaria per controllare se ci sono ancora nodi da visitare
bool nodiDaVisitare() {
    for(int i = 0 ; i < n ; i++)
        if(V[i] == 0) return true;
    return false;
}

// Funzione ausiliaria per controllare se ci sono nodi con distanza minima non infinita
bool verificaF() {
    for(nodo app = T ; app != NULL ; app = app->next)
        if(f[app->info] != INT_MAX) return true;
    return false;
}

// Funzione ausiliaria per cercare un nodo in una lista
bool cerca(nodo lista, int valore) {
    for(nodo app = lista ; app != NULL ; app = app->next)
        if(app->info == valore) return true;
    return false;
}

// Funzione ausiliaria per trovare il nodo con la distanza minima in una lista
int minimoF(nodo lista) {
    int min = f[lista->info]; // Inizializza il minimo con il valore del primo nodo
    int min_nodo = lista->info; // Salva l'indice del nodo corrispondente al minimo
    for(nodo app = lista->next; app != NULL ; app = app->next) { // Inizia dall'elemento successivo
        if(f[app->info] < min) {
            min = f[app->info];
            min_nodo = app->info; // Aggiorna l'indice del nodo corrispondente al nuovo minimo
        }
    }
    return (min == INT_MAX ? -1 : min_nodo); // Restituisce -1 se tutte le distanze sono infinite
}


// Funzione per creare un nuovo nodo
nodo creaNodo(int p, int q) {
    nodo app = (nodo)malloc(sizeof(nodo));
    app->info = p;
    app->peso = q;
    app->next = NULL;
    return app;
}

// Funzione per rimuovere un elemento da una lista
nodo rimuoviElemento(nodo lista, int val) {
    if(lista == NULL) return NULL;
    if(lista->info == val) {
        nodo app = lista->next;
        free(lista);
        return app;
    }
    nodo p1 = lista, p2 = lista->next;
    while(p2 != NULL) {
        if(p2->info == val) {
            p1->next = p2->next;
            free(p2);
            break;
        }
        p1 = p2;
        p2 = p2->next;
    }
    return lista;
}

// Funzione per stampare una lista
void stampaLista(nodo lista) {
    if(lista == NULL) cout << "x";
    else {
        cout << "| " << lista->info << " , "<<  lista->peso << "| -> ";
        stampaLista(lista->next);
    }
}

// Funzione per stampare la lista di adiacenza
void stampaTutto() {
    for(int i = 0 ; i < n ; i++) {
        if(L[i] == NULL) continue;
        cout << i << ": ";
        stampaLista(L[i]);
        cout << endl;
    }
}

// Funzione per inserire un nodo all'inizio di una lista
nodo inserimentoInTesta(nodo lista, nodo nuovo) {
    nuovo->next = lista;
    return nuovo;
}

// Funzione per inserire un nodo alla fine di una lista
nodo inserimentoInCoda(nodo lista, nodo nuovo) {
    if(lista == NULL) return nuovo;
    nodo p = lista;
    while(p->next != NULL) p = p->next;
    p->next = nuovo;
    return lista;
}

// Funzione per eliminare il primo nodo di una lista
nodo eliminazioneInTesta(nodo l) {
    if(l == NULL) return NULL;
    nodo n = l->next;
    free(l);
    return n;
}

// Funzione per eliminare l'ultimo nodo di una lista
nodo eliminazioneInCoda(nodo l) {
    if(l == NULL) return NULL;
    if(l->next == NULL) {
        free(l);
        return NULL;
    }
    nodo p1 = l;
    nodo p2;
    for(p2 = l->next ; p2->next != NULL ; p2 = p2->next) {
        p1 = p1->next;
    }

    free(p2);
    p1->next = NULL;
    return l;
}

// Funzione per stampare il grafo
void stampaGrafo() {
    for(int i = 0; i < n; ++i) {
        cout << "Nodo " << i << " -> ";
        stampaLista(L[i]);
        cout << endl;
    }
}
