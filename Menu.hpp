#ifndef FUNZIONIMENU_HPP_
#define FUNZIONIMENU_HPP_

#include <iostream>
#include <string>
#include <sstream>

#include "Node.hpp"
#include "ClassPlayer.hpp"

const int lenght=10;
const int c=56;

//Funzione che stampa il menu
void stampaMenu(std::string x,std::string y,std::string z,std::string w, int n);

// Funzione che stampa il menu con scelta fra Start e Quit
bool loadMenu();

// Menu che imposta il numero di giocatori
int setPlayers();

//Menu che imposta il nome del giocatore
std::string setName(int num);

#endif
