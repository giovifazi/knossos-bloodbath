#include "Game.hpp"

// Funzione per fare decidere a un giocatore se combattere o meno
bool battleChoice()
{
	std::string choice;

	std::cout<<"Vuoi combattere? [y/n]\n";
	std::cin>>choice;

	if (choice == "y") 
		return true;
	
	else if (choice == "n")
		return false;
	
	else
		return battleChoice();
}

// Precondizione: cmd deve avere lunghezza 1, mentre allowed almeno 1
//
// Postcondizione: se cmd viene trovato nella stringa allowed allora ritorna
// true, false altrimenti
bool is_command(std::string cmd, std::string allowed)
{
   int n = allowed.size();

   // Controllo grandezza sui valori validi
   if (n == 0)
      return false;
   
   // Controllo grandezza sull input
   if (cmd.size() != 1) return false;

   // Controllo validita caratteri input
   for (int i=0; i < n; i++)
      if (cmd[0] == allowed[i])
         return true;
   
   return false;  // eseguito qunado fallisce il controllo
}


// Precondizione: La funzione prende in input una stringa NON VUOTA! (altrimenti
// si rimane bloccati in un loop infinito) contenente tutti i possibili caratteri
// accettati come input, anche se sconsigliato funziona pure se la stringa 
// allowed contiene doppioni.
//
// Postcondizione: Ritorna il carattere valido dell input del giocatore
char get_player_input(std::string allowed)
{
   // Dichiarazione e inserimento della stringa di input
   std::string input;
   std::cin >> input;

   // finche l' input non è un comando valido notifica un errore
   while(!is_command(input, allowed))
   {
      std::cout << "Comando non valido, inserire solo un carattere valido!\n";
      std::cin >> input;
   }
   
   return input[0];  // ritorna il char del comando
}
