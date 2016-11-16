#include "Menu.hpp"



void stampaMenu(std::string x,std::string y,std::string z,std::string w, int n){
					
         int uno=31-x.size();			//variabili che contano il numero di spazi bianchi da stampare
         int due=31-y.size();
         int tre=31-z.size();
         int quattro=31-w.size();

switch(n){

case 0:
std::cout
        <<" _____                                                                        _____ \n"
	<<"(@___@)                                                                      (@___@)\n"
	<<" ║ ║ ║                                                                        ║ ║ ║ \n"
	<<" ║ ║ ║                                                                        ║ ║ ║ \n"
	<<" ║ ║ ║╔═══════════════════════════════════╦══════════════════════════════════╗║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                 ↑                ║║ ║ ║ \n"
	<<" ║ ║ ║║    "<<x<<std::string(uno,' ')<<"║                 w                ║║ ║ ║   \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║ ║ ║║    "<<y<<std::string(due,' ')<<"║            1-conferma            ║║ ║ ║   \n"
	<<" ║ ║ ║║    "<<z<<std::string(tre,' ')<<"║                                  ║║ ║ ║   \n"             
	<<" ║ ║ ║║    "<<w<<std::string(quattro,' ')<<"║                 s                ║║ ║ ║\n"
	<<" ║ ║ ║║                                   ║                 ↓                ║║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║_║_║╚═══════════════════════════════════╩══════════════════════════════════╝║_║_║ \n"
	<<"(_____)                                                                      (_____)\n";

        break;

case 1:

std::cout
        <<" _____                                                                        _____ \n"
	<<"(@___@)                                                                      (@___@)\n"
	<<" ║ ║ ║                                                                        ║ ║ ║ \n"
	<<" ║ ║ ║                                                                        ║ ║ ║ \n"
	<<" ║ ║ ║╔═══════════════════════════════════╦══════════════════════════════════╗║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║        Lo scopo del gioco e'     ║║ ║ ║ \n"
	<<" ║ ║ ║║    "<<x<<std::string(uno,' ')<<"║          rimanere l'unico        ║║ ║ ║   \n"
	<<" ║ ║ ║║                                   ║        giocatore sulla mappa.    ║║ ║ ║ \n"
	<<" ║ ║ ║║    "<<y<<std::string(due,' ')<<"║                                  ║║ ║ ║   \n"
	<<" ║ ║ ║║    "<<z<<std::string(tre,' ')<<"║          Per farlo dovrai        ║║ ║ ║   \n"             
	<<" ║ ║ ║║    "<<w<<std::string(quattro,' ')<<"║      sopravvivere ai pericoli    ║║ ║ ║\n"
	<<" ║ ║ ║║                                   ║           del labirinto.         ║║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║_║_║╚═══════════════════════════════════╩══════════════════════════════════╝║_║_║ \n"
	<<"(_____)                                                                      (_____)\n";

        break;

case 2:
std::cout
        <<" _____                                                                        _____ \n"
	<<"(@___@)                                                                      (@___@)\n"
	<<" ║ ║ ║                                                                        ║ ║ ║ \n"
	<<" ║ ║ ║                                                                        ║ ║ ║ \n"
	<<" ║ ║ ║╔═══════════════════════════════════╦══════════════════════════════════╗║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║ ║ ║║    "<<x<<std::string(uno,' ')<<"║      Sopravvivi al Minotauro,    ║║ ║ ║   \n"
	<<" ║ ║ ║║                                   ║           alle trappole          ║║ ║ ║ \n"
	<<" ║ ║ ║║    "<<y<<std::string(due,' ')<<"║           del labirinto,         ║║ ║ ║   \n"
	<<" ║ ║ ║║    "<<z<<std::string(tre,' ')<<"║         agli altri giocatori     ║║ ║ ║   \n"             
	<<" ║ ║ ║║    "<<w<<std::string(quattro,' ')<<"║     e conquisterai la liberta'!  ║║ ║ ║\n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║ ║ ║║                                   ║                                  ║║ ║ ║ \n"
	<<" ║_║_║╚═══════════════════════════════════╩══════════════════════════════════╝║_║_║ \n"
	<<"(_____)                                                                      (_____)\n";

        break;



}

} 


//Stampa il menu per la scelta fra Start e Quit
bool loadMenu()
{
	bool start = true;           // Cursore per selezionare start o quit
        char command;

stampaMenu("         <START>","","","          QUIT", 0);                               
	// Itera finche' non si seleziona qualcosa
	while (command != '1')
	{
	        std::cin>>command;
		
		// Cambia posizione cursore in base a command
		if (command == 'w')
		{	for (int i=0; i<40; i++, std::cout<<"\n");			//spazio fra una schermata e l'altra
			stampaMenu("         <START>","","","          QUIT", 0);
			start = true;
		}
		

		else if (command == 's')
		{
                        for (int i=0; i<40; i++, std::cout<<"\n");
			stampaMenu("          START","","","         <QUIT>", 0);
			start = false;
		}
        
        }
	return (start); 	
}

//Stampa il menu per la selezione del numero di giocatori	
int setPlayers()
{
	int  numberP = 0;
	while (numberP < 2)		//itero finche' il numero di giocatori e' <= a 2
	{
                for (int i=0; i<40; i++, std::cout<<"\n");				//spazio fra una schermata e l'altra
		stampaMenu("Quanti giocatori?","","[minimo 2 giocatori]","", 1);	//stampo il menu
		std::cin>> numberP;
               if(!std::cin){
                
                 std::cin.clear();
                 std::cin.ignore();
               }
	
	}
	
	return (numberP);
}

//Stampa il menu per il nome
std::string setName(int num) 	
{                                      
	std::string name;
	std::ostringstream convert;
	convert<<num;
	std::string stringa = "Giocatore "+convert.str(); 
        std::string stringa2 = "inserisci il tuo nome:";  
        for (int i=0; i<40; i++, std::cout<<"\n"); 			//spazio fra una schermata e l'altra        
	stampaMenu(stringa,"",stringa2,"[max 10 caratteri]", 2);	
	std::cin>> name;
	while (name.size() > lenght)					//controllo lunghezza nome
	{
                for (int i=0; i<40; i++, std::cout<<"\n");
		stampaMenu("Nome troppo lungo!","riprova con un nome piu corto","","",2);
		std::cin>>name;
	}
		return name;
} 

