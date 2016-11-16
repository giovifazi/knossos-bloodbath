// IN OGNI FILE DOVE SI USA IL TIPO NODE, TOCCA INCLUDERE NODE.HPP
#include "Node.hpp"

//Costruttore
Node::Node(int xx, int yy)
{
   x = xx;
   y = yy;
   nord = NULL;
   sud = NULL;
   est = NULL;
   ovest = NULL;
}

// metodi per ritornare le coordinate protected di un nodo
int Node::get_x()	{return x;}
int Node::get_y() {return y;}

// metodi per impostare le coordinate
void Node::set_x(int xx) {x = xx;}
void Node::set_y(int yy) {y = yy;}

// POSTCONDIZIONE: ritorna il puntatore cardinale del nodo in base alla
// direzione chiesta
Node* Node::get_cardinal(char cardinal_dir)
{
	switch (cardinal_dir)
	{
   	case 'n':
			return nord;
			break;

      case 's':
			return sud;
			break;

      case 'e':
			return est;
			break;

      case 'o':
			return ovest;
			break;
	}
}

// POSTCONDIZIONE: assegnando al puntatore cardinale del chiamante il nodo 
// passato come parametro, si effettua il collegamento fra chiamante ed n
void Node::set_cardinal(char cardinal_dir, Node& n)
{
	switch (cardinal_dir)
	{
		case 'n':
			nord = &n;
			break;

      case 's':
			sud = &n;
			break;

      case 'e':
			est = &n;
			break;

		case 'o':
			ovest = &n;
			break;
	}
}


// Funzione ricorsiva per la ricerca dei nodi nella griglia
// 
// PRECONDIZIONE: passare le coordinate integer del nodo da cercare, passare il
// Nodo origine della griglia di gioco e passare una mappa vuota
//
// POSTCONDIZIONE: la funzione ritorna il puntatore al nodo cercato, se esso
// esiste, altrimenti ritorna NULL
Node* Node::search_node(int x, int y, Node& current, Map& search_map)
{
 
   //std::cout << "cerco il nodo " << x << " " << y << "\ne sono nel " << current.x << " " << current.y << std::endl;

   // inizializzo il valore di ritorno a null ad ogni chiamata ricorsiva
	Node* ret = NULL;

	// Parte di debugging, cambia i valori nella mappa di ricerca per mostrare in
	// quale nodo sta avvenendo la ricerca e poi stampa la mappa
	search_map.changeValue(current.get_x(), current.get_y(), 2, 0);
	//search_map.draw_search();
	search_map.changeValue(current.get_x(), current.get_y(), 1, 0);
	//std::cout << "\n";

   // Caso base ricorsione (se il nodo e` stato trovato)
	if (current.get_x() == x && current.get_y() == y)
	{
			ret = &current;
			return ret;
	}
	else
	{
      // In base al nodo su cui mi trovo, se il puntatore a nord/est/sud/ovest
      // non e` nullo e se secondo la mappa non ho gia`  visitato il nodo a
      // nord/sud/est/ovest, aggiorno la mappa di ricerca e chiamo la funzione
      // sul nodo nel quale ho itenzione di spostarmi.
      // Se il nodo viene trovato, si assegna a ret l' indirizzo del nodo
      // e tramite if (ret != NULL) viene ritornato fino alla prima chiamata di
      // ricerca

		if (current.get_cardinal('n') != NULL && search_map.getValueAt(current.get_x(), current.get_y()+1) != 1)
		{
			if (search_map.getValueAt(current.get_x(), current.get_y()+1) == -99999)
				search_map.addLine(true);

			ret = search_node(x,y, (*current.nord), search_map);
		}

		if (ret != NULL)
			return ret;
		else
		{
			if (current.get_cardinal('e') != NULL && search_map.getValueAt(current.get_x()+1, current.get_y()) != 1)
			{
				if (search_map.getValueAt(current.get_x()+1, current.get_y()) == -99999)
					search_map.addColumn(false);

				ret = search_node(x,y, (*current.est), search_map);
			}
		}

		if (ret != NULL)
			return ret;
		else
		{
			if (current.get_cardinal('s') != NULL && search_map.getValueAt(current.get_x(), current.get_y()-1) != 1)
			{
				if (search_map.getValueAt(current.get_x(), current.get_y()-1) == -99999)
					search_map.addLine(false);

				ret = search_node(x,y, (*current.sud), search_map);
			}
		}

		if (ret != NULL)
			return ret;
		else
		{
			if (current.get_cardinal('o') != NULL && search_map.getValueAt(current.get_x()-1, current.get_y()) != 1)
			{
				if (search_map.getValueAt(current.get_x()-1, current.get_y()) == -99999)
					search_map.addColumn(true);

				ret = search_node(x,y, (*current.ovest), search_map);
			}
		}

		return ret;
	}
}




// Precondizione: vengono passati: un 'vecchio' nodo al quale aggiungerne uno nuovo,
// la direzione del nuovo nodo, la mappa di gioco per aggiornare i valori da stampare,
// il nodo origine (obbligatorio per usare la ricerca di nodi)
//
// Postcondizione: Viene aggiunto e collegato a nodi adiacenti, un nuovo nodo in
// base alla direzione richiesta
void Node::add_node(Node& old_node, char dir, Map& draw_map, Node& origin)
{
	// in base alla direzione viene creato il nuovo nodo
	// viene effettuato il collegamento fra il nuovo nodo e quello iniziale
	// vengono poi aggiornati i valori nella mappa grafica
		
   Node* p_new_node;   // Puntatore al nuovo nodo creato

	if (dir == 'n')
	{	
      //   [  ]  <- nuovo nodo 
      //    ^^ 
      //   [..]  <- vecchio nodo
	
      // Crea nuovo nodo
		old_node.nord = new Node(old_node.get_x(), old_node.get_y()+1);
		p_new_node = old_node.get_cardinal('n');

      // Collegamento nuovo nodo a quello vecchio
      p_new_node->set_cardinal('s', old_node);

		// parte grafica, allarga la mappa da disegno solo se ci si sposta out of bounds
		if (draw_map.getValueAt(p_new_node->get_x(), p_new_node->get_y()) == -99999)
			draw_map.addLine(true);
	
	   // Cambia i valori nella mappa per stampare giocatore e nuovo nodo
	   draw_map.changeValue(p_new_node->get_x(), p_new_node->get_y(), 1, 0);
		
		// collego eventuali nodi adiacenti al nodo appena creato
      link_adjacent('s', p_new_node, origin);
	}
	else if (dir == 's')
	{
	   //   [..]  <- vecchio nodo 
      //    vv 
      //   [  ]  <- nuovo nodo
	
      // Crea nuovo nodo
		old_node.sud = new Node(old_node.get_x(), old_node.get_y()-1);
		p_new_node = old_node.get_cardinal('s');

      // Collegamento nuovo nodo a quello vecchio
      p_new_node->set_cardinal('n', old_node);

		// parte grafica, allarga la mappa da disegno solo se ci si sposta out of bounds
		if (draw_map.getValueAt(p_new_node->get_x(), p_new_node->get_y()) == -99999)
			draw_map.addLine(false);
	
	   // Cambia i valori nella mappa per stampare giocatore e nuovo nodo
	   draw_map.changeValue(p_new_node->get_x(), p_new_node->get_y(), 1, 0);
		
		// collego eventuali nodi adiacenti al nodo appena creato
      link_adjacent('n', p_new_node, origin);
	}
	else if (dir == 'e')
	{
	   // vecchio nodo [..] >> [  ] nuovo nodo
	
      // Crea nuovo nodo
		old_node.est = new Node(old_node.get_x()+1, old_node.get_y());
		p_new_node = old_node.get_cardinal('e');

      // Collegamento nuovo nodo a quello vecchio
      p_new_node->set_cardinal('o', old_node);

		// parte grafica, allarga la mappa da disegno solo se ci si sposta out of bounds
		if (draw_map.getValueAt(p_new_node->get_x(), p_new_node->get_y()) == -99999)
			draw_map.addColumn(false);
	
	   // Cambia i valori nella mappa per stampare giocatore e nuovo nodo
	   draw_map.changeValue(p_new_node->get_x(), p_new_node->get_y(), 1, 0);
		
		// collego eventuali nodi adiacenti al nodo appena creato
      link_adjacent('o', p_new_node, origin);
	}
	else if (dir == 'o')
	{
	   // nuovo nodo [..] << [  ] vecchio nodo
	
      // Crea nuovo nodo
		old_node.ovest = new Node(old_node.get_x()-1, old_node.get_y());
		p_new_node = old_node.get_cardinal('o');

      // Collegamento nuovo nodo a quello vecchio
      p_new_node->set_cardinal('e', old_node);

		// parte grafica, allarga la mappa da disegno solo se ci si sposta out of bounds
		if (draw_map.getValueAt(p_new_node->get_x(), p_new_node->get_y()) == -99999)
			draw_map.addColumn(true);
	
	   // Cambia i valori nella mappa per stampare giocatore e nuovo nodo
	   draw_map.changeValue(p_new_node->get_x(), p_new_node->get_y(), 1, 0);
		
		// collego eventuali nodi adiacenti al nodo appena creato
      link_adjacent('e', p_new_node, origin);
	}

}


// Precondizione: exclude deve essere un char fra n,s,e,o; current puntatore al
// nodo di cui si vogliono collegare gli adiacenti, origin deve essere il nodo
// (0,0) iniziale, usato  per la ricerca nodi, 
// Exclude e` la direzione dal nuovo al vecchio nodo, dire che exclude e diverso
// da nord, vuol dire che il nuovo nodo non si trova a nord del vecchio
void Node::link_adjacent(char exclude, Node* current, Node& origin)
{
   Node* found;
   int xx = current->get_x();
   int yy = current->get_y();

	Map search_map(1,1);    // mappa di ricerca
	search_map.init(0);

   // Cerco nodo adiacente a nord
   if (exclude != 'n')
   {
      found = current->search_node(xx, yy+1, origin, search_map);
      search_map.delete_map(true);

      if (found != NULL)
      {
         // Collegamento nodi
         found->set_cardinal('s', *(current));
         current->set_cardinal('n', *(found));
      }
   }

   // Cerco nodo adiacente a sud
   if (exclude != 's')
   {
      found = current->search_node(xx, yy-1, origin, search_map);
      search_map.delete_map(true);

      if (found != NULL)
      {
         // Collegamento nodi
         found->set_cardinal('n', *(current));
         current->set_cardinal('s', *(found));
      }
   }

   // Cerco nodo adiacente a est
   if (exclude != 'e')
   {
      found = current->search_node(xx+1, yy, origin, search_map);
      search_map.delete_map(true);

      if (found != NULL)
      {
         // Collegamento nodi
         found->set_cardinal('o', *(current));
         current->set_cardinal('e', *(found));
      }
   }

   // Cerco nodo adiacente a ovest
   if (exclude != 'o')
   {
      found = current->search_node(xx-1, yy, origin, search_map);
      search_map.delete_map(true);

      if (found != NULL)
      {
         // Collegamento nodi
         found->set_cardinal('e', *(current));
         current->set_cardinal('o', *(found));
      }
   }
}

