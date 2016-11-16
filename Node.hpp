// Definizione interfaccia
#ifndef NODE_HPP
#define NODE_HPP

#include "Map.hpp"
#include <cstddef>
#include <iostream>

class Node
{
   protected:

   // puntatori per collegarsi alle altre stanze
   Node* nord;
   Node* sud;
   Node* est;
   Node* ovest;

   // Coordinate
   int x;
   int y;

   public:

   // Costruttore
   Node(int xx, int yy);

   // Ricerca ricorsiva di un nodo sulla mappa
	Node* search_node(int x, int y, Node& current, Map& search_map);

   // Accetta solamente i caratteri 'n' 's' 'e' 'o', ritorna il puntatore del
   // nodo in base al carattere passato
	Node* get_cardinal(char cardinal_dir);

   // Ritornano semplicamente i valori y e x
	int get_y();
	int get_x();

   // impostano i valori x e y
	void set_x(int xx);
	void set_y(int yy);

   // Imposta il puntatore della direzione chiesta, verso il nodo passato, n
	void set_cardinal(char cardinal_dir, Node& n);

   // Metodo chiamato da add node per collegare nodi adiacenti al nodo current 
   void link_adjacent(char exclude, Node* current, Node& origin);

   // Metodo per aggiungere nodi. In base al nodo start e la direzione crea un nuovo nodo
   // usando la search e link_adjacent collega eventuali nodi vicini (come da specifica)
   // inoltre chiama le funzioni grafiche della mappa per aggiornare la draw_map
   void add_node(Node& start, char direction, Map& draw_map, Node& origin);
};

#endif
