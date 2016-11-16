// Definizione interfaccia
#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>
#include <iostream>
#include <cmath>

// Lista per le ascisse nella matrice
struct listaX
{
   listaX* next;                 // Puntatore al nodo successivo
   int val;                      // valore da stampare in linea con la griglia di nodi es: [X], [1]... etc
   int pres;                     // tiene il numero di giocatori presenti nel nodo

   bool turn;                    // se true, stampa graffe nel nodo xy, serve per capire dove si trova il giocatore che fa il turno

   listaX() : turn(false){}      // imposta turn = false, ogni volta che si usa la struttura
};

// Lista per le ordinate nella matrice
struct listaY
{
   listaY* down;                 // Puntatore alla ordinata successiva
   listaX* h;                    // Puntatore alla lista di ascisse
};

class Map
{
protected:
   listaY* origin;   // puntatore alla testa della lista di ordinate
   int width;        // larghezza mappa (numero di colonne)
   int height;       // altezza mappa (numero di righe)
   int mostLeft;     // intero che tiene la x del nodo piu in alto a sx
   int mostUp;       // intero che tiene la y del nodo piu in alto a dx

public:
   Map(int w, int h);          						   // Costruttore

   void init(int playerNum);   						   // Metodo che inizializza la mappa con una matrice 1x1

   void draw(int n);                				   // Disegna a schermo la mappa

   void addLine(bool onTop);   						   // Aggiunge una riga in testa o in coda alle ascisse

   void addColumn(bool onTop); 						   // Aggiunge una colonna in testa o in coda alle ordinate

   void changeValue(int x, int y, int v, int p);	// Permette di cambiare valori all' interno della mappa

   int getValueAt(int x, int y); 					   // Ritorna il valore nella posizione x,y nella mappa il valore -99999 significa coordinate sbagliate

   int getPresAt(int x, int y); 					      // Ritorna il valore nella posizione x,y nella mappa il valore -99999 significa coordinate sbagliate 
	
   void draw_search();                  		 	   // Metodo di debug per la funzione cerca nodo

   void delete_map(bool garbage);        			   // Metodo che reinizializza la mappa con o senza garb collection (Attenzione il nodo di coordinate (0,0) contiene il valore 0)

   void set_Turn(int x, int y, bool t);            // Segna nelle coordinate x y dove avviene il turno corrente

};

#endif
