#ifndef HUD_HPP
#define HUD_HPP

#include <cstring>
#include <cstddef>    // Usato per il tipo NULL dei puntatori
#include <iostream>
#include "ClassPlayer.hpp"


// Funzione che controlla se un carattere è presente in una stringa
// Postcondizione: resituisce true sse il char è nella stringa
bool c_in_str(std::string s, char c);

// Stampa ad ogni turno i valori di attacco, hp.. etc di un giocatore, e poi
// stampa le azioni disponibili, contenute nella stringa cmds
//
// Esempio: se il gioactore non puo andare a nord la stringa contiene "seo"
// che sta per sud-est-ovest
void hud_print(Player* &p, std::string cmds, int o); 

//Stampa i risultati del lancio del dado quando mi muovo
void hud_movement(int n);

//Stampa i risultati del lancio del dado quando esploro una stanza
void hud_action(int n);

//Stampa i risultati della battaglia
int hud_battle(std::string name1, std::string name2, int atk, int atk2, int n);

//Stampa se il giocatore muore di "morte naturale", a causa di trappole 
void hud_death(std::string name_p1, int n);

// Funzione che stampa titolo del gioco
void printTitle();

// Funzione che stampa grafica e narrazione di entrata nel labirinto
void printEntrance();

// Funzione che stampa grafica e narrazione di uscita dal labirinto
void printExit(); 
#endif
