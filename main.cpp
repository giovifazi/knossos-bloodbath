#include <iostream>
#include <cstddef>          // Usato per il tipo NULL dei puntatori
#include <ctime>            // Usato per la funzione time che "randomizza il seed"
#include <cstddef>          // Usato per la funzione srand() e rand()
#include <cstdlib>

#include "Map.hpp"	    // Definisce il tipo mappa per la stampa
#include "Node.hpp"         // Definisce il tipo Nodo
#include "ClassPlayer.hpp"  // Definisce la classe player
#include "Menu.hpp"	    // Definisce le funzioni del Menu
#include "Game.hpp"         // Libreria di funzioni 	
#include "Hud.hpp"	


int main()
{
   	printTitle();

   	srand(time(0));        // Random seed per partite pseudocasuali

	Map map_game(1,1);     // Creo una mappa con w=1 e h=1 ma ancora vuota
	map_game.init(1);      // Inizializza la mappa con valore 1 nella posizione (0,0)
	Node node_orig(0,0);   // Creo il nodo iniziale

	//Controllo se i giocatori vogliono giocare
  	if (!loadMenu())
		return 0;		

	int NP = setPlayers();        	//imposto il numero di giocatori

	Player *players[NP];	      	   //creo n giocatori in array dinamico

	for (int i=0; i<NP; i++)      	//inizializzo tutti i giocatori
	{
		players[i] = new Player(setName(i+1),50,10,i+1);   // setName e` nel Menu.cpp
		players[i]->pos = &node_orig;                      // imposto la posizione di tutti giocatori nel nodo iniziale
	}

   // Stampa grafica e narrazione di entrata nel labirinto
   printEntrance();

   // Metto nella mappa grafica la somma dei numeri assegnati ai players
	map_game.changeValue(0,0, ((NP*(NP+1))/2) +1, NP);

	// Inizio vera e propria partita
	char cmd_player;		         // carattere di input del giocatore
	int alive_players = NP;		   // Numero di giocatori in vita
	std::string allwd_mov = "nseox";   // stringa con i caratteri validi per giocare

   int z;                  // in base al valore di z stampo un hud differente
   int death;              // controlla se un giocatore e' morto di "morte naturale" o se in seguito ad un combattimento
   bool mov_newn;          // controlla movimento verso un nodo esistente o appena creato
   bool ignore = false;    // controlla per stabilire se usare cin.ignore o meno 

	// Loop dei turni
	while (true)
	{
		// Scorre array giocatori per far eseguire i turni
		for (int j=0; j<NP; j++)
		{
			// Fa turni finche` non c e` un solo vincitore
			if (alive_players > 1)
			{
				//Fa fare il turno solo ai giocatori ancora in vita
				if (players[j] != NULL && players[j]->is_alive())
				{
	       death=0;		//reimposto la morte naturale, durante i turni precedenti potrebbe essere stata cambiata
               map_game.set_Turn(players[j]->pos->get_x(), players[j]->pos->get_y(),true); // Imposta nella mappa dove stampare le {} per il turno corrente
					map_game.draw(NP);				
					map_game.set_Turn(players[j]->pos->get_x(), players[j]->pos->get_y(),false);// Toglie nella mappa dove avviene il turno corrente

               if (map_game.getPresAt(players[j]->pos->get_x(), players[j]->pos->get_y())!= 1)
                  z=1;     // se nel nodo c'e' un solo player indico che x e` per cercare oggetti 
               else 
                  z=0;     // ..per combattere altrimenti


					hud_print(players[j], allwd_mov, z);			// Stampa comandi player
					cmd_player = get_player_input(allwd_mov);    // filtra input giocatore e lo ritorna in cmd_player, get_player_input e` in game.cpp
	
					if (cmd_player == 'x')  // Se esamino/combatto
               {	
                  ignore = true;    // stampa ignore per comodita gameplay
						
						//Se c`e' un solo giocatore nella stanza, esamina la stanza
						if (map_game.getPresAt(players[j]->pos->get_x(), players[j]->pos->get_y())== 1)
                     hud_action(players[j]->diceRoll_or());   // Lancia il dado per esaminare stanze visitate, diceRoll_or() mi restituisce un'intero per la stampa hud_action
						//Altrimenti decide se combattere
						else
						if (battleChoice()) {
								death=players[j]->engage_battle(&players[0],  map_game, NP, j, node_orig, alive_players);
                        ignore = true;
                  }
else { ignore = false;}
               }
					//Se l'input e' un azione di movimento (n s e o)
					else
               {
						//Muove il giocatore secondo l'input
						mov_newn = players[j]->Player_move(cmd_player, map_game, node_orig);
										
						//Controllo se ci sono altri giocatori nel nodo in cui mi sto muovendo
						if (map_game.getPresAt(players[j]->pos->get_x(), players[j]->pos->get_y()) > 1)
						{
							if (battleChoice()){    // battleChoice fa scegliere se combattere
								death=players[j]->engage_battle(&players[0],  map_game, NP, j, node_orig, alive_players );					
					         ignore = true;
					      } else { ignore = false; }
                  }

               }

                                        
					//Controllo eventuale morte del giocatore[j] alla fine del suo turno
					if (!players[j]->is_alive())
					{
                  hud_death(players[j]->getName(), death);  // Grafica della morte

						players[j]->remove_from_map(map_game);    // Rimuove il simbolo dalla mappa grafica
						players[j]->pos = NULL;                   // cancella il puntatore della pos ai nodi
						players[j] = NULL;                        // cancella il puntatore a giocatore
                  
                  alive_players--;                          // Segna un giocatore vivo in meno
					}
           
               // FINE TURNO stampo mappa per rispettare le specifiche del progetto

               if (players[j]==NULL)                            //caso in cui il giocatore sia morto durante il suo turno
               {
                  map_game.draw(NP);               
                  std::cout << "\n\nPremi invio per terminare il turno";
                  std::cin.get();
               }
               else 
               {
                  std::cout << "Fine del turno di " << players[j]->getName() << "\n\n";
                  map_game.draw(NP);
          

 
	  	// Evita di dover premere due volte invio a fine turno in certi casi
	  	if (!(mov_newn /*|| map_game.getPresAt(players[j]->pos->get_x(), players[j]->pos->get_y()) > 1*/))
                     if (!ignore)
			std::cin.ignore(); 
                  
                  std::cout << "\n\nPremi invio per terminare il turno ";
                  std::cin.get();
               }
               
               // reimposto queste variabili per cin.ignore
               ignore = false;
               mov_newn = false;
            }

            // Spazi per separare grafica
            for (int r=0; r < 40; r++)
               std::cout << "\n";

         }// if alive_players > 1
	
		   if (alive_players == 1)    // In caso di vittoria di un giocatore
         {			   
            // scorre l array di giocatori per trovare quello che ha vinto
            for (int j=0; j<NP; j++)
            {
               if (players[j] != NULL)
               {  
                  // Stampa mappa con ultimo sopravvissuto
                  map_game.draw(NP);
                 
                  // Stampa grafica e narrazione di uscita dal labirinto
				  printExit();

				  std::cout
                  << players[j]->getName() << " vince!\n"
                  << "Premi invio per chiudere il gioco";
                 
                  std::cin.get();
               }
            }
           
            // Cancella la mappa di gioco con garbage collection
            map_game.delete_map(true);
            return 0;
        
         }//if alive_players ==1
	   
	   }//for j=0.. np.. etc
  	
  	}//while true
 

   return 0;
}// main
