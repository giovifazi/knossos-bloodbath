#ifndef _GAME
#define _GAME

#include <iostream>

// Funzione che chiede in input "y" o "n"
// in caso di errore si chiama ricorsivamente
bool battleChoice();

// Precondizione: cmd deve avere lunghezza 1, mentre allowed almeno 1
//
// Postcondizione: se cmd viene trovato nella stringa allowed allora ritorna
// true, false altrimenti
bool is_command(std::string cmd, std::string allowed);

// Precondizione: La funzione prende in input una stringa NON VUOTA! (altrimenti
// si rimane bloccati in un loop infinito) contenente tutti i possibili caratteri
// accettati come input, anche se sconsigliato funzione pure se la stringa 
// allowed contiene doppioni.
//
// Postcondizione: Ritorna il carattere valido dell input del giocatore
char get_player_input(std::string allowed);

#endif
