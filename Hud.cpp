#include <cstring>
#include <cstddef>    // Usato per il tipo NULL dei puntatori
#include <iostream>
#include "Hud.hpp"


// Funzione che controlla se un carattere è presente in una stringa
// Postcondizione: resituisce true sse il char è nella stringa
bool c_in_str(std::string s, char c)
{
   for (int i=0; i < s.size(); i++)
      if (s[i] == c)
         return true;

   return false;
}



// Stampa ad ogni turno i valori di attacco, hp etc di un giocatore
// e la lista delle azioni che puo' compiere
void hud_print(Player* &p, std::string cmds, int o)
{  
   std::string name = p->getName();
   std::string shield = p->getShield();
   int hp = p->getHp();
   int atk = p->getAtk();
	
   //spazi da stampare bianchi per il nome
   int blank=20-name.size();
	
   //spazi bianchi da stampare per il simbolo
   int blank_p;
   if (p->getNumPlay()>9&&p->getNumPlay()<100){blank_p=17;}
   else if (p->getNumPlay()<10){blank_p=18;}
   else {blank_p=16;}

   //spazi bianchi da stampare per la vita
   int blank_hp;
   if (hp>9&&hp<100){blank_hp=22;}
   else if (hp<10){blank_hp=23;}
   else {blank_hp=21;}

   //spazi bianchi da stampare per l'attacco
   int blank_atk;
   if (atk>9&&atk<100){blank_atk=22;}
   else if (atk<10){blank_atk=23;}
   else {blank_atk=21;}

   //spazi bianchi da stampare per lo scudo
   int blank_s=22-shield.size();


   
   switch (o){   
   //caso con x=cerca
   case 0:
   std::cout 
  
   << " _____                                _____      \n"
   << "(@___@) Turno di "<< name << std::string(blank,' ') <<"(@___@)\n"
   << " ║ ║ ║╔══════════════════════════════╗║ ║ ║\n" 
   << " ║ ║ ║║ Simbolo [" << p->getNumPlay() <<"]"<< std::string(blank_p,' ') <<"║║ ║ ║\n" 
   << " ║ ║ ║║ HP:  "<< hp << std::string(blank_hp,' ')<<"║║ ║ ║\n"
   << " ║ ║ ║║ ATK: " << atk << std::string(blank_atk,' ')<<"║║ ║ ║\n"
   << " ║ ║ ║║ SCUDO: " << shield << std::string(blank_s,' ') <<"║║ ║ ║\n"
   << " ║ ║ ║╚══════════════════════════════╝║ ║ ║\n"
   << " ║ ║ ║ Cosa vuoi fare?                ║ ║ ║ \n";
   std::cout 
   << " ║ ║ ║╔══════════════════════════════╗║ ║ ║" << std::endl;

   if (c_in_str(cmds, 'n'))
      std::cout << " ║ ║ ║║ Andare a nord----[premere n] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 's'))
      std::cout << " ║ ║ ║║ Andare a sud-----[premere s] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 'e'))
      std::cout << " ║ ║ ║║ Andare a est-----[premere e] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 'o'))  
      std::cout << " ║ ║ ║║ Andare a ovest---[premere o] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 'x'))
      std::cout << " ║ ║ ║║ Cercare oggetti--[premere x] ║║ ║ ║\n";
   
   std::cout << " ║_║_║╚══════════════════════════════╝║_║_║\n";
   std::cout << "(_____)                              (_____) \n";
   break;
   //caso con x=combatti
   case 1:

   std::cout 
  
   << " _____                                _____      \n"
   << "(@___@) Turno di "<< name << std::string(blank,' ') <<"(@___@)\n"
   << " ║ ║ ║╔══════════════════════════════╗║ ║ ║\n" 
   << " ║ ║ ║║ Simbolo [" << p->getNumPlay() <<"]"<< std::string(blank_p,' ') <<"║║ ║ ║\n" 
   << " ║ ║ ║║ HP:  "<< hp << std::string(blank_hp,' ')<<"║║ ║ ║\n"
   << " ║ ║ ║║ ATK: " << atk << std::string(blank_atk,' ')<<"║║ ║ ║\n"
   << " ║ ║ ║║ SCUDO: " << shield << std::string(blank_s,' ') <<"║║ ║ ║\n"
   << " ║ ║ ║╚══════════════════════════════╝║ ║ ║\n"
   << " ║ ║ ║ Cosa vuoi fare?                ║ ║ ║ \n";
   std::cout 
   << " ║ ║ ║╔══════════════════════════════╗║ ║ ║" << std::endl;

   if (c_in_str(cmds, 'n'))
      std::cout << " ║ ║ ║║ Andare a nord----[premere n] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 's'))
      std::cout << " ║ ║ ║║ Andare a sud-----[premere s] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 'e'))
      std::cout << " ║ ║ ║║ Andare a est-----[premere e] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 'o'))  
      std::cout << " ║ ║ ║║ Andare a ovest---[premere o] ║║ ║ ║\n";
   
   if (c_in_str(cmds, 'x'))
      std::cout << " ║ ║ ║║ Combattere-------[premere x] ║║ ║ ║\n";
   
   std::cout << " ║_║_║╚══════════════════════════════╝║_║_║\n";
   std::cout << "(_____)                              (_____) \n";

   break;

}




}



//Stampa i risultati del lancio del dado quando mi muovo
void hud_movement(int n){
   
   // Stampo righe vuote per separare schermate
   for(int j=0; j < 6; j++)
      std::cout << "\n"; 
   
   switch (n){
           
      case 1: case 2: case 3: case 4: case 5:
         
        if (n%2==0){  std::cout<<"Passeggi nell'oscurita', circondato dal silenzio...\n\n";}
        else {  std::cout<<"Passeggi nel buio, circondato dal silenzio...\n\n";}
      break;

      case 6: case 7: case 8: case 9:
         std::cout
         <<"Qualcosa splende sul pavimento impolverato del Labirinto: è una spada incagliata nella gabbia toracica di uno scheletro.\n" 
         <<"La sfili mentre le ossa si dissolvono in uno scricchiolio che rimbomba con eco. \n"
         <<"La spada è lucente e pare appartenuta ad un antico eroe...\n\n"
         <<"Hai trovato una spada di bronzo!\n"
         <<"+3 in attacco.\n"
         <<"\n"
<<"            _\n"
<<" _         | |\n"
<<"| |_ _ _ __| |------------------------------------------.._        \n"
<<"| |_|_|_|_|==[]=========================================  _>      \n"
<<"|_|        | |------------------------------------------''        \n"
<<"           |_|\n\n";


      break;
     
      case 10: case 11: case 12:
         std::cout
         <<"Qualcosa splende sul pavimento impolverato del Labirinto: è una spada incagliata nella gabbia toracica di uno scheletro.\n" 
         <<"La sfili mentre le ossa si dissolvono in uno scricchiolio che rimbomba con eco. \n"
         <<"La spada è lucente e pare appartenuta ad un antico eroe...\n\n"
         <<"Hai trovato una spada d'argento!\n"
         <<"+4 in attacco.\n"
         <<"\n"
<<"              />\n"
<<" ()          //----------------------------------------------------.._\n"
<<"(8)OXOXOXOXO(8>|---------------------------------------------------  _:> \n"
<<" ()          \\\\----------------------------------------------------''   \n"
<<"              \\>\n\n";
      break;
   
      case 13: case 14: 
         std::cout

        <<"Saranno le allucinazioni da stanchezza ma quello che ti appare davanti agli occhi non ti sembra vero. \n"
        <<"C'era una volta un gigante di nome Orione, portava con sé una grossa spada d'oro. \n"
        <<"Dava la caccia ad animali feroci con quella lama e la sua forza fece innamorare anche Diana, una dea.\n"
        <<"Quella che vedi, nascosta in un anfratto, pare una mirabile copia. La impugni con timore...\n\n"

         <<"Hai trovato una spada d'oro!\n"
         <<"+6 in attacco.\n"
         <<"\n"

<<"                ()\n"
<<"                ))\n"
<<"               / (\n"
<<"  _.-.-.-.-..-/| ((::::::::::::::::::::::::::::::::::::::::::::::.._          \n"
<<"()_( ( ( ( (  (|  ))    -====================================-     _.>     \n"
<<"   `-*-`-`-'`-\\| ((::::::::::::::::::::::::::::::::::::::::::::::''               \n"
<<"               \\ (\n"
<<"                ))\n"
<<"                ()\n\n";




      break;
   
      case 15: case 16: case 17: 
         std::cout

<<"        |\\\n"
<<"        | \\        /|\n"
<<"        |  \\____  / |\n"
<<"      /|__/AMMA\\/  |\n"
<<"     /AMMMMMMMMMMM\\_|\n"
<<" ___/AMMMMMMMMMMMMMMA\n"
<<" \\   |MVKMMM/ .\\MMMMM\\\n"
<<"  \\__/MMMMMM\\  /MMMMMM---\n"
<<"  |MMMMMMMMMMMMMMMMMM|  /\n"
<<"  |MMMM/. \\MM.--MMMMMM\\/\n"
<<"  /\\MMM\\  /MM\\  |MMMMMM   ___\n"
<<" /  |MMMMMMMMM\\ |MMMMMM--/   \\-.\n"
<<"/___/MMMMMMMMMM\\|M.--M/___/_|   \\\n"
<<"     \\VMM/\\MMMMMMM\\  |      /\\ \\/\n"
<<"      \\V/  \\MMMMMMM\\ |     /_  /\n"
<<"        |  /MMMV'   \\|    |/ _/\n"
<<"        | /              _/  /\n"
<<"        |/              /| \\'\n"
<<"                       /_  /\n"
<<"                       /  /\n\n"




         <<"Si dice che in quel Labirinto siano stati abbandonati altri prigionieri... E che siano impazziti.\n" 
         <<"Non puoi spiegare in altro modo quella trappola per animali feroci che ti ha appena colpito il polpaccio, facendoti sanguinare e urlare dal dolore...\n\n"
         <<"Hai attivato una trappola!\n-4 Hp.\n"
         <<"\n";
      break;

      // I casi 18 19 20 hanno tre sottocasi, identificati con 181 182 183
      case 181: 
         std::cout
<<"                                                          _( (~/ \\           \n"
<<"       _ _                        /                          ( \\> >\\       \n"
<<"   -/~/ / ~\\                     :;                \\       _  > /(~\\/    \n"
<<"  || | | /\\ ;\\                   |l      _____     |;     ( \\/    > >    \n"
<<"  _(()\\)\\)/ ;;;                  `8o __-~     ~\\   d|      \\      //    \n"
<<" ///(())(__/~;;\\                  *88p;.   * _\\*_;.oP        (_._/ /\n"
<<"(((__   __ **   \\                  `>,% (\\  (\\./)8*         ;:'  i\n"
<<")))--`.'-- (( ;,8 \\               ,;%%%:  ./V^^^V'          ;.   ;.\n"
<<"((\\   |   /)) .,88  `: ..,,;;;;,-::::::'_::\\   ||\\         ;[8:   ;\n"
<<" )|  ~-~  |(|(888; ..``'::::8888oooooo.  :\\`^^^/,,~--._    |88::  |\n"
<<" |\\ -===- /|  \\8;; ``:.      oo.8888888888:`((( o.ooo8888Oo;:;:'  |\n"
<<" |_~-___-~_|   `-\\.   `        `o`88888888b` )) 888b88888P""'     ;\n"
<<" ; ~~~~;~~         *`--_`.       b`888888888;(.,*888b888*  ..::;-'\n"
<<"   ;      ;              ~*-....  b`8888888:::::.`8888. .:;;;''\n"
<<"      ;    ;                 `:::. `:::OOO:::::::.`OO' ;;;''\n"
<<" :       ;                     `.      *``::::::''    .'\n"
<<"    ;                           `.   \\_              /\n"
<<"  ;       ;                       +:   ~~--  `:'  -';\n"
<<"                                   `:         : .::/  \n"
<<"      ;                            ;;+_  :::. :..;;;  \n"
<<"                                   ;;;;;;,;;;;;;;;,;\n"


         <<"Mentre cammini senti un ruggito provenire alle tue spalle. Non ti sembra reale quello che ti si erge di fronte:\n"
         <<"la figura di un mostro metà uomo e metà toro. Ti colpisce con forza, puoi a malapena ripararti. Quando riapri gli occhi non c'è più nessuno.\n" 
         <<"Ti vuole uccidere lentamente...\n\n"
         <<"Hai dovuto combattere contro il Minotauro!\n"
         <<"Grazie allo scudo d'oro riesci a difenderti senza subire danni, ma lo scudo si rompe...\n"

         <<"Da uno scheletro raccogli uno scudo in bronzo.\n";

      break;

      case 182: 
         std::cout
<<"                                                          _( (~/ \\           \n"
<<"       _ _                        /                          ( \\> >\\       \n"
<<"   -/~/ / ~\\                     :;                \\       _  > /(~\\/    \n"
<<"  || | | /\\ ;\\                   |l      _____     |;     ( \\/    > >    \n"
<<"  _(()\\)\\)/ ;;;                  `8o __-~     ~\\   d|      \\      //    \n"
<<" ///(())(__/~;;\\                  *88p;.   * _\\*_;.oP        (_._/ /\n"
<<"(((__   __ **   \\                  `>,% (\\  (\\./)8*         ;:'  i\n"
<<")))--`.'-- (( ;,8 \\               ,;%%%:  ./V^^^V'          ;.   ;.\n"
<<"((\\   |   /)) .,88  `: ..,,;;;;,-::::::'_::\\   ||\\         ;[8:   ;\n"
<<" )|  ~-~  |(|(888; ..``'::::8888oooooo.  :\\`^^^/,,~--._    |88::  |\n"
<<" |\\ -===- /|  \\8;; ``:.      oo.8888888888:`((( o.ooo8888Oo;:;:'  |\n"
<<" |_~-___-~_|   `-\\.   `        `o`88888888b` )) 888b88888P""'     ;\n"
<<" ; ~~~~;~~         *`--_`.       b`888888888;(.,*888b888*  ..::;-'\n"
<<"   ;      ;              ~*-....  b`8888888:::::.`8888. .:;;;''\n"
<<"      ;    ;                 `:::. `:::OOO:::::::.`OO' ;;;''\n"
<<" :       ;                     `.      *``::::::''    .'\n"
<<"    ;                           `.   \\_              /\n"
<<"  ;       ;                       +:   ~~--  `:'  -';\n"
<<"                                   `:         : .::/  \n"
<<"      ;                            ;;+_  :::. :..;;;  \n"
<<"                                   ;;;;;;,;;;;;;;;,;\n"


         <<"Mentre cammini senti un ruggito provenire alle tue spalle. Non ti sembra reale quello che ti si erge di fronte:\n"
         <<"la figura di un mostro metà uomo e metà toro. Ti colpisce con forza, puoi a malapena ripararti. Quando riapri gli occhi non c'è più nessuno.\n" 
         <<"Ti vuole uccidere lentamente...\n\n"
         <<"Hai dovuto combattere contro il Minotauro!\n"
         <<"Grazie allo scudo d'argento sei riuscito a ripararti dai suoi colpi mortali.\nMa non da tutti...\n-2 Hp.\n"
         <<"\n";
      break;
      
      case 183: 
         std::cout
<<"                                                          _( (~/ \\           \n"
<<"       _ _                        /                          ( \\> >\\       \n"
<<"   -/~/ / ~\\                     :;                \\       _  > /(~\\/    \n"
<<"  || | | /\\ ;\\                   |l      _____     |;     ( \\/    > >    \n"
<<"  _(()\\)\\)/ ;;;                  `8o __-~     ~\\   d|      \\      //    \n"
<<" ///(())(__/~;;\\                  *88p;.   * _\\*_;.oP        (_._/ /\n"
<<"(((__   __ **   \\                  `>,% (\\  (\\./)8*         ;:'  i\n"
<<")))--`.'-- (( ;,8 \\               ,;%%%:  ./V^^^V'          ;.   ;.\n"
<<"((\\   |   /)) .,88  `: ..,,;;;;,-::::::'_::\\   ||\\         ;[8:   ;\n"
<<" )|  ~-~  |(|(888; ..``'::::8888oooooo.  :\\`^^^/,,~--._    |88::  |\n"
<<" |\\ -===- /|  \\8;; ``:.      oo.8888888888:`((( o.ooo8888Oo;:;:'  |\n"
<<" |_~-___-~_|   `-\\.   `        `o`88888888b` )) 888b88888P""'     ;\n"
<<" ; ~~~~;~~         *`--_`.       b`888888888;(.,*888b888*  ..::;-'\n"
<<"   ;      ;              ~*-....  b`8888888:::::.`8888. .:;;;''\n"
<<"      ;    ;                 `:::. `:::OOO:::::::.`OO' ;;;''\n"
<<" :       ;                     `.      *``::::::''    .'\n"
<<"    ;                           `.   \\_              /\n"
<<"  ;       ;                       +:   ~~--  `:'  -';\n"
<<"                                   `:         : .::/  \n"
<<"      ;                            ;;+_  :::. :..;;;  \n"
<<"                                   ;;;;;;,;;;;;;;;,;\n"


         <<"Mentre cammini senti un ruggito provenire alle tue spalle. Non ti sembra reale quello che ti si erge di fronte:\n"
         <<"la figura di un mostro metà uomo e metà toro. Ti colpisce con forza, puoi a malapena ripararti. Quando riapri gli occhi non c'è più nessuno.\n" 
         <<"Ti vuole uccidere lentamente...\n\n"
         <<"Hai dovuto combattere contro il Minotauro!\n"
         <<"Grazie allo scudo di bronzo sei riuscito a difenderti da qualche suo colpo, ma lo scudo si e' rotto!\n"
	 <<"-4 Hp."
         <<"\n";
      break;

      case 184:
         std::cout
                                                                   
<<"                                                          _( (~/ \\           \n"
<<"       _ _                        /                          ( \\> >\\       \n"
<<"   -/~/ / ~\\                     :;                \\       _  > /(~\\/    \n"
<<"  || | | /\\ ;\\                   |l      _____     |;     ( \\/    > >    \n"
<<"  _(()\\)\\)/ ;;;                  `8o __-~     ~\\   d|      \\      //    \n"
<<" ///(())(__/~;;\\                  *88p;.   * _\\*_;.oP        (_._/ /\n"
<<"(((__   __ **   \\                  `>,% (\\  (\\./)8*         ;:'  i\n"
<<")))--`.'-- (( ;,8 \\               ,;%%%:  ./V^^^V'          ;.   ;.\n"
<<"((\\   |   /)) .,88  `: ..,,;;;;,-::::::'_::\\   ||\\         ;[8:   ;\n"
<<" )|  ~-~  |(|(888; ..``'::::8888oooooo.  :\\`^^^/,,~--._    |88::  |\n"
<<" |\\ -===- /|  \\8;; ``:.      oo.8888888888:`((( o.ooo8888Oo;:;:'  |\n"
<<" |_~-___-~_|   `-\\.   `        `o`88888888b` )) 888b88888P""'     ;\n"
<<" ; ~~~~;~~         *`--_`.       b`888888888;(.,*888b888*  ..::;-'\n"
<<"   ;      ;              ~*-....  b`8888888:::::.`8888. .:;;;''\n"
<<"      ;    ;                 `:::. `:::OOO:::::::.`OO' ;;;''\n"
<<" :       ;                     `.      *``::::::''    .'\n"
<<"    ;                           `.   \\_              /\n"
<<"  ;       ;                       +:   ~~--  `:'  -';\n"
<<"                                   `:         : .::/  \n"
<<"      ;                            ;;+_  :::. :..;;;  \n"
<<"                                   ;;;;;;,;;;;;;;;,;\n"


         <<"Mentre cammini senti un ruggito provenire alle tue spalle. Non ti sembra reale quello che ti si erge di fronte:\n"
         <<"la figura di un mostro metà uomo e metà toro. Ti colpisce con forza, puoi a malapena ripararti. Quando riapri gli occhi non c'è più nessuno.\n" 
         <<"Ti vuole uccidere lentamente...\n\n"
         <<"Hai dovuto combattere contro il Minotauro!\n"
         <<"Senza scudo è difficile combattere!\n-7 Hp.\n"
         <<"\n";
      break;

      case 211:
         std::cout 
         <<"Trovi una stanza. Pare fosse una sorta di cucina. Bicchieri e cianfrusaglie su di un lungo tavolo.\n"
         <<"C'è un anche un'anfora ben chiusa. La apri... nasconde del vino conservato meravigliosamente. Lo bevi e ti senti rinvigorito...\n\n"
         << "Trovata pozione magica!\n+4 Hp.\n\n"
            
    <<"    ___\n"
    <<"   (___)\n"
    <<"   <   >\n"
    <<"    ) (\n"
    <<"   /`-.\\\n"
    <<"  /     \\\n"
    <<" / _    _\\\n"
    <<":,' `-.' `:\n"
    <<"|         |\n"
    <<":         ;\n"
    <<" \\       /\n"
    <<"  `.___.' \n\n";

        
      break;

      case 231:
         std::cout 
         <<"Sei assetato e quell'ampolla contiene, pare, ottimo vino. In realtà è sangue infetto. Riesci a vomitarlo, ma sei avvelenato...\n\n"
         << "Hai bevuto del sangue infetto... \n-4 Hp.\n"
         <<"\n"
            
    <<"    ___\n"
    <<"   (___)\n"
    <<"   <   >\n"
    <<"    ) (\n"
    <<"   /`-.\\\n"
    <<"  /     \\\n"
    <<" / _    _\\\n"
    <<":,' `-.' `:\n"
    <<"|         |\n"
    <<":         ;\n"
    <<" \\       /\n"
    <<"  `.___.' \n\n";
      break;

   }

   std::cout << "Premi invio per continuare";
   std::cin.ignore();
   std::cin.get();

   // Stampo righe vuote per separare schermate
   for(int j=0; j < 40; j++)
      std::cout << "\n"; 
}
   


//Stampa i risultati del lancio del dado quando esploro una stanza
void hud_action(int n){

   // Stampo righe vuote per separare schermate
   for(int j=0; j < 6; j++)
      std::cout << "\n"; 

   switch(n){
      case 1: case 2: case 3: case 4: case 5:
         std::cout 

         <<"Hai deciso di interrompere la tua fuga per entrare in una stanza malamente illuminata. \n"
         <<"Speri di trovare un baule, del cibo o dell'acqua. Ti accontenteresti di poco... ma non trovi nulla...\n"
         <<"\n";			
      break;

      case 6:
         std::cout 
         <<"In un baule trovi uno scudo. Su di esso vi è raffigurato lo scontro tra Ercole e Cicno. Ti senti più forte...\n\n"
         <<"Hai trovato uno scudo d'oro!\nUtile nei combattimenti.\n"
         <<"\n"
          <<"|`-._/\\_.-`|\n"
          <<"|    ||    |\n"
          <<"|___o()o___|\n"
          <<"|__((<>))__|\n"
          <<"\\   o\\/o   /\n"
          <<" \\   ||   /\n"
          <<"  \\  ||  /\n"
          <<"   '.||.'\n"
          <<"     ``\n";
			
      break;

      case 71:
         std::cout 
         <<"Trovi una stanza. Pare fosse una sorta di cucina. Bicchieri e cianfrusaglie su di un lungo tavolo.\n"
         <<"C'è un anche un'anfora ben chiusa. La apri... nasconde del vino conservato meravigliosamente. Lo bevi e ti senti rinvigorito...\n\n"
         <<"+8 Hp.\n"
         <<"\n"
            
    <<"    ___\n"
    <<"   (___)\n"
    <<"   <   >\n"
    <<"    ) (\n"
    <<"   /`-.\\\n"
    <<"  /     \\\n"
    <<" / _    _\\\n"
    <<":,' `-.' `:\n"
    <<"|         |\n"
    <<":         ;\n"
    <<" \\       /\n"
    <<"  `.___.' \n\n";		
      break;

      case 72:
          std::cout 
         <<"Sei assetato e quell'ampolla contiene, pare, ottimo vino. In realtà è sangue infetto. Riesci a vomitarlo, ma sei avvelenato...\n\n"
         << "Hai bevuto del sangue infetto... \n-8 Hp.\n"
         <<"\n"
            
    <<"    ___\n"
    <<"   (___)\n"
    <<"   <   >\n"
    <<"    ) (\n"
    <<"   /`-.\\\n"
    <<"  /     \\\n"
    <<" / _    _\\\n"
    <<":,' `-.' `:\n"
    <<"|         |\n"
    <<":         ;\n"
    <<" \\       /\n"
    <<"  `.___.' \n\n";
      break;

      case 91:
         std::cout 
         <<"In un baule trovi uno scudo. Su di esso vi è raffigurato lo scontro tra Ercole e Cicno. Ti senti più forte.\n\n"
         <<"Hai trovato uno scudo di bronzo!\nUtile nei combattimenti.\n"
         <<"\n"
          <<"|`-._/\\_.-`|\n"
          <<"|    ||    |\n"
          <<"|___o()o___|\n"
          <<"|__((<>))__|\n"
          <<"\\   o\\/o   /\n"
          <<" \\   ||   /\n"
          <<"  \\  ||  /\n"
          <<"   '.||.'\n"
          <<"     ``\n";
			
      break;

      case 92:
         std::cout 
<<"Esistono verso il nord Europa, barbari esperti nell'uso di piccole spade chiamate daghe. \n"
<<"Non sai come sia possibile, ma ne hai trovata una nel labirinto. Simboli celtici adornano una lama consumata...\n\n"

         << "Trovata una daga!\n+1 in attacco.\n"
         <<"\n"		


               
<<"              (@|\n"
<<" ,,           ,)|____________________________________\n"
<<"//\\8@8@8@8@8@8 / _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \\\n"
<<"\\//8@8@8@8@8@8 \\_____________________________________/\n"
<<" ``           `)|\n"
<<"              (@|\n\n";
                
      break;

      case 13: case 14: case 15: case 16: case 17: 
         std::cout 

<<"           __\n"
<<"        ,. |_'.\n"
<<"       / / /:\\ \\\n"
<<"     _/_/_/::: |\n"
<<"    /o_'/o>::/ /\n"
<<"    / /'/:::/ /\n"
<<"   / /_/::.'_/\n"
<<"  / / \\__.-'   \n"           
<<" / /          \n"            
<<"/ /          \n"              
<<" /\n\n"

<<"Stai percorrendo il tunnel con passo costante e monotono e sei cosi' stanco da non dare piu' attenzione a quello che ti circonda.\n"
<<"Non ti accorgi dal sistema di trappole ad ascia che si attiva nel momento in cui premi la mattonella. \n"
<<"Riesci, con un riflesso animale, a schivare la lama, ma solo in parte: una lunga ferita ti attraversa il petto...\n\n"
         <<"Hai attivato una trappola!\n-4 Hp.\n"
         <<"\n";			
      break;

      case 18: case 19: 
         std::cout
         <<"Qualcosa splende sul pavimento impolverato del Labirinto: è una spada incagliata nella gabbia toracica di uno scheletro.\n" 
         <<"La sfili mentre le ossa si dissolvono in uno scricchiolio che rimbomba con eco. \n"
         <<"La spada è lucente e pare appartenuta ad un antico eroe...\n\n"
         <<"Hai trovato una spada d'argento!\n"
         <<"+4 in attacco.\n"
         <<"\n"
<<"              />\n"
<<" ()          //----------------------------------------------------.._\n"
<<"(8)OXOXOXOXO(8>|---------------------------------------------------  _:> \n"
<<" ()          \\\\----------------------------------------------------''   \n"
<<"              \\>\n\n";			
      break;

      case 20:
         std::cout 
        <<"Saranno le allucinazioni da stanchezza ma quello che ti appare davanti agli occhi non ti sembra vero. \n"
        <<"C'era una volta un gigante di nome Orione, portava con sé una grossa spada. \n"
        <<"Dava la caccia ad animali feroci con quella lama e la sua forza fece innamorare anche Diana, una dea.\n"
        <<"Quella che vedi, nascosta in un anfratto, pare una mirabile copia. La impugni con timore...\n\n"
		 <<"Hai trovato una spada magica!\n"
         <<"+5 Hp e +5 in attacco.\n"
         <<"\n"
<<"               \n"
<<"               /)     \n"          
<<"              //          \n"    
<<" _   .-------| |--------------------------------------.__\n"
<<"(_)88|WMWMWMW| |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:>\n"
<<"     `-------| |--------------------------------------'^^\n"
<<"              \\\\               \n"
<<"               \\)        \n"
<<"                       \n\n";
      break;
   }
   
   

   std::cout << "Premi invio per continuare ";
  
   std::cin.ignore();
   std::cin.get();

   // Stampo righe vuote per separare schermate
   for(int j=0; j < 40; j++)
      std::cout << "\n"; 
}

//Stampa i risultati della battaglia
int hud_battle(std::string name1, std::string name2, int atk, int atk2,int n){
	
	
std::cout

<<"Te lo sei ritrovato proprio di fronte. E' il tuo compagno di viaggio.\n" 
<<"Un prigioniero come te, un disperato, un affamato. Sareste dovuti essere compagni, e invece vi afferrate e vi colpite come animali selvaggi...\n\n" 



<<"                           __.--|~|--.__                             ,,;/;\n"
<<"                         /~     | |    ;~\\                         ,;;;/;;'\n"
<<"                        /|      | |    ;~\\                       ,;;;;/;;;'\n"
<<"                       |/|      \\_/   ;;;|\\                    ,;;;;/;;;;'\n"
<<"                       |/ \\          ;;;/  )                 ,;;;;/;;;;;'\n"
<<"                   ___ | ______     ;_____ |___....__      ,;;;;/;;;;;'\n"
<<"             ___.-~ \\(| \\  \\*\\ \\__/ /*/ /:|)~   ~   \\    ,;;;;/;;;;;'\n"
<<"         /~~~    ~\\    |  ~-.     |   .-~: |//  _.-~~--,;;;;/;;;;;'\n"
<<"        (.-~___     \\.'|    | /-.__.-\\|::::| //~     ,;;;;/;;;;;'\n"
<<"        /      ~~--._ \\|   /          `\\:: |/      ,;;;;/;;;;;'\n"
<<"     .-|             ~~|   |  /V****V\\ |:  |     ,;;;;/;;;;;' \\\n"
<<"    /                   \\  |  ~`^~~^'~ |  /    ,;;;;/;;;;;'    ;\n"
<<"   (        \\             \\|`\\._____./'|/    ,;;;;/;;;;;'      '\\\n"
<<"  / \\        \\                             ,;;;;/;;;;;'     /    |\n"
<<" |            |                          ,;;;;/;;;;;'      |     |\n"
<<"|`-._          |                       ,;;;;/;;;;;'              \\\n"
<<"|             /                      ,;;;;/;;;;;'  \\              \\__________\n"
<<"(             )                 |  ,;;;;/;;;;;'      |        _.--~          \n"
<<" \\          \\/ \\              ,  ;;;;;/;;;;;'       /(     .-~_..--~~~~~~~~~~\n"
<<" \\__         '  `       ,     ,;;;;;/;;;;;'    .   /  \\   / /~                \n"
<<" /          \'  |`._______ ,;;;;;;/;;;;;;'    /   :    \\/'/'       /|_/|   ``|\n"
<<"| _.-~~~~-._ |   \\ __   .,;;;;;;/;;;;;;' ~~~~'   .'    | |       /~ (/\\/    ||\n"
<<"/~ _.-~~~-._\\    /~/   ;;;;;;;/;;;;;;;'          |    | |       / ~/_-'|-   /|\n"
<<"(/~         \\| /' |   ;;;;;;/;;;;;;;;            ;   | |       (.-~;  /-   / |\n\n"



   << name1 << " colpisce e fa " << atk << " danni.\n"
   << name2 << " colpisce e fa " << atk2 << " danni.\n\n";



switch(n){   

        case -1:
                std::cin.ignore();

                std::cout << "Premi invio per continuare\n";

                 std::cin.get();
        break;


        case 0:

std::cout
<<"                     :::!~!!!!!:.\n"
<<"                  .xUHWH!! !!?M88WHX:.\n"
<<"                .X*#M@$!!  !X!M$$$$$$WWx:.\n"
<<"               :!!!!!!?H! :!$!$$$$$$$$$$8X:\n"
<<"              !!~  ~:~!! :~!$!#$$$$$$$$$$8X:\n"
<<"             :!~::!H!<   ~.U$X!?R$$$$$$$$MM!\n"
<<"             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM!\n"
<<"               !:~~~ .:!M'T#$$$$WX??#MRRMMM!\n"
<<"               ~?88888*`   `'*$$$$8!!!!|?!!!         Nel combattimento \n"
<<"             :X- M$$$$       `'T#$T~!8$WUXU~         muore "<<name1<<"\n"
<<"            :%`  ~#$$$m:        ~!~ ?$$$$$$\n"
<<"          :!`.-   ~T$$$$8xx.  .xWW- ~''##*'\n"
<<".....   -~~:<` !    ~?T#$$@@W@*?$$      /`\n"
<<"W$@@M!!! .!~~ !!     .:XUW$W!~ `*~:    :\n"
<<"#*~~`.:x%`!!  !H:   !WM$$$$Ti.: .!WUn+!`\n"
<<":::~:!!`:X~ .: ?H.!u *$$$B$$$!W:U!T$$M~\n"
<<".~~   :X@!.-~   ?@WTWo('*$$$W$TH$! `\n"
<<"Wi.~!X$?!-~    : ?$$$B$Wu('**$RM!\n"
<<"$R@i.~~ !     :   ~$$$$$B$$en:``\n"
<<"?MXT@Wx.~    :     ~'##*$$$$M~\n\n\n";

                 std::cin.ignore();

                std::cout << "Premi invio per continuare\n";

                 std::cin.get();

                return 1;


   
        
        case 1:
      std::cout 

        <<"Vi siete colpiti entrambi con tutta la forza possibile. Dovreste morire, ma il vostro combattimento ha stupito la dea Tiche,\n" 
        <<"signora della fortuna. Decide di intervenire e far vivere uno dei due...\n\n"


<<"       .-------.    ______\n"
<<"      /   o   /|   /\\     \\\n"
<<"     /_______/o|  /o \\  o  \\\n"
<<"     | o     | | /   o\\_____\\\n"
<<"     |   o   |o/ \\o   /o    /\n"
<<"     |     o |/   \\ o/  o  /\n"
<<"     '-------'     \\/____o/\n\n";

        std::cin.ignore();

        std::cout << "Premi invio per continuare\n";

        std::cin.get();

        std::cout 
        << "Regala 1 Hp a " << name1<<"\n\n"
        << name2 << " e' morto.\n\n";
      //  std::cin.ignore();

        std::cout << "Premi invio per continuare";

        std::cin.get();


                return 0;
        
        case 2:
        std::cout
        <<"Vi siete colpiti entrambi con tutta la forza possibile. Dovreste morire, ma il vostro combattimento ha stupito la dea Tiche,\n" 
        <<"signora della fortuna. Decide di intervenire e far vivere uno dei due...\n\n" 


<<"       .-------.    ______\n"
<<"      /   o   /|   /\\     \\\n"
<<"     /_______/o|  /o \\  o  \\\n"
<<"     | o     | | /   o\\_____\\\n"
<<"     |   o   |o/ \\o   /o    /\n"
<<"     |     o |/   \\ o/  o  /\n"
<<"     '-------'     \\/____o/\n\n";

        std::cin.ignore();

        std::cout << "Premi invio per continuare\n";

        std::cin.get();

        std::cout

        << "Regala 1 Hp a " << name2<<"\n\n" 
        << name1 << " e' morto.\n\n";

        std::cout << "Premi invio per continuare";

        std::cin.get();



                return 1;

        case 3:


std::cout
<<"                     :::!~!!!!!:.\n"
<<"                  .xUHWH!! !!?M88WHX:.\n"
<<"                .X*#M@$!!  !X!M$$$$$$WWx:.\n"
<<"               :!!!!!!?H! :!$!$$$$$$$$$$8X:\n"
<<"              !!~  ~:~!! :~!$!#$$$$$$$$$$8X:\n"
<<"             :!~::!H!<   ~.U$X!?R$$$$$$$$MM!\n"
<<"             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM!\n"
<<"               !:~~~ .:!M'T#$$$$WX??#MRRMMM!\n"
<<"               ~?789iW*`   `'#$$$$8!!!!8?!!!         Nel combattimento \n"
<<"             :X- M$$$$       `'T#$T~!8$WUXU~         muore "<<name2<<"\n"
<<"            :%`  ~#$$$m:        ~!~ ?$$$$$$\n"
<<"          :!`.-   ~T$$$$8xx.  .xWW- ~''##*'\n"
<<".....   -~~:<` !    ~?T#$$@@W@*?$$      /`\n"
<<"W$@@M!!! .!~~ !!     .:XUW$W!~ `*~:    :\n"
<<"#*~~`.:x%`!!  !H:   !WM$$$$Ti.: .!WUn+!`\n"
<<":::~:!!`:X~ .: ?H.!u *$$$B$$$!W:U!T$$M~\n"
<<".~~   :X@!.-~   ?@WTWo('*$$$W$TH$! `\n"
<<"Wi.~!X$?!-~    : ?$$$B$Wu('**$RM!\n"
<<"$R@i.~~ !     :   ~$$$$$B$$en:``\n"
<<"?MXT@Wx.~    :     ~'##*$$$$M~\n\n\n";


                  std::cin.ignore();

                   std::cout << "Premi invio per continuare\n";
        
                  std::cin.get();

                return 0;
        }

return 0;
  
}








//stampa per le morti "naturali", a causa di trappole
void hud_death(std::string name, int n){

if (n==0){

std::cout

<<"               ...\n"
<<"             ;::::;\n"
<<"           ;::::; :;\n"
<<"         ;:::::'   :;\n"
<<"        ;:::::;     ;.\n"
<<"       ,:::::'       ;           OOO\\\n"
<<"       ::::::;       ;          OOOOO\\\n"
<<"       ;:::::;       ;         OOOOOOOO\n"
<<"      ,;::::::;     ;'         / OOOOOOO\n"
<<"    ;:::::::::`. ,,,;.        /  / DOOOOOO\n"
<<"  .';:::::::::::::::::;,     /  /     DOOOO\n"
<<" ,::::::;::::::;;;;::::;,   /  /        DOOO\n"
<<";`::::::`'::::::;;;::::: ,#/  /          DOOO\n"
<<":`:::::::`;::::::;;::: ;::#  /            DOOO\n"
<<"::`:::::::`;:::::::: ;::::# /              DOO\n"
<<"`:`:::::::`;:::::: ;::::::#/               DOO\n"
<<" :::`:::::::`;; ;:::::::::##                OO\n"
<<" ::::`:::::::`;::::::::;:::#                OO\n"
<<" `:::::`::::::::::::;'`:;::#                O\n"
<<"  `:::::`::::::::;' /  / `:#\n"
<<"   ::::::`:::::;'  /  /   `#\n\n"


<<"Non sei un dio, e nemmeno uno di quegli eroi dei quali Atene e' ricoperta di statue.\n"
<<"Le ferite sono troppe, le trappole ti hanno fatto perdere sangue, hai camminato troppo e ti manca il fiato. \n"
<<"Gli altri prigionieri ti hanno sfiancato. Il Minotauro si erge sul tuo corpo ormai esanime...\n\n"
<<name<<" e' morto.\n\n";

   std::cout << "Premi invio per continuare\n";

   std::cin.get();
}

}

// Stampa titolo del gioco
void printTitle()
{
   std::cout<<std::endl;
   std::cout<<"          ██ ▄█▀ ███▄    █  ▒█████    ██████   ██████  ▒█████    ██████ "<<std::endl;
   std::cout<<"          ██▄█▒  ██ ▀█   █ ▒██▒  ██▒▒██    ▒ ▒██    ▒ ▒██▒  ██▒▒██    ▒ "<<std::endl;
   std::cout<<"          ▓███▄░ ▓██  ▀█ ██▒▒██░  ██▒░ ▓██▄   ░ ▓██▄   ▒██░  ██▒░ ▓██▄   "<<std::endl;
   std::cout<<"          ▓██ █▄ ▓██▒  ▐▌██▒▒██   ██░  ▒   ██▒  ▒   ██▒▒██   ██░  ▒   ██▒"<<std::endl;
   std::cout<<"          ▒██▒ █▄▒██░   ▓██░░ ████▓▒░▒██████▒▒▒██████▒▒░ ████▓▒░▒██████▒▒"<<std::endl;
   std::cout<<"          ▒ ▒▒ ▓▒░ ▒░   ▒ ▒ ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░"<<std::endl;
   std::cout<<"          ░ ░▒ ▒░░ ░░   ░ ▒░  ░ ▒ ▒░ ░ ░▒  ░ ░░ ░▒  ░ ░  ░ ▒ ▒░ ░ ░▒  ░ ░"<<std::endl;
   std::cout<<"          ░ ░░ ░    ░   ░ ░ ░ ░ ░ ▒  ░  ░  ░  ░  ░  ░  ░ ░ ░ ▒  ░  ░  ░  "<<std::endl;
   std::cout<<"          ░  ░            ░     ░ ░        ░        ░      ░ ░       "<<std::endl; 
   std::cout<<"          ░                                                        "<<std::endl;
}

// Stampa grafica e narrazione di entrata
void printEntrance()
{
	 // Intro
   std::cout
	<<  "\n\nNon avreste dovuto sfidare la parola degli Arconti. Questo è quello che vi siete meritati:\n" 
    <<  "un viaggio da prigionieri in una vecchia e puzzolente galea che dalla decadente Atene vi ha portato sull'Isola di Creta.\n"
    <<  "Le guardie vi hanno slegato all'entrata di quello che sembra un antichissimo labirinto: colonne rosse segnano l'entrata.\n"
    <<  "Si dice che sia stato costruito da una civiltà secoli prima, una civiltà che aveva combattuto barbari e mostri.\n"
    <<  "\n\n\n";
			
   std::cout
   <<"88888888888888888888888888888888888888888888888888888888888888888888888\n"
   <<"88.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..88\n"
   <<"88   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  88\n"
   <<"88      | `-!._  |  `;!  ;. _______________ ,'| .-' |   _!.i'     |  88\n"
   <<"88..__  |     |`-!._ | `.| |_______________||.*'|  _!.;'   |     _|..88\n"
   <<"88   |``*..__ |    |`*;.| i|_|\\         /|_|'| _!-|   |   _|..-|'    88\n"
   <<"88   |      |``--..|_ | `;!|b| \\       / |b|.'j   |_..!-'|     |     88\n"
   <<"88   |      |    |   |`-,!_|_|  \\ ___ /  |_||.!-;'  |    |     |     88\n"
   <<"88___|______|____!.,.!,.!,!|l|   |   |   |a|,!,.!.,.!..__|_____|_____88\n"
   <<"88      |     |    |  |  | |_|   |   |   |_|| |   |   |    |      |  88\n"
   <<"88      |     |    |..!-;'i|o|   |   |   |t| |`-..|   |    |      |  88\n"
   <<"88      |    _!.-j'  | _!,*|_|   |   |   |_||!._|  `i-!.._ |      |  88\n"
   <<"88     _!.-'|    | _.*|  !;|o|   |___|   |h|`.| `-._|    |``-.._  |  88\n"
   <<"88..-i'     |  _.''|  !-| !|_|  /     \\  |_|.|`-. | ``._ |     |``*..88\n"
   <<"88   |      |.|    |.|  !| |d| /       \\ |!||`. |`!   | `*.    |     88\n"
   <<"88   |  _.-'  |  .'  |.' |/|_|/         \\|_|! |`!  `,.|    |-._|     88\n"
   <<"88  _!*'|     !.'|  .'| .'|[@]___________[@] \\|  `. | `._  |   `-._  88\n"
   <<"88-'    |   .'   |.|  |/| /                 \\|`.  |`!    |.|      |`-88\n"
   <<"88      |_.'|   .' | .' |/                   \\  \\ |  `.  | `._-  |   88\n"
   <<"88     .'   | .'   |/|  /                     \\ |`!   |`.|    `.  |  88\n"
   <<"88  _.'     !'|   .' | /                       \\|  `  |  `.    |`.|  88\n"
   <<"88888888888888888888888888888888888888888888888888888888888888888888888\n";
}

// Stampa grafica e narrazione di uscita
void printExit()
{	
  std::cout			
  << "\n\n"
  <<"Hai la pelle bianca come i morti dell'Ade, gli occhi bruciano, e bruciano di piacere: il sole è forte sulle colline di Creta.\n"
  <<"Sei riuscito a scappare dal labirinto. Ora dovrai trovare un modo per tornare sulla penisola Greca... o fuggirai verso Est, verso l'Asia Minore.\n"
  <<"Ma questa, mio caro amico, è un'altra storia.\n\n"


  <<"           .          .           .     .          .             .\n"
  <<"  .      .      *           .       .          .      \\_/                .\n"
  <<"                 .       .   . *            *       --(_)--                     \n"
  <<"  .       ____     .      . .            .            / \\                .*\n"
  <<"         /WW>>\\         .        .               .                              \n"
  <<" .   .  /WWWI; \\  .       .    .  ____               .         .     .        \n" 
  <<"  *    /WWWWII; \\=====;    .     /WI; \\   *    .        /\\_             .\n"
  <<"  .   /WWWWWII;..      \\_  . ___/WI;:. \\     .        _/M; \\    .   .         .\n"
  <<"     /WWWWWIIIIi;..      \\__/WWWIIII:.. \\____ .   .  /MMI:  \\   * .\n"
  <<" . _/WWWWWIIIi;;;:...:   ;\\WWWWWWIIIII;.     \\     /MMWII;   \\    .  .     .\n"
  <<"  /WWWWWIWIiii;;;.:.. :   ;\\WWWWWIII;;;::     \\___/MMWIIII;   \\              .\n"
  <<" /WWWWWIIIIiii;;::.... :   ;|WWWWWWII;;::.:      :;IMWIIIII;:   \\___     *\n"
  <<"/WWWWWWWWWIIIIIWIIii;;::;..;\\WWWWWWIII;;;:::...    ;IMIII;;     ::  \\     .\n"
  <<"<<*WWWWWWWWWIIIIIIIIIii;;::.;..;\\WWWWWWWWIIIII;;..  :;IMIII;:::     :    \\   \n"
  <<"WWWWWWWWWWWWWIIIIIIii;;::..;..;\\WWWWWWWWIIII;::; :::::::::.....::       \\\n"
  <<"888888888888888888888888888888888888888888888888888888888888888888888888888888888888***\n\n\n";
}



































