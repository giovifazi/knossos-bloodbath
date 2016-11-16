#ifndef CLASSPLAYER_HPP_
#define CLASSPLAYER_HPP_

#include <iostream>
#include <cstring>
#include <cstddef>
#include <ctime>
#include <cstdlib>

#include "Map.hpp"
#include "Node.hpp"

class Player{

protected:

   int hp;                // i punti vita del giocatore (impostati su 20)
   int atk;               // valore di attacco usati negli scontri (0)
   std::string name;      // nome del giocatore
   int numPlay;		     // numero identificativo giocatore

   std::string shield;	  // Scudo equipaggiato al giocatore

public:

   Node* pos; // puntatore a nodi per la posizione sulla mappa

   // Costruttore
   Player (std::string n, int life, int att, int np);

   // Metodi semplici di ritorno valori
	std::string getShield();
	std::string getName(); 
	int getAtk();
	int getHp();
	int getNumPlay();

   // Imposta punti vita al giocatore
	void set_hp(int l);

   // Controllo se hp < 0
	bool is_alive();	

   // Movimento su nodi, sia vecchi (ritorna false) che nuovi da creare (true)
   bool Player_move(char dir, Map& map, Node& curr_node);

   // Funzione che rimuove il valore del numPlay del giocatore sulla mappa
   // usata nel main, quando un giocatore muore e non deve piu apparire
   void remove_from_map(Map& map);
   
   // Funzione di battaglia, passare array giocatori, numero giocatori, indice
   // nell`array del giocatore attaccante, nodo origine, numero giocatori
   // correntemente vivi
   int engage_battle(Player* p[], Map& map, int np, int p1_index, Node& node, int& alive_players);	

   // Tira il dado per visitare stanze vecchie (or = old_room)
   int diceRoll_or();

   // Tira il dado per visitare stanze nuove (nr = new_room)
   int diceRoll_nr(); 	
};

#endif
